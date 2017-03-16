#include <cstdio>
#include <algorithm>
#define LL long long
#define N 39
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, ans[N] = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002};
LL a, b;

int odp(LL x){
	int ret = 0;
	while(ret < N && (LL) ans[ret] * ans[ret] <= x) ret++;
	return ret;
}

int main(){
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%I64d %I64d", &a, &b);
		printf("Case #%d: %d\n", z, odp(b) - odp(a - 1));
	}
	scanf("\n");
}
