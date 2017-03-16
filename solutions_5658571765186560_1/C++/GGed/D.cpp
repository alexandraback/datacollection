#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int f(int n, int r, int c){
	if (n >= 7) return 1;
	if (n > r && n > c) return 1;
	int s = (n + 1) / 2;
	if (s > min(r, c)) return 1;
	if (r * c % n > 0) return 1;
	if (n == 4 && min(r, c) <= 2) return 1;
	
	if (n == 5){
		if (min(r, c) <= 3) return 1;
	}
	if (n == 6){
		if (r * c <= 18) return 1;
		if (min(r, c) <= 3) return 1;
	}
	
	
	return 0;
}

void solve(int tc){
	int R, C, n;
	scanf("%d%d%d", &n, &R, &C);
	printf("Case #%d: %s\n", tc, f(n, R, C) ? "RICHARD" : "GABRIEL");
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
