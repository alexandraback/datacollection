/*------------------------------------------------------------------------------
 * Filename    :  C.cpp
 * Author      :  ferruh
 * Description : 
 *
 * Date        :  Apr 13 2012 18:47:25
 *
 *----------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "C.h"
#include <stdio.h>
#include <string.h>

/* Private Types -------------------------------------------------------------*/

/* Defines -------------------------------------------------------------------*/


#define SMALL_MAX_AB 1000
#define SMALL_MAX_AB_STR 4

#define LARGE_MAX_AB 2000000
#define LARGE_MAX_AB_STR 7

#define SMALL 0

#if (SMALL == 1)
#define MAX_AB SMALL_MAX_AB
#define MAX_AB_STR SMALL_MAX_AB_STR
#else
#define MAX_AB LARGE_MAX_AB
#define MAX_AB_STR LARGE_MAX_AB_STR
#endif
/* Function Declarations -----------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/
char str_A[MAX_AB_STR];
int digits[MAX_AB_STR];
unsigned long int found = 0;

/*------------------------------------------------------------------------------
 * Function    :  
 * Description : 
 *
 * Params      : 
 * Returns     : 
 *----------------------------------------------------------------------------*/
static int swap(int num, int str_len)
{
    /*
    int digit = num - (num / 10) * 10;
    num = num / 10;
    for (str_len--; str_len > 0; str_len--) digit *= 10;
    num += digit;
	return num;
	*/
    int i;
    int number = 0;
    int digit = digits[0];
    for (i = 0; i < str_len - 1; i++) {
        digits[i] = digits[i+1];
    }
    digits[str_len - 1] = digit;
    for (str_len--; str_len >= 0; str_len--) {
        number *= 10;
        number += digits[str_len];
    }

    return number;
}

/*------------------------------------------------------------------------------
 * Function    :  
 * Description : 
 *
 * Params      : 
 * Returns     : 
 *----------------------------------------------------------------------------*/
static int get_str_len(int num)
{
    int str_len = 0;

    while (num > 0) {
        str_len++;
        num = num / 10;
    }
	
	return str_len;
}

/*------------------------------------------------------------------------------
 * Function    :
 * Description :
 *
 * Params      :
 * Returns     :
 *----------------------------------------------------------------------------*/
static int fast_check(int num, int str_len)
{
    int index = 0;
    int first_digit;
    int i;

    while (num > 0) {
        digits[index++] = num - ((num / 10) * 10);
        num = num / 10;
    }
#if (DEBUG == 1)
    printf("Num:%u, ", num);
    printf("Array[");
    for (i = 0; i < str_len - 1; i++) {
        printf("%d, ", digits[i]);
    }
    printf("%d]\n", digits[str_len - 1]);
#endif

    first_digit = digits[str_len - 1];

    for (i = 0; i < str_len - 1; i++) {
        if (digits[i] >= first_digit) return 0;
    }
    for (i = 0; i < str_len - 1; i++) {
        if (digits[i] == 0) return 0;
    }

    return 1;
}

/*------------------------------------------------------------------------------
 * Function    :
 * Description :
 *
 * Params      :
 * Returns     :
 *----------------------------------------------------------------------------*/
static void compare(int A, int B, int str_len)
{
    if (fast_check(A, str_len)) return;

    int generated_A = swap(A, str_len);
    while (generated_A != A) {
#if (DEBUG == 1)
    printf("A:%u, new A:%u\n", A, generated_A);
#endif
        if (generated_A > A) {
            if (B >= generated_A) {
                found++;
#if (DEBUG == 1)
    printf("Found:%lu\n", found);
#endif
            }
        }
        generated_A = swap(generated_A, str_len);
    }
}

/*------------------------------------------------------------------------------
 * Function    :  main 
 * Description :  main function 
 *
 * Params      :  int argc, char *argv[] 
 * Returns     :  int 
 *----------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
	int T;
	int i, j;
	int A, B;
	int str_len;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
	    scanf("%d %d", &A, &B);
        found = 0;
        str_len = get_str_len(A);
	    for (j = A; j < B; j++) {
#if (DEBUG == 1)
    printf("Compare: A:%u B:%u Len:%d\n", j, B, str_len);
#endif
	        compare(j, B, str_len);
	    }
		printf("Case #%d: %lu\n", i+1, found);
	}
	return 0;
}

/* end of C.cpp */
