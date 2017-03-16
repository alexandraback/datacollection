#include <cstdio>
#include <algorithm>
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n;

void solve(int tc){
	scanf("%d", &n);
	if(!n){
		printf("Case #%d: INSOMNIA\n", tc);
		return;
	}
	
	int u = 0, x = n;
	do{
		for(int y = x; y; y /= 10) u |= 1 << y % 10;
		x += n;
	}while(u != (1 << 10) - 1);
	
	printf("Case #%d: %I64d\n", tc, x - n);
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t) solve(z);
	scanf("\n");
}
