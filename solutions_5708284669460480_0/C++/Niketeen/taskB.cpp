#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
typedef long long ll;
const double eps = 1e-9;
const int mod = 1e9 + 7;



int main(){
	freopen("B-small-attempt0 (4).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t)
	{
		int k, l, s;
		cin >> k >> l >> s;
		vector<double> cnt(26, 0);
		for (int i = 0; i < k; ++i)
		{
			char c;
			cin >> c;
			cnt[c - 'A']++;
		}
		string str;
		cin >> str;

		vector<vector<int> > mxpref(str.size() + 2, (vector<int>(26, 0)));
		for (int i = 0; i <= str.size(); ++i)
		{
			for (int j = 0; j < cnt.size(); ++j)
			{
				string cur = str.substr(0, i);
				cur += char(j + 'A');
				int mxlen = 0;
				for (int q = 0; q <= cur.size(); ++q)
				{
					bool can = true;
					for (int m = 0; m < q; ++m)
					{
						if (m >= str.size())
						{
							can = false;
							break;
						}
						int ptr = (int)cur.size() - q + m;
						if (str[m] != cur[ptr])
						{
							can = false;
							break;
						}
					}
					if (can)
						mxlen = max(mxlen, q);
				}
				mxpref[i][j] = mxlen;
			}
		}

		//int a = 0;

		vector<vector<double> > dp(s+5, vector<double>(str.size() + 1, 0));
		vector<vector<ll> > dp2(s+5, vector<ll>(str.size() + 1, 0));
		vector<vector<bool> > can(s + 5, vector<bool>(str.size() + 1, 0));
		double ans = 0;
		for (int i = 0; i < 26; ++i)
		{
			dp[0][mxpref[0][i]] += cnt[i] / k;
			if (cnt[i] != 0)
			{
				can[0][mxpref[0][i]] = 1;
			}
		}
		ll mxban = 0;
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j <= str.size(); ++j)
			{
				
				if (j == str.size())
				{
					ans += dp[i][j];
					if (can[i][j])
						dp2[i][j]++;
				}
				for (int q = 0; q < 26; ++q)
				{
					dp[i + 1][mxpref[j][q]] += dp[i][j] * cnt[q] / k;

					if (can[i][j] && cnt[q] != 0)
					{
						can[i + 1][mxpref[j][q]] = true;
					}

					dp2[i + 1][mxpref[j][q]] = max(dp2[i][j], dp2[i + 1][mxpref[j][q]]);
				}

				mxban = max(mxban, dp2[i][j]);
			}
		}
		
		printf("Case #%d: %.7lf\n", t, (mxban - ans));

		//cout << "Case #" << t << ": " << ans << "\n";

	}



	return 0;
}