#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		long long p, q;
		scanf("%lld/%lld", &p, &q);
		cerr << p << q << endl;
		long long g = __gcd(p, q);
		p /= g, q /= g;
		long long qq = 1;
		while (qq * 2 <= q) qq *= 2;
		cerr << qq << " " << q;
		if (qq != q)
		{
			cout << "impossible\n";
			continue;
		} 
		int ans = 1;
		while (p * 2 < q) p *= 2, ans++;
		cout << ans << "\n";
	}
}