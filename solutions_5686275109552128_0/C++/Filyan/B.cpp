#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

string const name = "B";

int const N = 1e3 + 43;

int test, curTest, d, p, cnt, ans, dp[N][N];

vector<int> a;

void calcDp()
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			dp[i][j] = 1e5 + 123;
			if(i <= j)
				dp[i][j] = 0;
		}
	}

	for(int i=1;i<N;++i)
	{
		for(int j=1;j<i;++j)
		{
			for(int k=1;k<i;++k)
			{
				dp[i][j] = min(dp[i][j], dp[i-k][j] + 1 + dp[k][j]);
			}
		}
	}
}

void print(int v)
{
	printf("Case #%d: %d\n",++curTest,v);
}

int main()
{
	freopen((name + ".in").c_str(),"r",stdin);
	freopen((name + ".out").c_str(),"w",stdout);

	calcDp();

	cin >> test;
	while(test--)
	{
		cin >> d;
		ans = N;
		a.clear();

		for(int i=0;i<d;++i)
		{
			cin >> p;
			a.push_back(p);
		}

		for(int i=1;i<N;++i)
		{
			int pAns = i;
			for(int j=0;j<a.size();++j)
			{
				pAns += dp[a[j]][i];
			}
			ans = min(ans, pAns);
		}
		print(ans);
	}

	return 0;
}
