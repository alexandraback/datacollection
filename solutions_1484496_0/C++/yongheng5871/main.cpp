#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;

const int Maxn=210;

int n;
int a[Maxn],S;
map<int,vector<int> > LO;
int mask;
void IN()
{
    LO.clear();
   mask=1<<n;
    for(int i=0;i<mask;++i)
    {
        int sum=0;
        for(int j=0;j<n;++j)
            if(i&(1<<j)) sum+=a[j];
        LO[sum].push_back(i);
    }
}
void ss()
{
    for(map<int,vector<int> >::iterator it=LO.begin();it!=LO.end();++it)
    {
        vector<int> now=it->second;
        if(now.size()==1)continue;
        for(int j=0;j<(int)now.size();++j)
            for(int k=j+1;k<(int)now.size();++k)
                if((now[k]|now[j]) == (now[j]+now[k]))
                {
                    vector<int> ans;
                    for(int u=0;u<n;++u)
                        if(now[j]&(1<<u))ans.push_back(u);
                    for(int u=0;u<(int)ans.size();++u)
                        printf("%d%c",a[ans[u]],u==(int)ans.size()-1?'\n':' ');
                    ans.clear();

                    for(int u=0;u<n;++u)
                        if(now[k]&(1<<u))ans.push_back(u);
                    for(int u=0;u<(int)ans.size();++u)
                        printf("%d%c",a[ans[u]],u==(int)ans.size()-1?'\n':' ');
                    return;
                }
    }
    printf("Impossible\n");
}
void solve()
{
    IN();
    ss();
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;++cas)
    {

        printf("Case #%d:\n",cas);
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
        solve();
    }
    return 0;
}
