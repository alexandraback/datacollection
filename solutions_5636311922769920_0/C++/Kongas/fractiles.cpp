
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t){
		ll k, pow, st;
		cin >> k >> pow >> st;
		if (k > pow * st){
			cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
			continue;
		}

		ll p, mul, x = 0;
		cout << "Case #" << t + 1 << ":";
		while (x < k){
			ll sum = 0;
			for (p = 0, mul = 1; p < pow; ++p, mul *= k){
				sum += mul * x;
				++x;
				if (x >= k)
					break;
			}
			cout << " " << sum + 1;
		}
		cout << endl;
	}
	return 0;
}
