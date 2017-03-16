#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
bool isbff[1005][1005];
int ans=0;
int place[1005];
bool isplace[1005];
bool checkmax(int n)
{
    if(n<2)
        return 0;
    if(!isbff[place[1]][place[2]]&&!isbff[place[1]][place[n]])
        return 0;
    for(int i=2;i<n;++i)
        if(!isbff[place[i]][place[i+1]]&&!isbff[place[i]][place[i-1]])
            return 0;
    if(!isbff[place[n]][place[1]]&&!isbff[place[n]][place[n-1]])
        return 0;
    return 1;
}
void dfs(int now,int all)
{
    if(checkmax(now-1))
        ans=max(ans,now-1);
    if(now==all+1)
    {
        return;
    }
    for(int i=1; i<=all; ++i)
        if(!isplace[i])
        {
            place[now]=i;
            isplace[i]=1;
            dfs(now+1,all);
            isplace[i]=0;
        }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("1.out","w",stdout);
    int t;
    int ca=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(isbff,0,sizeof(isbff));
        int n;
        ans=0;
        scanf("%d",&n);
        vector<int>bff(n+1);
        memset(isplace,0,sizeof(isplace));
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&bff[i]);
            isbff[i][bff[i]]=1;
        }
        dfs(1,n);
        printf("Case #%d: %d\n",++ca,ans);
    }
}
