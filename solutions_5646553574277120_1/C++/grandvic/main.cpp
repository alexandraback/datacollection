#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iterator>

using namespace std;

void solve()
{
	int c, d;
	long long v; cin >> c >> d >> v;
	vector<long long> a(d);
	for (int i = 0; i < d; ++i) cin >> a[i];
	long long sum = 0;
	int coini = 0, additional = 0;
	while (sum < v)
	{
		if ((coini < a.size()) && (a[coini] <= sum + 1))
		{
			sum += a[coini] * c;
			++coini;
		}
		else
		{
			sum += (sum + 1) * c;
			++additional;
		}
	}
	cout << additional << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("d:/input.txt", "rt", stdin);
	int T; std::cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}

	return 0;
}