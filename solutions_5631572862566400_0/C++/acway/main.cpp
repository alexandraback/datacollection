#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1100;
int a[maxn];
int ans ;
int n;
bool v[maxn];
void dfs(int first,int pre,int x,int d)
{
    if(a[x] == first||a[x] == pre)
    {
        ans = max(ans,d);
    }
    if(a[x] == pre)
    {
        for(int i=1; i<=n; ++i)
        {
            if(!v[i])
            {
                v[i] = true;
                dfs(first,x,i,d+1);
                v[i] = false;
            }
        }
    }
    if(!v[a[x]])
    {
        v[a[x]] = true;
        dfs(first,x,a[x],d+1);
        v[a[x]] = false;
    }
}
int main()
{
    int t,ca=1;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1; i<=n; i++)
        {
            memset(v,false,sizeof(v));
            v[i] = true;
            dfs(i,-1,i,1);
        }
        printf("Case #%d: %d\n",ca++,ans);
    }
    return 0;
}
