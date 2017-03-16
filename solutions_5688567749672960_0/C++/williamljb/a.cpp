#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
using namespace std;

long long doit(long long n)
{
	if (n < 10)
		return n;
	if (n % 10 == 0)
		return doit(n-1)+1;
	long long k = 1, k0 = 1;
	int num = 1;
	while (k * 10 <= n)
	{
		k *= 10;
		++num;
	}
	long long ans = doit(k-1);
	int flag = 0;
	//cout << ":" << n << " " << num << endl;
	for (int i = 0; i <= num-i-1; ++i)
	{
		long long cnt;
		if (i == num-i-1)
			cnt = (n/k%10) * k0;
		else
		{
			cnt = ((n / k%10) + (n / k0) % 10) * k0;
			if (!(n / k%10 == 0 || (n / k%10 == 1 && k0 == 1)))
				flag = 1;
		}
		ans += cnt;
		//cout << " " << cnt << endl;
		k /= 10;
		k0 *= 10;
	}
	return ans+flag;
}

void solve()
{
	long long n;
	cin >> n;
	cout << doit(n) << endl;
}

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("a.out", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}