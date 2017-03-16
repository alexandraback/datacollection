#include <cstdio>
#include <algorithm>
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, n, m, k;

void solve(int tt){
	printf("Case #%d: ", tt);
	scanf("%d %d %d", &n, &m, &k);
	if(n == 1) puts("1");
	else if(m == 1){
		if(n > k) puts("IMPOSSIBLE");
		else FI(i, 1, n) printf("%d%c", i, i == n ? '\n' : ' ');
	}else{
		if(n > k + 1) puts("IMPOSSIBLE");
		else FI(i, 2, n) printf("%d%c", i, i == n ? '\n' : ' ');
	}
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc) solve(z);
	scanf("\n");
}
