#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int A, B, K;
long long f[35][8];

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	int tw[35];
	tw[0] = 1;
	for (int i=1; i<32; i++) tw[i] = tw[i-1] << 1;
	
	int T;
	scanf("%d", &T);
	for (int times=1; times<=T; times++) {
		printf("Case #%d: ", times);
		
		scanf("%d%d%d", &A, &B, &K);
		memset(f, 0, sizeof(f));
		f[32][7] = 1;
		for (int i=32; i>0; i--)
			for (int j=0; j<8; j++)
				if (f[i][j]) {
					for (int na=0; na<2; na++)
						for (int nb=0; nb<2; nb++) {
							if ((j&4)>0 && ((A & tw[i-1])==0) && na==1 ) continue;
							if ((j&2)>0 && ((B & tw[i-1])==0) && nb==1 ) continue;
							if ((j&1)>0 && ((K & tw[i-1])==0) && nb==1 && na == 1) continue;
							int ansa, ansb, ansk;
							if ((j&4) && (na == ((A & tw[i-1]) >> (i-1)))) ansa = 4;
							else ansa = 0;
							if ((j&2) && (nb == ((B & tw[i-1]) >> (i-1)))) ansb = 2;
							else ansb = 0;
							if ((j&1) && ((na & nb) == ((K & tw[i-1]) >> (i-1)))) ansk = 1;
							else ansk = 0;
							
							f[i-1][ansa+ansb+ansk] += f[i][j];
						}
				}
		printf("%I64d\n", f[0][0]);
	}
	return 0;
}

