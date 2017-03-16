#include <cstdio>
#include <set>
#include <cmath>
using namespace std;
set <long long> p;
bool check(long long n)
{
	long long a[20], len = 0;
	while(n)
	{
		a[len ++] = n % 10;
		n /= 10;
	}
	for(int i = 0; i < (len >> 1); i ++)
		if(a[i] != a[len - i - 1]) return false;
	return true;
}
void init()
{
	for(int i = 1; i <= 10000000; i ++)
		if(check(i)) p.insert(i);
}
void work()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	long long s = (long long)ceil(sqrt(a));
	long long t = (long long)floor(sqrt(b));
	long long ans = 0;
	for(long long i = s; i <= t; i ++)
		if(p.find(i) != p.end() && check(i * i)) ans ++;
	printf("%lld\n", ans);
}
int main()
{
	init();
	freopen("in", "r", stdin);
	freopen("out1", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int i = 1; i <= _; i ++)
		printf("Case #%d: ", i), work();
	return 0;
}
