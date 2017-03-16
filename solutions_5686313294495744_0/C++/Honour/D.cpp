//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

int dp[100009];
vector<pair<int,int> >vec;
char dd[100],ff[100];
string aa,ss;
map<string,int>mymap,yourmap;

int check(int curr,int n,int tot)
{
    int ans,i,j,flag,flagg;
    if(curr==tot) return 0;
    if(dp[curr]!=-1) return dp[curr];
    ans=0;

    for(i=0;i<n;i++)
    {
        if(!((1<<i) & curr))
        {
            flag=0;
            flagg=0;
            for(j=0;j<n;j++)
            {
                if(flag && flagg) break;
                if(((1<<j) & curr))
                {
                    if(vec[j].first==vec[i].first) flag=1;
                    if(vec[j].second==vec[i].second) flagg=1;
                }
            }

            if(flag && flagg) ans=max(ans,1+check((curr | (1<<i)),n,tot));
            else ans=max(ans,check((curr | (1<<i)),n,tot));
        }
    }

    dp[curr]=ans;
    return dp[curr];

}

int main()
{
    freopen("out.txt","rt",stdin);
    freopen("out1.txt","wt",stdout);
    int i,j,k,l,n,cas,test,flag,temp,now,ans=0,index,indexx,tempp;

    cin>>test;
    for(cas=1;cas<=test;cas++)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        index=0;
        indexx=0;
        vec.clear();
        mymap.clear();
        yourmap.clear();

        for(i=1;i<=n;i++)
        {
            scanf("%s%s",dd,ff);
            aa=dd;
            ss=ff;

            if(mymap[aa]==0)
            {
                mymap[aa]=++index;
            }

            if(yourmap[ss]==0)
            {
                yourmap[ss]=++indexx;
            }

            temp=mymap[aa];
            tempp=yourmap[ss];

            vec.push_back(make_pair(temp,tempp));

        }

        ans=check(0,n,(1<<n)-1);

        printf("Case #%d: %d\n",cas,ans);

    }



}
