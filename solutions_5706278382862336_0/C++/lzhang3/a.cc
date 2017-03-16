#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <climits>

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

long long gcd(const long long &a, const long long &b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve()
{
		long long p, q, t; scanf("%lld/%lld", &p, &q);
		t = gcd(p, q); p /= t; q /= t;
		t = q;
		while (t % 2 == 0)
			t >>= 1;
		if (t != 1) {
			cout << "impossible" << endl;
			return;
		}
		long long n = 0;
		t = q;
		while (t > p) {
			t >>= 1;
			++n;
		}
		cout << n << endl;
}

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}







