/*------------------------------------------------------------------------------
 * Filename    :  B.cpp
 * Author      :  ferruh
 * Description : 
 *
 * Date        :  Apr 13 2012 18:47:25
 *
 *----------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "B.h"
#include <stdio.h>
#include <string.h>

/* Private Types -------------------------------------------------------------*/

/* Defines -------------------------------------------------------------------*/


#define SMALL_MAX_N 3
#define LARGE_MAX_N 100

#define SMALL 0

#if (SMALL == 1)
#define MAX_N SMALL_MAX_N
#else
#define MAX_N LARGE_MAX_N
#endif
/* Function Declarations -----------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/
static int scores[MAX_N];

/*------------------------------------------------------------------------------
 * Function    :
 * Description :
 *
 * Params      :
 * Returns     :
 *----------------------------------------------------------------------------*/
static int isOdd(int score)
{
    if (score & 0x1) {
        return 1;
    }

	return 0;
}

#if (DEBUG == 1)
/*------------------------------------------------------------------------------
 * Function    :  
 * Description : 
 *
 * Params      : 
 * Returns     : 
 *----------------------------------------------------------------------------*/
static void print_scores(int N)
{
	int i;
	
    printf("[");
	for (i = 0; i < N - 1; i++) {
	    printf("%d,", scores[i]);
	}
    printf("%d]\n", scores[i]);
}
#endif

/*------------------------------------------------------------------------------
 * Function    :  main 
 * Description :  main function 
 *
 * Params      :  int argc, char *argv[] 
 * Returns     :  int 
 *----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int T;
	int i, j;
	int N, S, p;
	int best_score, worst_score, middle_score;
	int max_available_best_score;
	int n;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
	    scanf("%d %d %d ", &N, &S, &p);
	    for (j = 0; j < N; j++) {
	        scanf("%d", &scores[j]);
	    }
#if (DEBUG == 1)
	    print_scores(N);
#endif
	    max_available_best_score = 0;

        for (j = 0; j < N; j++) {
            if (scores[j] == 0) {
                best_score = 0;
                middle_score = 0;
                worst_score = 0;
            } else if (scores[j] == 30) {
                best_score = 10;
                middle_score = 10;
                worst_score = 10;
            } else if (scores[j] == 29) {
                best_score = 10;
                middle_score = 10;
                worst_score = 9;
            } else if ((scores[j] - (scores[j] / 3) * 3) == 0) {
                n = scores[j] / 3;
                best_score = n + 1;
                middle_score = n;
                worst_score = n - 1;
            } else if (isOdd(scores[j]) ^ isOdd(scores[j]/3)) {
                /* n + n + (n+1) = 3n +1 */
                n = (scores[j] - 1) / 3;
                best_score = n + 1;
                middle_score = n + 1;
                worst_score = n;
            } else {
                /* n + n + (n+2) = 3n + 2 */
                n = (scores[j] - 2) / 3;
                best_score = n + 2;
                middle_score = n + 1;
                worst_score = n;
            }
#if (DEBUG == 1)
        printf("Worst:%d, Best:%d, Middle:%d, p:%d, S:%d\n", worst_score, best_score, middle_score, p, S);
#endif
            if (worst_score >= p) {
                max_available_best_score++;
            } else if (middle_score >= p) {
                max_available_best_score++;
            } else if (best_score >= p) {
                if (S > 0) {
                    max_available_best_score++;
                    S--;
                }
            }
        }

		printf("Case #%d: %u\n", i+1, max_available_best_score);
	}
	return 0;
}


/* end of B.cpp */
