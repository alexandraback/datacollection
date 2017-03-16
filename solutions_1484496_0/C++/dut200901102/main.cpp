#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN=210;

int n;
int a[MAXN],S;
map<int,vector<int> > load;

void init()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
}

void solve()
{
    load.clear();
    int mask=1<<n;
    for(int i=0;i<mask;++i)
    {
        int sum=0;
        for(int j=0;j<n;++j)
            if(i&(1<<j)) sum+=a[j];
        load[sum].push_back(i);
    }
    for(map<int,vector<int> >::iterator it=load.begin();it!=load.end();++it)
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
    puts("Impossible");
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,cases=1;
    for(scanf("%d",&t);t--;)
    {
        printf("Case #%d:\n",cases++);
        init();
        solve();
    }
    return 0;
}
