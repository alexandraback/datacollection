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

int n, a[1000005];
int ret, cur, sz;

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%d%d", &sz, &n);
	FOR(i,0,n) scanf("%d", &a[i]);
	if (sz == 1){
		printf("%d\n", n);
		return;
	}
	sort(a, a + n);
	ret = n;
	cur = 0;
	FOR(i,0,n){
		ret = min(ret, cur + n - i);
		while (sz <= a[i]){
			++cur;
			sz += sz - 1;
		}
		sz += a[i];
	}
	ret = min(ret, cur);
	printf("%d\n", ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
