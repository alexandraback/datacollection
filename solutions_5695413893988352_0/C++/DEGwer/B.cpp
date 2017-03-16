#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
typedef pair<ll, pii>pi3;
pi3 dp[20][2][2];
ll p10[19];
string get(ll a, int d)
{
	string r;
	for (int i = 0; i < d; i++)
	{
		r.push_back(a % 10 + '0');
		a /= 10;
	}
	reverse(r.begin(), r.end());
	return r;
}
int main()
{
	freopen("b-small-attempt0.in", "r", stdin);
	freopen("small.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	p10[0] = 1;
	for (int i = 1; i <= 18; i++)p10[i] = p10[i - 1] * 10;
	for (int p = 1; p <= data; p++)
	{
		string sa, sb;
		cin >> sa >> sb;
		for (int i = 0; i < 20; i++)dp[i][0][0] = dp[i][0][1] = make_pair(2000000000000000000LL, make_pair(0LL, 0LL));
		for (int i = 0; i < 20; i++)dp[i][1][0] = dp[i][1][1] = make_pair(2000000000000000000LL, make_pair(0LL, 0LL));
		dp[0][0][0].first = dp[0][0][1].first = 0;
		dp[0][1][0].first = dp[0][1][1].first = 0;
		reverse(sa.begin(), sa.end());
		reverse(sb.begin(), sb.end());
		for (int i = 0; i < sa.size(); i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				for (int k = 0; k <= 9; k++)
				{
					if (sa[i] != '?'&&sa[i] != '0' + j)continue;
					if (sb[i] != '?'&&sb[i] != '0' + k)continue;
					if (j < k)
					{
						dp[i + 1][0][0] = min(dp[i + 1][0][0], make_pair(dp[i][0][0].first + p10[i] * (k - j), make_pair(dp[i][0][0].second.first + p10[i] * j, dp[i][0][0].second.second + p10[i] * k)));
						dp[i + 1][0][0] = min(dp[i + 1][0][0], make_pair(dp[i][1][1].first + p10[i] * (k - j), make_pair(dp[i][1][1].second.first + p10[i] * j, dp[i][1][1].second.second + p10[i] * k)));
						dp[i + 1][1][0] = min(dp[i + 1][1][0], make_pair(dp[i][1][0].first - p10[i] * (k - j), make_pair(dp[i][1][0].second.first + p10[i] * j, dp[i][1][0].second.second + p10[i] * k)));
						dp[i + 1][1][0] = min(dp[i + 1][1][0], make_pair(dp[i][0][1].first - p10[i] * (k - j), make_pair(dp[i][0][1].second.first + p10[i] * j, dp[i][0][1].second.second + p10[i] * k)));
					}
					else if (j > k)
					{
						dp[i + 1][0][1] = min(dp[i + 1][0][1], make_pair(dp[i][1][0].first + p10[i] * (j - k), make_pair(dp[i][1][0].second.first + p10[i] * j, dp[i][1][0].second.second + p10[i] * k)));
						dp[i + 1][0][1] = min(dp[i + 1][0][1], make_pair(dp[i][0][1].first + p10[i] * (j - k), make_pair(dp[i][0][1].second.first + p10[i] * j, dp[i][0][1].second.second + p10[i] * k)));
						dp[i + 1][1][1] = min(dp[i + 1][1][1], make_pair(dp[i][0][0].first - p10[i] * (j - k), make_pair(dp[i][0][0].second.first + p10[i] * j, dp[i][0][0].second.second + p10[i] * k)));
						dp[i + 1][1][1] = min(dp[i + 1][1][1], make_pair(dp[i][1][1].first - p10[i] * (j - k), make_pair(dp[i][1][1].second.first + p10[i] * j, dp[i][1][1].second.second + p10[i] * k)));
					}
					else
					{
						dp[i + 1][0][0] = min(dp[i + 1][0][0], make_pair(dp[i][0][0].first, make_pair(dp[i][0][0].second.first + p10[i] * j, dp[i][0][0].second.second + p10[i] * k)));
						dp[i + 1][0][1] = min(dp[i + 1][0][1], make_pair(dp[i][0][1].first, make_pair(dp[i][0][1].second.first + p10[i] * j, dp[i][0][1].second.second + p10[i] * k)));
						dp[i + 1][1][0] = min(dp[i + 1][1][0], make_pair(dp[i][1][0].first, make_pair(dp[i][1][0].second.first + p10[i] * j, dp[i][1][0].second.second + p10[i] * k)));
						dp[i + 1][1][1] = min(dp[i + 1][1][1], make_pair(dp[i][1][1].first, make_pair(dp[i][1][1].second.first + p10[i] * j, dp[i][1][1].second.second + p10[i] * k)));
					}
				}
			}
			//for (int j = 0; j < 2; j++)for (int k = 0; k < 2; k++)printf("%lld ", dp[i + 1][j][k].first); printf("\n");
		}
		pi3 ans = min(dp[sa.size()][0][0], dp[sa.size()][0][1]);
		cout << "Case #" << p << ": " << get(ans.second.first, sa.size()) << " " << get(ans.second.second, sb.size()) << endl;
	}
}