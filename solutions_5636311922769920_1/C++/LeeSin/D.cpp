#include <cstdio>
#include <algorithm>
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, n, m, k, ans;
LL l;

void solve(int tt){
	printf("Case #%d: ", tt);
	scanf("%d %d %d", &n, &m, &k);
	m = min(n, m);
	ans = (n + m - 1) / m;
	l = 1;
	fi(i, 0, m) l *= n;
	
	if(k < ans) puts("IMPOSSIBLE");
	else{
		fi(i, 0, ans){
			LL x = 0;
			fi(j, 0, m - 1) x = x * n + ((i / 2) * m + j);
			x = x * n + ((i / 2) * m + m);
			if(i % 2) x = l - x + 1;
			printf("%I64d%c", x, i == ans - 1 ? '\n' : ' ');
		}
	}
}

int main(){
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc) solve(z);
	scanf("\n");
}
