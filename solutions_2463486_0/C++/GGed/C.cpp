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

int n, lo, hi;
LLD a[100000];
char s[300];

int count(int m){
	return upper_bound(a, a + n, m) - a;
}

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%lld%lld", &lo, &hi);
	printf("%d\n", count(hi) - count(lo-1));
}

int palin(LLD x){
	sprintf(s, "%lld", x);
	int l = strlen(s);
	FOR(i,0,l) if (s[i] != s[l-i-1]) return 0;
	return 1;
}

int main(){
	FOE(i,1,10000000){
		if (palin(i*1LL) && palin(i*1LL*i)) a[n++] = i * 1LL * i;//, printf("%d %lld\n", i, i*1LL*i);
	}
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
