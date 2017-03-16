#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	if (a < b)
		swap(a, b);
	while (b > 0)	
	{
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int n;
ll a, b;
char t;

int main()
{
	cin >> n;
	for (int q = 0; q < n; q++)
	{
		cin >> a >> t >> b;
		ll qq = gcd(a, b);
		a /= qq;
		b /= qq;
		ll b1 = b;
		while (b1 % 2 == 0)
			b1 /= 2;
		if (b1 != 1)
		{
			cout << "Case #" << q + 1 << ": impossible" << endl;
			continue;
		}
		int ans = 0;
		while (a < b)
		{
			b /= 2;
			ans++;
		}
		cout << "Case #" << q + 1 << ": " << max(1, ans) << endl;
	}
	cout << endl;
}
