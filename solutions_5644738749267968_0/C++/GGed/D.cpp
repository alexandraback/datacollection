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

int n, ret;
double a[1005], b[1005];

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%d", &n);
	FOR(i,0,n) scanf("%lf", &a[i]);
	FOR(i,0,n) scanf("%lf", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	
	ret = 0;
	FOE(i,0,n){
		int ok = 1, off = n - i;
		FOR(j,0,i) if (b[j] > a[j + off]) ok = 0;
		if (ok) ret = i;
	}
	printf("%d ", ret);
	
	ret = 0;
	FOE(i,0,n){
		int ok = 1, off = n - i;
		FOR(j,0,i) if (a[j] > b[j + off]) ok = 0;
		if (ok) ret = i;
	}
	printf("%d\n", n - ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
