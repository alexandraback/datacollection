#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

char s[4100];

vector <string> vec[1000];





int DP[4100][4100];

int main()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	int maxsz = 0;
	while (scanf("%s", &s) != -1)
	{
		int sz = strlen(s);
		string cur = string(s);
		vec[sz].push_back(cur);
	}
	

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d\n", &t);

	for (int test = 0; test < t; test++)
	{
		gets(s);
		int n = strlen(s);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				DP[i][j] = 0;

		memset(DP, 0, sizeof(DP));
		DP[0][0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = max(0, i-1); j >= max(0, i-5); j--)
				if (DP[i][j])
				{
					bool flag = 0;
					if (j == 0 && DP[i][j] == 1)
						flag = 1;
					for (int len = 1; len <= min(n-i, 11); len++)
					{
						for (int k = 0; k < vec[len].size(); k++)
						{
							int dif = 0, lastindex = (flag)?-10:j;
							bool possible = 1;
							for (int l = 0; l < len; l++)
								if (vec[len][k][l] != s[i+l])
								{
									if (i+l - lastindex > 4)
									{
										lastindex = i+l;
										dif++;
									}
									else
									{
										possible = 0;
										break;
									}
								}
							if (!possible)
								continue;

							if (lastindex < 0)
								lastindex = 0;
							if (DP[i+len][lastindex] == 0 || DP[i+len][lastindex] > DP[i][j] + dif)
								DP[i+len][lastindex] = DP[i][j] + dif;
						}
					}
				}
				if (i >= 5)
				for (int j = 0; j <= i-5; j++)
					if (DP[i+1][j])
						if (DP[i+1][i+1-5] == 0 || DP[i+1][i+1-5] > DP[i+1][j])
							DP[i+1][i+1-5] = DP[i+1][j];
		}

		int ans = -1;
		for (int i = 0; i <= n; i++)
			if (DP[n][i] && (ans == -1 || ans > DP[n][i] - 1))
				ans = DP[n][i] - 1;
		printf("Case #%d: %d\n", test + 1, ans);
	}


	return 0;
}