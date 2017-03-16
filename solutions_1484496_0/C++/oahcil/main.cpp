#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 210

int n;
int a[MAXN],S;
map<int,vector<int> > LLLL;
int mmm;
void init_data()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    LLLL.clear();
    mmm=1<<n;
    for(int i=0;i<mmm;++i)
    {
        int sum=0;
        for(int j=0;j<n;++j)
            if(i&(1<<j)) sum+=a[j];
        LLLL[sum].push_back(i);
    }
}

bool solve1()
{
    init_data();
    for(map<int,vector<int> >::iterator it=LLLL.begin();it!=LLLL.end();++it)
    {
        vector<int> NNNN=it->second;
        if(NNNN.size()==1)continue;
        for(int j=0;j<(int)NNNN.size();++j)
            for(int k=j+1;k<(int)NNNN.size();++k)
                if((NNNN[k]|NNNN[j]) == (NNNN[j]+NNNN[k]))
                {
                    vector<int> ans;
                    for(int u=0;u<n;++u)
                        if(NNNN[j]&(1<<u))ans.push_back(u);
                    for(int u=0;u<(int)ans.size();++u)
                        printf("%d%c",a[ans[u]],u==(int)ans.size()-1?'\n':' ');
                    ans.clear();

                    for(int u=0;u<n;++u)
                        if(NNNN[k]&(1<<u))ans.push_back(u);
                    for(int u=0;u<(int)ans.size();++u)
                        printf("%d%c",a[ans[u]],u==(int)ans.size()-1?'\n':' ');
                    return 1;
                }
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;scanf("%d",&t);
    int cases=1;
    while(t--)
    {
        printf("Case #%d:\n",cases++);
        if(!solve1())puts("Impossible");
    }
    return 0;
}
