#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(i=a;i<=b;i++)
#define FD(i,a, b) for(i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 100000000
#define MAXN ?
#define MAXE ?
using namespace std;
int i,j, k, N, M, K, T;
int main(){
	scanf("%d", &T);
	FI(k, 1, T){
		scanf("%d%d%d", &N, &M, &K);
		int Q = 0;
		FI(i, 0 , N - 1){
			FI(j, 0, M - 1){
				if((i & j) < K){ Q++;}
			}
			
		}
		printf("Case #%d: %d\n", k, Q);
	}
	
}
