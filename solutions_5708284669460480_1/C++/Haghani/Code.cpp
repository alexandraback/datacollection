#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 105;
double p[MAX], dp[MAX][MAX];
int cnt[MAX][MAX];
int next[MAX][MAX];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		for (int i = 0; i < MAX; i++)
			p[i] = 0.0;
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
			{
				dp[i][j] = 0.0;
				next[i][j] = 0;
				cnt[i][j] = -1e9;
			}
		int l, m, n;
		cin >> l >> m >> n;
		for (int i = 0; i < l; i++)
		{
			char c;
			cin >> c;
			p[c - 'A'] += 1.0;
		}
		string s;
		cin >> s;
		bool valid = true;
		for (int i = 0; i < m; i++)
			if (p[s[i] - 'A'] < 0.5)
			{
				valid = false;
				break;
			}
		if (!valid)
		{
			cout << "Case #" << _ << ": 0.000000000\n";
			continue;
		}
		for (int i = 0; i < MAX; i++)
			p[i] /= l;
		for (int i = 0; i <= m; i++)
			for (char c = 'A'; c <= 'Z'; c++)
				for (int k = min(m, i + 1); k > 0; k--)
					if (s.substr(i - k + 1, k - 1) == s.substr(0, k - 1) && s[k - 1] == c)
					{
						next[i][c - 'A'] = k;
						break;
					}
		dp[0][0] = 1.0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= m; j++)
				for (int c = 0; c < 26; c++)
					dp[i + 1][next[j][c]] += dp[i][j] *p[c];
		cnt[0][0] = 0;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
			{
				if (j == m)
					cnt[i][j]++;
				for (int c = 0; c < 26; c++)
					cnt[i + 1][next[j][c]] = max(cnt[i + 1][next[j][c]], cnt[i][j]);
			}
		double ans = 0.0;
		for (int i = 0; i <= n; i++)
			ans += dp[i][m];
		string t = s;
		int mx = 0;
		for (int i = 0; i <= m; i++)
			mx = max(mx, cnt[n][i]);
		ans = mx - ans;
		cerr << _ << endl;
		cout << "Case #" << _ << ": " << setprecision(9) << fixed << ans << endl;
	}
	return 0;
}
