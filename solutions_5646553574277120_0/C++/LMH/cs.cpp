#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(int i=a;i<=b;i++)
#define FD(i,a, b) for(int i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 2000000000
#define MAXN ?
#define MAXE ?
#define ll long long
using namespace std;
int n, m, k, c, d, v, coin[100], cur[100], p[100];
int check(){
	CL(p, 0);
	FI(i, 0, (1 << d) - 1){
		
		int s = 0;
		FI(j, 0, d - 1){
			if((1 << j) & i) s += coin[j];
		}
		p[s] = 1;
	}
	FI(i, 1, v){
		if(p[i] == 0) return i; 
	}
	return INF; 
}
int solve(){
	int u = 0;
	FI(i, 1, 30){
		int mpos = check();
		if(mpos == INF) return u;
		coin[d++] = mpos;
		u++;
	}
}
int main(){
	int K;
	scanf("%d", &K);
	FI(k, 1, K){
		scanf("%d%d%d", &c, &d, &v);
		FI(i, 0, d - 1) scanf("%d", &coin[i]);
		int ans = solve();
		printf("Case #%d: %d\n", k, ans);
	}
}
