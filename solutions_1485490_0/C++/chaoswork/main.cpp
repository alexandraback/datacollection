#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<limits>
using namespace std;

typedef long long LL;

LL dp[128][128];
LL cnt[128][128][128];

int main(int argc, char *argv[])
{
#ifdef CHAOS
	freopen("data.in","r",stdin);
#endif
	int T;
	cin>>T;
	int t;
	for(t=1;t<=T;++t)
	{
		cout<<"Case #"<<t<<": ";
		int N,M;
		cin>>N>>M;
		vector<pair<LL,LL> > sn;
		vector<pair<LL,LL> > sm;
		int i,j;
		sn.push_back(make_pair(0,0));
		sm.push_back(make_pair(0,0));
		for(i=0;i<N;++i)
		{
			LL n,p;
			cin>>n>>p;
			sn.push_back(make_pair(n,p));
		}
		for(j=0;j<M;++j)
		{
			LL n,p;
			cin>>n>>p;
			sm.push_back(make_pair(n,p));
		}
		memset(dp,0,sizeof(dp));
		for(i=1;i<=N;++i)
		{
			for(j=1;j<=M;++j)
			{
				int ii,jj;
				LL curi=0;
				for(ii=i;ii>0;--ii)
				{
					LL curj=0;
					for(jj=j;jj>0;--jj)
					{
						if(sn[i].second!=sn[ii].second) continue;
						if(sm[j].second!=sm[jj].second) continue;
						dp[i][j]=max(dp[ii-1][j],dp[i][j]);
						dp[i][j]=max(dp[i][jj-1],dp[i][j]);
						if(sn[ii].second==sm[jj].second)
						{
						//	if(i==ii && jj==j) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+min(sn[i].first,sm[j].first));
						//	if(i==ii && jj!=j) dp[i][j]=max(dp[i][j],dp[ii-1][jj-1]+min(sn[i].first,sm[j].first+sm[jj].first));
						//	if(i!=ii && jj==j) dp[i][j]=max(dp[i][j],dp[ii-1][jj-1]+min(sn[i].first+sn[ii].first,sm[j].first));
						//	if(i!=ii && jj!=j) dp[i][j]=max(dp[i][j],dp[ii-1][jj-1]+min(sn[i].first+sn[ii].first,sm[j].first+sm[jj].first));
							dp[i][j]=max(dp[i][j],dp[ii-1][jj-1]+min(sn[ii].first+curi,sm[jj].first+curj));
						}
						if(sm[j].second==sm[jj].second) curj+=sm[jj].first;
					}
					if(sn[ii].second==sn[i].second) curi+=sn[ii].first;
				}
				//cout<<dp[i][j]<<" ";	
			}
			//cout<<endl;
		}
		cout<<dp[N][M]<<endl;
	}
	return 0;
}
