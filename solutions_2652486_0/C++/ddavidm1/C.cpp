#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;

#define SET(v,i) memset(v,i,sizeof(v));
#define FOR(i,n,k) for(int i=n;i<k;++i)
#define WHILE(i,n) while(i<n)
#define RI(i) scanf("%d",&i);
#define RS(i) scanf("%s",i);
#define RF(i) scanf("%lf",&i);
#define RL(i) scanf("%lld",&i);
#define OPEN(s) freopen(s,"r",stdin);
#define CLOSE(s) freopen(s,"w",stdout);

const int INF=0x3F3F3F3F;
const int MAXN=101;
typedef long long int i64;
typedef pair<int,int> pii;
typedef pair<string,int> psi;

int A[MAXN];

int main(){
	#ifdef DM1_MACHINE
		OPEN("FILE.in");
		CLOSE("FILE.out");
	#endif
	int t; RI(t);
	FOR(ic,1,t+1){
		int R,N,M,K; RI(R); RI(N); RI(M); RI(K);
		printf("Case #%d:\n",ic);
		FOR(i,0,R){
			SET(A,0)
			FOR(j,0,K){
				int num;
				RI(num);
				FOR(k,2,M+1){
					int c=0;
					while(num % k == 0){
						c++;
						num /= k;
					}
					A[k] = max(A[k],c);
				}
			}
			int d=0;
			FOR(i,2,M+1){
				d+=A[i];
			}
			if(d==N){
				FOR(k,2,M+1){
					while(A[k]){
						A[k]--;
						printf("%d",k);
					}
				}
			}
			else if(d<N){
				FOR(k,0,N-d)
					printf("2");
				FOR(k,2,M+1){
					while(A[k]){
						A[k]--;
						printf("%d",k);
					}
				}
			}
			else if(d>N){
				while(d>N){
					d--;
					A[2]-=2;
					A[4]+=1;
				}
				FOR(k,2,M+1){
					while(A[k]){
						A[k]--;
						printf("%d",k);
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}


////////////////////////////////////////////
/////////////Code by David Moran////////////
/////////////////////////////P=NP///////////
