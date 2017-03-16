#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[11][6];
int E, R;
vector <int> v;

int go(int pos, int e)
{
	if (pos >= v.size())	return 0;
	if (dp[pos][e] != -1)	return dp[pos][e];
	int ans = 0;
	for (int i = 0; i <= e; i++)
		ans = max(ans,v[pos]*i + go(pos+1, min(E,e-i+R)));
	return dp[pos][e] = ans;
}

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		memset(dp,-1,sizeof(dp));
		int N;
		cin >> E >> R >> N;
		v = vector<int>(N);
		for (int j = 0; j < N; j++)
			cin >> v[j];
		cout << "Case #" << (i+1) << ": " << go(0,E) << endl;
	}
	return 0;
}
