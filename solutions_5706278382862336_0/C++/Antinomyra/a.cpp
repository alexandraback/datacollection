#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

long long gcd(long long x, long long y)
{
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int main()
{
	map<long long, long long> pow2;
	pow2.clear();
	for (long long i = 1; i <= 40; i++)
		pow2[1LL << i] = i;
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		long long p, q;
		char op;
		cin >> p >> op >> q;
		cout << "Case #" << test << ": ";

		long long g = gcd(p, q);
		p /= g;
		q /= g;

		long long ans = 41;
	
		if (pow2.count(q))
		{
			ans = pow2[q];
			while (p > 1)
			{
				p /= 2;
				ans--;
			}
		}
		
		if (ans > 40)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}