#include <cstdio>
#include <algorithm>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, s[N], l[N], ans;
double a[N], b[N];

int f(int x, int s[]){
	return x == s[x] ? x : s[x] = f(s[x], s);
}

void solve(){
	scanf("%d", &n);
	FI(i, 1, n) scanf("%lf", &a[i]);
	FI(i, 1, n) scanf("%lf", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	
	ans = 0;
	FI(i, 0, n + 1) s[i] = l[i] = i;
	FI(i, 1, n){
		int j = lower_bound(b + 1, b + n + 1, a[i]) - b, use;
		if(f(j, l) > n){
			ans++;
			use = f(1, l);
			l[use] = f(use + 1, l);
			s[use] = f(use - 1, s);
		}else{
			use = f(j, l);
			l[use] = f(use + 1, l);
			s[use] = f(use - 1, s);
		}
	}
	
	int l = 0, h = n;
	while(l < h){
		int m = l + h + 1 >> 1;
		bool ok = 1;
		FI(i, 1, m) if(b[i] > a[n - m + i]) ok = 0;
		if(ok) l = m;
		else h = m - 1;
	}
	
	printf("%d %d\n", l, ans);
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
