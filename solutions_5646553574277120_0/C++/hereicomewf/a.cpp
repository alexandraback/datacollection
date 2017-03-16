#include <bits/stdc++.h>
using namespace std;

#define cin(n) scanf("%d",&n)
#define pb push_back


int dp[32];
map<int,int>ma;

int main()
{

    int t,m,n,i,j;

    cin(t);
    int jj=1;
    //t=1;
    while(t--)
    {
        int c,d,vl,i,j,k,l,m;
        cin(c);
        cin(d);
        cin(vl);
        vector<int>v;
        ma.clear();
        for(i=0;i<d;i++)
        {cin(j);if(j>vl){continue;}
        v.pb(j);
        ma[j]=1;
        }
        int cnt=0;
        int ans=4;
        for(i=0;i<=vl;i++)
        {
            for(j=i;j<=vl;j++)
            {
                if(j==i&&j!=0)
                continue;
                for(k=j;k<=vl;k++)
                {
                    if(ma[i]||ma[j]||ma[k])
                    continue;
                    if(k==j&&k!=0)
                        continue;
                    vector<int>vv;
                    vv=v;
                    vv.pb(i);vv.pb(j);vv.pb(k);
                    memset(dp,0,sizeof(dp));
                    dp[0]=1;
                    for(l=0;l<vv.size();l++)
                    {
                        for(m=vl;m>=vv[l];m--)
                        {
                            dp[m]=dp[m]||dp[m-vv[l]];
                        }
                    }
                    int fg=1;
                    for(l=0;l<=vl;l++)
                    {
                        if(!dp[l])fg=0;
                    }
                    if(!fg)
                    continue;
                    if(i)cnt++;
                    if(j)cnt++;
                    if(k)
                    cnt++;
                    ans=min(ans,cnt);
                }
            }
        }
        cout<<"Case #"<<jj++<<": ";
        cout<<ans<<"\n";
    }

    return 0;
}
