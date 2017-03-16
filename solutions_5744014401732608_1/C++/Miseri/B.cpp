#include <bits/stdc++.h>

using namespace std;
// Constants and macros
#define INF 		(int)1e9
#define EPS 		1e-9
#define bitcount 	__builtin_popcount
#define gcd 		__gcd
#define forall(i,a,b) 	for(int i=a;i<b;i++)
#define pb 		push_back
#define mp		make_pair
#define MAX(a,b)	( (a)>(b) ? (a):(b))
#define MIN(a,b)	( (a)<(b) ? (a):(b))
#define s(a)		scanf("%d", &a)
#define ss(a,b)		scanf("%d %d", &a,&b)
#define sss(a,b,c)	scanf("%d %d %d", &a,&b,&c)
#define sl(a)		scanf("%lld", &a)

int T;
long long  B, M;

bool g[64][64];

void findgrid(){
	memset(g,0,sizeof g);
	forall(i,0,B) {
		forall(j,i+1,B){
			g[i][j] = 1;
		}
	}
	if (1<<(B-2) == M) return;
	g[0][B-1] = 0;
	forall(j,0,B-2){
		g[0][B-j-2] = (M>>j)&1;
	}
}

int main(){
	s(T);
	forall(i,0,T){
		sl(B);
		sl(M);
		printf("Case #%d: ", i+1);
		if ((1<<(B-2)) < M) printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			findgrid();
			forall(ii,0,B){
				forall(jj,0,B){
					printf("%d", g[ii][jj]);
				}
				printf("\n");
			}
		}
	}
}
