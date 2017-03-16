#include <stdio.h>
#include <stdlib.h>

//#define DBG_PRINT

#ifdef DBG_PRINT
#define DbgPrintf(...) printf(__VA_ARGS__)
#else
#define DbgPrintf(...)
#endif

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int T;
	int N;
	int R, C, W;
	int i, j;
	int t1, t2;
	int ans;

	//DbgPrintf("MAX: %lld \n", LLONG_MAX);

	scanf("%d", &T);
	DbgPrintf("T: %d \n\n", T);

	for( i = 1 ; i <= T ; i++ ) {
		scanf("%d %d %d", &R, &C, &W);
		DbgPrintf("%d %d %d \n", R, C, W);

		t1 = C / W;
		DbgPrintf("t1: %d\n", t1);
		t2 = t1 * (R-1);
		DbgPrintf("t2: %d\n", t2);

		if( C % W == 0 ) {
			ans = t2 + t1 + W - 1;
		}
		else 
		{
			ans = t2 + t1 + W;
		}

		printf("Case #%d: %d\n", i, ans);
		DbgPrintf("\n");

	}

	return 0;
}
