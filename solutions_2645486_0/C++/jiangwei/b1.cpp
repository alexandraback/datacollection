#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 10;
const int MAX_E = 5;

int main()
{
	int T, task;
	cin >> T;

	for (task = 1; task <= T; task++)
	{
		cout << "Case #" << task << ": ";

		long long E, R;
		int N;
		cin >> E >> R >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		if (R > E) R = E;
		
		long long dp[MAX_N+1][MAX_E+1];
		memset(dp, 0xff, sizeof(dp));

		dp[0][E] = 0;

		for (int i = 1; i <= v.size(); i++)
		{
			int vi = v[i-1];
			for (int e = R; e <= E; e++)
			{
				long long &ret = dp[i][e];
				for (int e1 = R; e1 <= E; e1++)
				{
					if (dp[i-1][e1] < 0) continue;
					long long used = e1 - (e - R);
					if (used >= 0)
					{
						ret = max(ret, used * vi + dp[i-1][e1]);
					}
				}
			}
		}

		long long result = 0;
		for (int e = R; e <= E; e++)
		{
			result = max(result, dp[N][e]);
		}
		cout << result << endl;
	}

	return 0;
}
