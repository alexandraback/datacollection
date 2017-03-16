#include <cstdio>
#include <algorithm>
#define N 40
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, n, m;
char s[N];

void go(int x, int y){
	if(!m) return;
	if(x == n - 1){
		if(y) return;
		printf("%s", s);
		FI(i, 2, 10) printf(" %d", i + 1);
		puts("");
		m--;
		return;
	}
	
	s[x] = '0';
	go(x + 1, y);
	s[x] = '1';
	go(x + 1, x % 2 ? y + 1 : y - 1);
}

void solve(int tt){
	scanf("%d %d", &n, &m);
	s[0] = s[n - 1] = '1';
	s[n] = 0;
	printf("Case #%d:\n", tt);
	go(1, 0);
}

int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc) solve(z);
	scanf("\n");
}
