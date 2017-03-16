#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 105;

int max_cnt[N][N];
double dp[N][N];
double pr[N][N];

double solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			max_cnt[i][j] = -1;
			dp[i][j] = 0;
			pr[i][j] = 0;
		}
	}

	int _k, _l, s;
	cin >> _k >> _l >> s;
	string keyboard;
	cin >> keyboard;
	string target;
	cin >> target;

	dp[0][0] = 0;
	pr[0][0] = 1;
	max_cnt[0][0] = 0;

	for (int cnt = 0; cnt < s; cnt++)
	{
		for (int pref = 0; pref < (int)target.length(); pref++)
		{
			//printf("cnt = %d pref = %d dp = %.10lf pr = %.10lf max_cnt = %d\n", cnt, pref, dp[cnt][pref], pr[cnt][pref], max_cnt[cnt][pref]);
			
			if (max_cnt[cnt][pref] == -1)
				continue;

			double go_pr = (double)1 / (double)keyboard.length();
			for (char c : keyboard)
			{
				if (c == target[pref])
				{
					if (pref + 1 == (int)target.length())
					{
						int new_pref = 0;
						for (int i = 1; i < (int)target.length(); i++)
						{
							int cur_pref = (int)target.length() - i;
							if (target.substr(0, cur_pref) == target.substr(i, cur_pref))
							{
								new_pref = cur_pref;
								break;
							}
						}
					
						//printf("go_pr = %.10lf pref = %d new_pref = %d\n", go_pr, pref, new_pref);
						
						dp[cnt + 1][new_pref] += go_pr * (pr[cnt][pref] * 1 + dp[cnt][pref]);
						pr[cnt + 1][new_pref] += go_pr * pr[cnt][pref];
						max_cnt[cnt + 1][new_pref] = max(max_cnt[cnt + 1][new_pref], max_cnt[cnt][pref] + 1);
					}
					else
					{
						dp[cnt + 1][pref + 1] += go_pr * dp[cnt][pref];
						pr[cnt + 1][pref + 1] += go_pr * pr[cnt][pref];
						max_cnt[cnt + 1][pref + 1] = max(max_cnt[cnt + 1][pref + 1], max_cnt[cnt][pref]);
					}
				}
				else
				{
					string str = target.substr(0, pref);
					str.push_back(c);
					int new_pref = 0;
					for (int i = 0; i < (int)str.length(); i++)
					{
						int cur_pref = (int)str.length() - i;
						if (target.substr(0, cur_pref) == str.substr(i, cur_pref))
						{
							new_pref = cur_pref;
							break;
						}
					}

					dp[cnt + 1][new_pref] += go_pr * dp[cnt][pref];
					pr[cnt + 1][new_pref] += go_pr * pr[cnt][pref];
					max_cnt[cnt + 1][new_pref] = max(max_cnt[cnt + 1][new_pref], max_cnt[cnt][pref]);
				}
			}
		}
	}

	int max_ans = 0;
	double max_ex = 0;
	for (int pref = 0; pref < (int)target.length(); pref++)
	{
		max_ans = max(max_ans, max_cnt[s][pref]);
		max_ex += dp[s][pref];
	}
	
	//printf("max_ans = %d max_ex = %.10lf\n", max_ans, max_ex);

	return max_ans - max_ex;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
		printf("Case #%d: %.10lf\n", i + 1, solve());

	return 0;
}
