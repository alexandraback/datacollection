#include <cstdio>
#include <algorithm>
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, x, n, m;

int main(){
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w+", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d %d %d", &x, &n, &m);
		if(n < m) swap(n, m);
		printf("Case #%d: ", z);
		if(m < (x / 2 + 1) || n < x || n * m % x) puts("RICHARD");
		else puts("GABRIEL");
	}
	scanf("\n");
}
