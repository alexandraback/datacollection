#include <cstdio>
#include <algorithm>
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t;
LL a, b;

bool is(LL x){
	LL r = x, y = 0;
	for(; r; r /= 10) y = y * 10 + r % 10;
	return x == y;
}

int odp(LL x){
	int ret = 0;
	LL c = 1;
	for(; c * c <= x; c++) if(is(c) && is(c * c)) ret++;
	return ret;
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%I64d %I64d", &a, &b);
		printf("Case #%d: %d\n", z, odp(b) - odp(a - 1));
	}
	scanf("\n");
}
