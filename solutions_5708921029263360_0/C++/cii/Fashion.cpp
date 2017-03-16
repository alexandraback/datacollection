#include<stdio.h>
#include<stdlib.h>

#define maxS 10

int main() {
	int test;
	scanf("%d", &test);
	for(int t=0; t<test; t++) {
		int j, p, s, k;
		scanf("%d %d %d %d", &j, &p, &s, &k);
		int nJS[maxS][maxS];
		int nJP[maxS][maxS];
		int nPS[maxS][maxS];
		int solution[maxS][maxS][maxS];
		for(int i=0; i<maxS; i++) {
			for(int j=0; j<maxS; j++) {
				nJS[i][j] = 0;
				nJP[i][j] = 0;
				nPS[i][j] = 0;
			}
		}
		int ans = 0;
		for(int nj=0; nj<j; nj++) {
			for(int np=0; np<p; np++) {
				for(int ns=0; ns<s; ns++) {
					solution[nj][np][ns] = 0;
					if((nJS[nj][ns]<k) && (nJP[nj][np]<k) && (nPS[np][ns]<k)) {
						solution[nj][np][ns] = 1;
						nJS[nj][ns] += 1;
						nJP[nj][np] += 1;
						nPS[np][ns] += 1;
						ans += 1;
					}
				}
			}
		}	
		printf("Case #%d: %d\n", t+1, ans);
		for(int nj=0; nj<j; nj++) {
			for(int np=0; np<p; np++) {
				for(int ns=0; ns<s; ns++) {
					if(solution[nj][np][ns]==1) {
						printf("%d %d %d\n", nj+1, np+1, ns+1);
					}
				}
			}
		}
	}

	return 0;
}
