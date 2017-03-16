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

int n, a[1005];

void solve(int tc){
	scanf("%d", &n);
	FOR(i,0,n) scanf("%d", &a[i]);
	int ret = 1000;

	FOE(i,1,1000){
		int s = 0;
		FOR(j,0,n) s += (a[j] - 1) / i;
		ret = min(ret, s + i);
	}
	
	printf("Case #%d: %d\n", tc, ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
