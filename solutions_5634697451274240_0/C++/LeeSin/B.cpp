#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 105
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, ans, n;
char s[N];

void solve(int tt){
	scanf("%s", s);
	n = strlen(s);
	s[n] = '+';
	s[n + 1] = 0;
	
	ans = 0;
	FD(i, n - 1, 0) if(s[i] != s[i + 1]) ans++;
	printf("Case #%d: %d\n", tt, ans);
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc) solve(z);
	scanf("\n");
}
