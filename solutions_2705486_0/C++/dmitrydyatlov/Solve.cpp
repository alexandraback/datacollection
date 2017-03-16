#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long lint;
typedef vector<int> vi;
typedef vector<string> vs;
const int INF = 0x7fffffff;

set<string> s;

int dp[100][100];

int Solution()
{
	string str;
	cin >> str;
	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			dp[i][j] = -1;
	dp[0][5] = 0;
	for(int i = 0; i < str.size(); ++i)
	{
		for(int len = 1; len <= min(10u, str.size() - i); ++len)
		{
			string now = str.substr(i, len);
			if(s.find(now) != s.end())
				for(int j = 1; j <= 5; ++j)
				{
					int *nextDp = &(dp[i + len][j + len > 5 ? 5 : j + len]);
					if(dp[i][j] != -1 && (*nextDp == -1 || *nextDp > dp[i][j]))
					{
						*nextDp = dp[i][j];
					}
				}

			for(int i1 = 0; i1 < len; ++i1)
			{
				for(int ch = 'a'; ch <= 'z'; ++ch)
				{
					if(now[i1] == ch)
						continue;
					string new_now = now;
					new_now[i1] = ch;
					if(s.find(new_now) != s.end())
					{
						for(int j = 1; j <= 5; ++j)
						{
							if(i1 + j < 5)
								continue;
							int *nextDp = &(dp[i + len][len - i1 > 5 ? 5 : len - i1]);
							if(dp[i][j] != -1 && (*nextDp == -1 || *nextDp > dp[i][j] + 1))
							{
								*nextDp = dp[i][j] + 1;
							}
						}
						break;
					}
				}
			}


			for(int i1 = 0; i1 < len; ++i1)
			{
				for(int i2 = i1 + 5; i2 < len; ++i2)
				{
					for(int ch1 = 'a'; ch1 <= 'z'; ++ch1)
					{
						bool flag_break = false;
						for(int ch2 = 'a'; ch2 <= 'z'; ++ch2)
						{
							if(now[i1] == ch1 || now[i2] == ch2)
								continue;
							string new_now = now;
							new_now[i1] = ch1;
							new_now[i2] = ch2;
							if(s.find(new_now) != s.end())
							{
								for(int j = 1; j <= 5; ++j)
								{
									if(i1 + j < 5)
										continue;
									int *nextDp = &(dp[i + len][len - i2 > 5 ? 5 : len - i2]);
									if(dp[i][j] != -1 && (*nextDp == -1 || *nextDp > dp[i][j] + 2))
									{
										*nextDp = dp[i][j] + 2;
									}
								}
								flag_break = true;
								break;
							}
						}
						if(flag_break)
							break;
					}
				}
			}

		}
	}

	int ans = 100;
	for(int i = 1; i <= 5; ++i)
		if(dp[str.size()][i] != -1)
			ans = min(ans, dp[str.size()][i]);
	cout << ans;
	return 0;
}

#define debug 1

char buf[100];

int main()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	int m = 0;
	while(gets(buf))
	{
		string str = buf;
		s.insert(str);
	}

#ifdef debug
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
#endif
	int n;
	cin >> n;
	getchar();
	for(int i = 1; i <= n; ++i)
	{
		printf("Case #%d: ", i);
		Solution();
		printf("\n");
	}
	return 0;
}
