#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;
int dp[1024][1024];
int calculate(int target, int number)
{
	return (number + target - 1) / target - 1;
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	memset(dp, -1, sizeof(dp));
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int d;
		cin >> d;
		vector<int> p(d);
		int best = 1 << 20;
		int maxm = -1;
		for (int i = 0; i < d; i++)
		{
			cin >> p[i];
			maxm = max(maxm, p[i]);
		}
		for (int i = 1; i <= maxm; i++)
		{
			int res = i;
			for (int j = 0; j < d; j++)
			{
				res += calculate(i, p[j]);
			}
			best = min(best, res);
		}
		cout << best << endl;
	}
	return 0;
}
