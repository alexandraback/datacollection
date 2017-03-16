/*------------------------------------------------------------------------------
 * Filename    :  A.cpp
 * Author      :  ferruh
 * Description : 
 *
 * Date        :  Apr 13 2012 18:47:25
 *
 *----------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#include "A.h"
#include <stdio.h>
#include <string.h>

/* Private Types -------------------------------------------------------------*/
enum {
    START = 'a',
    NEWLINE = '\n',
    END_OF_STR = 0,
    SPACE = ' ',
    STOP = 'z',
    LAST
};

/* Defines -------------------------------------------------------------------*/


#define SMALL_MAX_G 100 + 1
#define LARGE_MAX_G 0

#define SMALL 1

#if (SMALL == 1)
#define MAX_G SMALL_MAX_G
#else
#define MAX_G LARGE_MAX_G
#endif

#define SAMPLE_LENGTH 3
#define MAX_CHAR_COUNT 26
/* Function Declarations -----------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/

char encoded[SAMPLE_LENGTH][MAX_G] = {{"ejp mysljylc kd kxveddknmc re jsicpdrysi"},
        {"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"},
        {"de kr kd eoya kw aej tysr re ujdr lkgc jv"},
};

char decoded[SAMPLE_LENGTH][MAX_G] = {{"our language is impossible to understand"},
        {"there are twenty six factorial possibilities"},
        {"so it is okay if you want to just give up"},
};

/* from encoded to decoded */
char mapping[MAX_CHAR_COUNT];

#if (DEBUG == 1)
/*------------------------------------------------------------------------------
 * Function    :  
 * Description : 
 *
 * Params      : 
 * Returns     : 
 *----------------------------------------------------------------------------*/
static void check_missing_mapping(void)
{
    int i;

    for(i = 0; i < MAX_CHAR_COUNT; i++) {
        if (mapping[i] == END_OF_STR) {
            printf("Missing %d(%c) \n", i, mapping[i]);
        }
    }
}

/*------------------------------------------------------------------------------
 * Function    :
 * Description :
 *
 * Params      :
 * Returns     :
 *----------------------------------------------------------------------------*/
static void print_mapping(void)
{
    int i;

    for(i = 0; i < MAX_CHAR_COUNT; i++) {
        printf("%d -> %d\n", i, (int)mapping[i]);
    }
}
#endif

/*------------------------------------------------------------------------------
 * Function    :  
 * Description : 
 *
 * Params      : 
 * Returns     : 
 *----------------------------------------------------------------------------*/
static void solve_from_sample(void)
{
    int i, j;
    char c_encoded, c_decoded;
#if (DEBUG == 1)
    char c_mapped;
#endif

    /*  'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'. */
    mapping['y'- START] = 'a';
    mapping['e'- START] = 'o';
    mapping['q'- START] = 'z';

    /* Learned from first failure */
    mapping['z'- START] = 'q';

    for (i = 0; i < SAMPLE_LENGTH; i++) {
        j = 0;
        while (1) {
            c_encoded = encoded[i][j];
            if ((c_encoded == NEWLINE) || (c_encoded == END_OF_STR)) break;
            c_decoded = decoded[i][j];

#if (DEBUG == 1)
            c_mapped = mapping[c_encoded - START];
            if ((c_mapped != END_OF_STR) && (c_mapped != c_decoded)) {
                printf ("THERE IS SOMETHING WRONG %d != %d\n", c_mapped, c_decoded);
            }
#endif

            mapping[c_encoded - START] = c_decoded;
            j++;
        }
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
	char c;

	for (i = 0; i < MAX_CHAR_COUNT; i++) mapping[i] = END_OF_STR;

	solve_from_sample();

	scanf("%d\n", &T);

#if (DEBUG == 1)
	check_missing_mapping();
	print_mapping();
#endif

	for (i = 0; i < T; i++) {
	    j = 0;
		printf("Case #%d: ", i+1);
	    while (1) {
	        scanf("%c", &c);
	        if (c != NEWLINE) {
	            printf("%c", mapping[c - START]);
	        } else {
	            printf("\n");
	            break;
	        }
	    };
	}
	return 0;
}


/* end of A.cpp */
