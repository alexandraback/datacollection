/*
 * Author: 67h2gak
 * PROG: C
 * DATE: 2013.4.13
*/
#include <cstdio>

using namespace std;

typedef long long LL;

const int maxn = 500005;

LL num[maxn], A, B;
int ns, ret;

void init()
{
	scanf("%lld%lld", &A, &B);
}

int dit[17];

bool test(LL x)
{
	int len = 0;
	while (x){
		dit[len ++] = x % 10; x /= 10;
	}
	for (int i = 0; i < len; i ++)
		if (dit[i] != dit[len - 1 - i]) return 0;
	return 1;
}

void Init()
{
	ns = 0;
	for (int i = 1; i <= 10000000; i ++) if (test(i)){
		LL x = (LL)i * i;
		if (test(x)) num[++ ns] = x;
	}
}

int Solve(LL x)
{
	if (x <= 0) return 0;
	if (x >= num[ns]) return ns;
	int l = 1, r = ns;
	while (l < r){
		int mid = (l + r + 1) >> 1;
		if (num[mid] <= x) l = mid;
			else r = mid - 1;
	}
	return r;
}

void work()
{
	ret = Solve(B) - Solve(A - 1);
}

void print()
{
	printf("%d\n", ret);
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	Init();
	int T, t = 0;
	scanf("%d", &T);
	while (T --){
		init();
		work();
		printf("Case #%d: ", ++ t);
		print();
	}
	return 0;
}
