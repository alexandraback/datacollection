#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define MAXN 103
using namespace std;
int T;
int A, N;
int mot[MAXN];
int dp[MAXN][MAXN * 10 + 3];

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A-small-attempt0.out");

	cin >> T;

	for (int ts = 1; ts <= T; ++ts)
	{
		cin >> A >> N;

		for (int i = 1; i <= N; ++i)
			cin >> mot[i];

		sort(mot + 1, mot + N + 1);

		int tmax = 1000 * 1000 + 3;
		int ans = tmax;

		for (int j = 1; j <= N + 1; ++j)
		{
			int cur = A;
			int op = 0;
			bool can = true;
			for (int i = 1; i < j; ++i)
			{
				while (cur <= mot[i])
				{
					cur += (cur - 1);
					++op;
					if (cur == 1){can = false;break;}
				}
				if (!can)break;
				cur += mot[i];
				cur = min(cur, tmax);
			}
			if (can)
			{
				op += (N - j + 1);
				ans = min(ans, op);
			}
		}


		cout << "Case #" << ts << ": " << ans << endl;
		/*int tmax = 1000 * 1000 + 3;
		int cmax = MAXN * 10 + 3;

		for (int i = 0; i < MAXN; ++i)
			for (int j = 0; j < cmax; ++j)
				dp[i][j] = 0;

		dp[0][0] = A;
		for (int j = 1; j < cmax; ++j)
			dp[0][j] = min(dp[0][j-1] + dp[0][j-1] - 1, tmax);

		for (int i = 0; i < N; ++i)
			for(int j = 0; j < cmax; ++j)
			{
				if (dp[i][j] > tmax)
					dp[i][j] = tmax;
				if (dp[i][j] <= mot[i])
					dp[i][j] = -1;
				if (dp[i][j] != -1)
				{
					if (dp[i][j] > mot[i + 1])
						dp[i+1][j] = max(dp[i+1][j], dp[i][j] + mot[i + 1]);
					else
					{
						dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
						dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + dp[i][j]-1);
					}
				}
			}*/




	}


	cin.close(); cout.close();
	return 0;
}

