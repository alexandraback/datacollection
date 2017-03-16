#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int e,r,n,a[11];
int ans;
void dfs(int p,int mon,int get)
{
    if(p==n)
    {
        ans=max(ans,get);
        return;
    }
    for(int i=0;i<=mon;i++)
    {
        dfs(p+1,min(mon-i+r,e),get+i*a[p]);
    }
}
void init()
{
    scanf("%d%d%d",&e,&r,&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    ans=0;
    dfs(0,e,0);
    printf("%d\n",ans);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int w;cin>>w;
    for(int id=1;id<=w;id++)
    {
        printf("Case #%d: ",id);
        init();
    }
//    cout << "Hello world!" << endl;
    return 0;
}
