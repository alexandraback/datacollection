#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int tc_, n, a[25], v[25], X, Y, ok;

void dfs(int x){
	if (ok) return;
	if (X == Y && X){
		FOR(i,0,n)
		if (v[i] == 1) printf("%d ", a[i]);
		puts("");
		FOR(i,0,n)
		if (v[i] == 2) printf("%d ", a[i]);
		puts("");
		ok = 1;
		return;
	}
	if (x == n) return;
	
	FOR(i,x,n){
		X += a[i];
		v[i] = 1;
		dfs(i+1);
		v[i] = 0;
		X -= a[i];
		
		Y += a[i];
		v[i] = 2;
		dfs(i+1);
		v[i] = 0;
		Y -= a[i];
	}
}


int main(){
	scanf("%d", &tc_);
	FOE(tc,1,tc_){
		scanf("%d", &n);
		FOR(i,0,n) scanf("%d", &a[i]);
		random_shuffle(a, a + n);
		
		printf("Case #%d:\n", tc);
		X = Y = ok = 0;
		CLR(v, 0);
		dfs(0);
		if (!ok) puts("Impossible");
		
	}
	return 0;
}
