#include <stdio.h>
#include <stdlib.h>  // malloc, atof, etc
#include <inttypes.h> // int64
#include <stdbool.h> // bool
#include <string.h>

#define _STR(x)      #x
#define _STR2(x)     _STR(x)
#define __SLINE__    _STR2(__LINE__)
#define HERE         __FILE__ "(" __SLINE__ ")"
// usage: printf(HERE "x=%d\n", x);

#define _PFP(str) printf("%s\n", str)
#define ASIZEOF(array) (sizeof(array) / sizeof(array[0]))
#define FOR(i, j) for(((i) = 0); ((i) < (j)); ((i)++))
#define ISR(str) str, #str

#define L 1001

char line[L];
char *cp1;
char cp2[26] ="yhesocvxduiglbkrztnwjpfmaq";

int main( )
{
  int num; // num of case
	unsigned int point;
	fgets(line, L, stdin);
	sscanf(line, "%d", &num);

	unsigned int i,j;

	for( i = 0 ; i < num; i++){
		fgets(line, L, stdin);
		cp1 = &(line[0]);
		printf("Case #%d: ", i + 1);  // space is added after next printf
		while ( (*cp1 != '\0') && (*cp1 != '\n') ) {
			if(*cp1 == ' '){
				printf(" ");
			} else {
				printf("%c", cp2[(*cp1)-'a'] );
			}
			cp1++;
		}
		printf("\n");
	}
  exit(EXIT_SUCCESS);
}