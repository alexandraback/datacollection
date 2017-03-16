#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <queue>

using namespace std;
const int MAXN = 1e5+10;
const long double eps = 1e-7;
typedef unsigned long long ull;
ull E,R,N,M;
ull dp[100][1000];
ull v[10000000+10];
ull solve()
{
	for(int i = 0; i <= E; ++i)
		dp[1][i] = (E-i)*v[1];
	for(int i = 2; i <= N; ++i)
	{
		for(int k = 0; k <= E; ++k)
		{
			int XX = min(k+R,E);
			//ull tmp = 0;
			for(int j = 0; j <= XX; ++j)
			{
				//tmp = max(tmp, dp[i-1][k]+(E-j)*v[i]);
				dp[i][j] = max(dp[i][j], dp[i-1][k]+(XX-j)*v[i]);
			}
		}
	}
	ull ans = 0;
	for(int i = 0; i <= E; ++i)
		ans = max(dp[N][i],ans);
	return ans;
}
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; ++i)
	{
		memset(dp,0,sizeof(dp));
		cin>>E>>R>>N;
		for(int j = 1; j <=N; ++j)
			cin>>v[j];
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	}
	return 0;
}
