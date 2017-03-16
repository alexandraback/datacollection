#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		long long p, q, d;
		char ch;
		cin >> p >> ch >> q;
		d = gcd(p, q);
		p /= d, q /= d;
		int ans = 0;
		printf("Case #%d: ", t);
		for (ans = 0; ans <= 40; ans++)
		{
			if ((1ll << ans) == q) break;
		}
		if (ans > 40) puts("impossible");
		else{
			ans = 0;
			for (;;q/=2,ans++)
			{
				if (p * 2 >= q) break;
			}
			cout << ans + 1 << endl;
		}
	}
}
