#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

int next[105][26];
double dp[105][105];
bool flag[105][105];

int k, l, s;
string keys, word;
double calc(int now, int pos)
{
	if (now == s)
		return 0;

	if (flag[now][pos]) return dp[now][pos];
	flag[now][pos] = true;
	dp[now][pos] = 0;
	for (int i = 0; i < k; ++i)
	{
		int nextp = next[pos][keys[i] - 'A'];
		dp[now][pos] += 1.0 / k * (calc(now + 1, nextp) + (nextp == word.size()));
	}
	return dp[now][pos];
}
int dp2[105][105];
int getMax(int now, int pos)
{
	if (now == s)
		return 0;

	if (flag[now][pos]) return dp2[now][pos];
	flag[now][pos] = true;
	dp2[now][pos] = 0;
	for (int i = 0; i < k; ++i)
	{
		int nextp = next[pos][keys[i] - 'A'];
		dp2[now][pos] = max(dp2[now][pos], getMax(now + 1, nextp) + (nextp == word.size()));
	}
	return dp2[now][pos];
}
int main()
{
	int cases;
	cin >> cases;
	for (int tcase = 1; tcase <= cases; ++tcase)
	{
		cin >> k >> l >> s;
		cin >> keys;
		cin >> word;
		for (int i = 0; i <= word.size(); ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				string str = word.substr(0, i);
				str += 'A' + j;
				int an = -1;
				for (int p = 0; p < str.size() && p <= word.size(); ++p)
					if (word.substr(0, p) == str.substr(str.size() - p))
					{
						an = p;
					}
				assert(an != -1);
				next[i][j] = an;
			}
			if (i < word.size())
				next[i][word[i] - 'A'] = i + 1;
		}
		memset(flag, 0, sizeof(flag));
		int need = getMax(0, 0);
		memset(flag, 0, sizeof(flag));
		printf("Case #%d: %.10f\n", tcase, need - calc(0, 0));
	}
}
