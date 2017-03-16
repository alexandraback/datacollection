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

int main( )
{
  int num; // num of case
	unsigned int point;
//	fgets(line, L, stdin);
//	sscanf(line, "%d", &num);
	scanf("%d", &num);

	int i, j;
	int n, s, p, x;
	for( i = 0 ; i < num; i++){
//		fgets(line, L, stdin);
//		sscanf(line, "%d %d %d", &n, &s, &p);
		scanf("%d %d %d", &n, &s, &p);
		int count = 0;
		int temp_count = 0;
		for( j = 0; j < n; j++){
//			sscanf(line, "%d", &x);
			scanf("%d", &x);
			int a;
			a = x / 3;
//	 printf(HERE "x=%d, a=%d\n", x, a);
			if ( (x-3*a) == 0) {
				if ( a >= p ) {
					count++;
				} else if ((a+1 == p) && (a > 0)) {
					temp_count++;
				}
			} else if ( (x-3*a) == 1) {
				if ( a+1 >= p ) {
					count++;
				}
			} else if ( (x-3*a) == 2) {
				if (a+1 >= p) {
					count++;
				} else if (a+2 == p) {
					temp_count++;
				}
			}
		}
		if ( temp_count > s){
			count += s;
		}	else {
			count += temp_count;
		}
		if (count > n) count = n;
		printf("Case #%d: %d\n", i + 1, count);
	}
  exit(EXIT_SUCCESS);
}