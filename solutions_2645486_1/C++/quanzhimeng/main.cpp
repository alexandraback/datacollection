#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int e,r,n;
int v[100];
int ans;
void dfs(int s,int i,int c)
{
    if(c>ans)
        ans=c;
    if(i>=n)
        return;
    int j;
    int tmp;
    for(j=s;j>=0;--j)
    {
        tmp=v[i]*j;
        if(s-j+r>e) dfs(e,i+1,tmp+c);
        else    dfs(s-j+r,i+1,tmp+c);
    }
    if(c>ans)
        ans=c;
    return;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    int t;
    int k;
    scanf("%d",&cases);
    t=1;
    while(cases--)
    {
        printf("Case #%d: ",t);
        t++;
        scanf("%d%d%d",&e,&r,&n);
        for(k=0;k<n;++k)
        {
            scanf("%d",&v[k]);
//            cout<<v[k]<<endl;
        }
        ans=-1;
        dfs(e,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
