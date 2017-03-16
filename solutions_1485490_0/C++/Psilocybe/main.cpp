#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

const int MAXN = 1005;

typedef long long ll;

ll dp[MAXN][MAXN];

pair<ll,ll> a[MAXN], b[MAXN];

int s1,s2;
int n,m;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int T;
	cin>>T;

	for(int test=0;test<T;test++)
	{
		cin>>n>>m;
		
		for(int i=0;i<n;i++)
			cin>>a[i].first>>a[i].second;

		for(int i=0;i<m;i++)
			cin>>b[i].first>>b[i].second;
	
		s1 = 1, s2=1;
		
		for(int i=1;i<n;i++)
		{
			if(a[s1-1].second == a[i].second)
				a[s1-1].first += a[i].first;
			else
				a[s1++] = a[i];
		}
		for(int i=1;i<m;i++)
		{
			if(b[s2-1].second == b[i].second)
				b[s2-1].first += b[i].first;
			else
				b[s2++] = b[i];
		}
		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				dp[i][j] = 0;

		for(int i=0;i<s1;i++)
		{
			for(int j=0;j<s2;j++)
			{
				ll c1 = 0;
				for(int k=i;k<=s1;k++)
				{
					ll c2=0;
					for(int l=j;l<=s2;l++)
					{
						dp[k][l] = max(dp[k][l],dp[i][j]+min(c1,c2));

						if(b[l].second == a[i].second)
							c2 += b[l].first;
					}
					if(a[k].second == a[i].second)
						c1 += a[k].first;
				}
			}
		}
		cout<<"Case #"<<test+1<<": "<<dp[s1][s2]<<endl;
	}
	return 0;
}