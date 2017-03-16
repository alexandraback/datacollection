#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

typedef long long ll;

ifstream fin("input.txt");
ofstream fout("output.txt");

int tc;

int dp[1000001];

int rev(int x)
{
	int l=0;
	while (x)
	{
		l = l*10+(x%10);
		x/=10;
	}
	return l;
}

queue<int> q;

void init()
{
	memset(dp,-1,sizeof(dp));
	dp[1] = 0;
	q.push(1);

	while (!q.empty())
	{
		int t;
		t = q.front();
		q.pop();
		if (dp[t+1]==-1)
		{
			dp[t+1] = dp[t] +1;
			q.push(t+1);
		} else dp[t+1] = min(dp[t+1],dp[t]+1);
		if (dp[rev(t)]==-1)
		{
			dp[rev(t)] = dp[t] +1;
			q.push(rev(t));
		} else dp[rev(t)] = min(dp[rev(t)],dp[t]+1);
	}
}


int main()
{
	fin>>tc;

	init();
	for (int tt=1; tt<=tc; tt++)
	{
		int n;
		fin>>n;

		fout<<"Case #"<<tt<<": ";
		fout<<dp[n]+1;
		fout<<'\n';
	}

	return 0;
}