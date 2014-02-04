
#include <stdio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>
#include "stm32f4xx_usart.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"

#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"

#include "stm32f4xx_spi.h"
#include "stm32f4xx_i2c.h"

//#include "SST25VFxx.h"
//#include "hw_SST25VFxx.h"


#include "my_defines.h"
#include "my_usart.h"
#include "my_BarkodReader.h"

#include "my_ads1230.h"
//#include "my_adc.h"

#include"W5100_Temp.h"

#include"24C32_E2PROM.h"




//***********************  STRUCTURES  ****************************
GPIO_InitTypeDef  GPIO_InitStructure;

GPIO_InitTypeDef  GPIOA_InitStructure;
GPIO_InitTypeDef  GPIOB_InitStructure;
GPIO_InitTypeDef  GPIOC_InitStructure;
GPIO_InitTypeDef  GPIOD_InitStructure;

GPIO_InitTypeDef  My_GPIO_InitStructure;
USART_InitTypeDef My_USART_InitStructure;
NVIC_InitTypeDef  My_NVIC_InitStructure;

GPIO_InitTypeDef  My_GPIO_InitStructure_B1;

SPI_InitTypeDef  	SPI1_InitStructure;

//***********************  DEFINES  ****************************
#define 		ads_clock_high		GPIO_SetBits(GPIOB, GPIO_Pin_1);
#define 		ads_clock_low		GPIO_ResetBits(GPIOB, GPIO_Pin_1);

//#define 		DEBUG_YAZDIR
#define 		Debug_ads_yazdir


#define 		Usart1_RX_Buf_Maks_Data_Len		512


#define 		LED_R_H		GPIO_SetBits(GPIOB, GPIO_Pin_3 );
#define 		LED_R_L		GPIO_ResetBits(GPIOB, GPIO_Pin_3 );
#define 		LED_R_T		GPIO_ToggleBits(GPIOB, GPIO_Pin_3 );

#define 		LED_G_H		GPIO_SetBits(GPIOB, GPIO_Pin_4 );
#define 		LED_G_L		GPIO_ResetBits(GPIOB, GPIO_Pin_4 );
#define 		LED_G_T		GPIO_ToggleBits(GPIOB, GPIO_Pin_4 );

#define 		LED_B_H		GPIO_SetBits(GPIOB, GPIO_Pin_5 );
#define 		LED_B_L		GPIO_ResetBits(GPIOB, GPIO_Pin_5 );
#define 		LED_B_T		GPIO_ToggleBits(GPIOB, GPIO_Pin_5 );

#define 		LED_ALL_L		GPIO_ResetBits(GPIOB, GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5  );
#define 		LED_ALL_H		GPIO_SetBits(GPIOB, GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5  );



//+++++++++++++++++  Delay Basi  +++++++++++++++++++++++
void Delay(__IO uint32_t nCount) {
  while(nCount--) {
  }
}
//-----------------  Delay Sonu  -----------------------






