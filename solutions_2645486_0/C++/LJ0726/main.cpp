#include <iostream>

using namespace std;
int ans;
int e,r,n;
int a[100];
void dfs(int t,int tmp,int ee)
{
    if(t==n)
    {
        if(tmp > ans) ans = tmp;
        return;
    }
    for (int i=0; i<=ee; i++)
    {
        tmp += a[t]*i;
        int hehe = ee-i+r;
        if(hehe>e) hehe = e;
        dfs(t+1,tmp,hehe);
        tmp -= a[t]*i;
    }
}
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    int k = 0;
    scanf("%d",&t);

    while(t--)
    {
        k++;
        ans = 0;
        scanf("%d %d %d",&e,&r,&n);
        for (int i=0; i<n; i++)
            scanf("%d",&a[i]);
        dfs(0,0,e);
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}
