#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		printf("Case #%d: ", t + 1);
		int B, M;	scanf("%d%d", &B, &M);
		if(M <= (1 << B - 2)) {
			puts("POSSIBLE");
			
			for(int i = 0; i < B; ++i) {
				for(int j = 0; j < i + 1; ++j)		// notice 1 here
					putchar('0');
				for(int j = i + 1; j < B - 1; ++j)
					putchar('1');
				
				if(i == 0) {
					if(M == (1 << B - 2)) {
						putchar('1');
					} else {
						putchar('0');
					}
				}
				
				if(0 < i && i < B - 1) {
					int ch;
					if(M == (1 << B - 2))
						ch = (M - 1 >> (i - 1)) & 1;
					else
						ch = (M >> (i - 1)) & 1;
					printf("%d", ch);
				}
				
				puts("");
			}
		} else {
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}
