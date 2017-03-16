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
		
		int J, P, S, K;	scanf("%d%d%d%d", &J, &P, &S, &K);
		
		int JJ[16], PP[16], SS[16];
		for(int i = 0; i < 16; ++i)
			JJ[i] = 0, PP[i] = 0, SS[i] = 0;
		
		int com[3];
		
		for(int i = 1; i <= J; ++i) {
			com[0] = i;
			
			for(int j = 1; j <= P; ++j) {
				if(PP[j] == K)	continue;
				com[1] = j;
				++PP[j];
				for(int k = 1; k <= S; ++k) {
					if(SS[j] == K)	continue;
					com[2] = k;
					++SS[j];
					printf("%d %d %d\n", com[0], com[1], com[2]);
				}
			}
			
			for(int i = 0; i < 16; ++i)
			JJ[i] = 0, PP[i] = 0, SS[i] = 0;
		}
	}
	return 0;
}
