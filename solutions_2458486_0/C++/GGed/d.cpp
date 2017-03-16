#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 405
using namespace std;

int n, m, K;
int a[N], b[N], c[N], d[N][N];
int init[N];
char dp[1<<20], v[N];

int func(int mask){
	if (mask == (1<<n) - 1) return dp[mask] = 1;
	if (dp[mask] != -1) return dp[mask];
	short have[K];
	FOR(i,0,K) have[i] = init[i];
	FOR(i,0,n) if (mask & (1<<i)){
		--have[b[i]];
		FOR(j,0,c[i]) ++have[d[i][j]];
	}
	FOR(i,0,n) if (!(mask & (1<<i))){
		if (have[b[i]] && func(mask | (1<<i))) return dp[mask] = 1;
	}
	return dp[mask] = 0;
}

void solve(int tc){
	printf("Case #%d:", tc);
	scanf("%d%d", &m, &n);
	CLR(dp, -1);
	CLR(v, -1);
	
	FOR(i,0,m) scanf("%d", &a[i]), v[a[i]] = 1;
	FOR(i,0,n){
		scanf("%d%d", &b[i], &c[i]);
		FOR(j,0,c[i]) scanf("%d", &d[i][j]), v[d[i][j]] = 1;
	}
	
	K = 0;
	FOR(i,1,401) if (v[i] != -1) v[i] = K++;
	
	CLR(init, 0);
	FOR(i,0,m) ++init[v[a[i]]];
	FOR(i,0,n){
		b[i] = v[b[i]];
		FOR(j,0,c[i]) d[i][j] = v[d[i][j]];
	}
	
	if (!func(0)) puts(" IMPOSSIBLE");
	else{
		CLR(v, 0);
		int mask = 0;
		FOR(i,0,n){
			FOR(j,0,n) if (!v[j] && func(mask + (1<<j)) && init[b[j]]){
				v[j] = 1;
				mask += 1<<j;
				--init[b[j]];
				FOR(k,0,c[j]) ++init[d[j][k]];
				printf(" %d", j + 1);
				break;
			}
		}
		puts("");
	}
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
