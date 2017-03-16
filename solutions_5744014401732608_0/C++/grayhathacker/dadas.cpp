/*
jai shree ram _/\_
A hacker from NITP
*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vs;
typedef map<int,char> msi;
typedef pair<int,int> pa;
typedef long long int ll;

int m,b,k,i,l,j,u,a[6][6],dp[6][6][6],ans,v;
int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
  	freopen("B-small-attempt1o.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  	int t,pe=1;
	cin>>t;
	while(t--)
	{
	    cout<<"Case #"<<pe++<<": ";
	    cin>>b>>m;
	    k=(b-1)*(b-1);
	    for(i=1;i<(1<<k);i++)
	    {
	        memset(dp,0,sizeof(dp));
	        for(j=0;j<b;j++)
                dp[1][b-1][j]=dp[1][j][j]=0;
            u=i;
            for(l=0;l<b;l++)
            {
                for(j=0;j<b;j++)
                {
                    if(i==j)
                        continue;
                    dp[1][l][j]=(u&1);
                    u/=2;
                }
            }
            bool flag=0;
            for(l=0;l<b;l++)
            {
                for(j=0;j<b;j++)
                    if(dp[1][l][j]==1 && dp[1][j][l]==1)
                    {
                        flag=1;
                        break;
                    }
            }
            if(flag)
                continue;
            for(v=2;v<b;v++)
            {
                for(u=0;u<b;u++)
                {
                    for(l=0;l<b;l++)
                    {
                        for(j=0;j<b;j++)
                        {
                            dp[v][l][j]+=dp[v-1][l][u]*dp[v-1][u][j];
                        }
                    }
                }
            }
            ans=0;
            for(v=1;v<b;v++)
                ans+=dp[v][0][b-1];
            if(ans==m)
                break;
	    }
	    if(i==(1<<k))
            cout<<"IMPOSSIBLE\n";
        else
        {
            cout<<"POSSIBLE\n";
            for(i=0;i<b;i++)
            {
                for(j=0;j<b;j++)
                    cout<<dp[1][i][j];
                cout<<"\n";
            }
        }
	}
	return 0;
}
