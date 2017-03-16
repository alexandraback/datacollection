#include<iostream>
#include<vector>

using namespace std;

int single_test(int n, vector<int> & P, int max_cakes)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (P[i] + max_cakes - 1) / max_cakes - 1;
	}
	ans += max_cakes;
	// cerr << max_cakes << " " << ans << endl;
	return ans;
}

int solve()
{
	int n, i, m;
	cin >> n;
	vector<int> P(n);
	m = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> P[i];
		m = max(m, P[i]);
	}
	int ans = m;
	for (i = 1; i < m; ++i)
		ans = min(ans, single_test(n, P, i));
	return ans;
}

int main()
{
	int T,t;
	cin >> T;
	for (t = 1; t <= T; ++t)
		cout << "Case #" << t << ": " << solve() << endl;
}

