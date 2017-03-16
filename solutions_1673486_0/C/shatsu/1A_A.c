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
char *cp[L];

double prob[100000]; // Šú‘Ò’l

int main( )
{
  int num; // num of case
	scanf("%d", &num);

	int i, j;
	int a,b;
	for( i = 0 ; i < num; i++){
		scanf("%d %d", &a, &b);
		double temp,p, x, y, min_stroke;
		prob[0] = b + 2.0; // ‚·‚®‚Éenter
		p = 1;
		min_stroke = prob[0];
		for( j = 0; j < a; j++){
			scanf("%lf", &temp);
			p = p * temp;
			x = a + b - 2.0 * ((double)j + 1.0) + 1.0;
			y = x + b + 1.0;
			prob[j+1] = p * x + (1.0 - p) * y;
			if (min_stroke > prob[j+1] ){
				min_stroke = prob[j+1];
			}
		}
		printf("Case #%d: %.6lf\n", i + 1, min_stroke);
	}
  exit(EXIT_SUCCESS);
}