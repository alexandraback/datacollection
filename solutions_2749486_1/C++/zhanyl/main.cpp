#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int x,y,flag1,flag2;

int ans[10010],temp[10010],fuck[10010];

bool vis[10010];

bool check(int num)
{
    int sum=(num+1)*num/2,i,flag=0;
    int tempx=x,tempy=y;
    int now=num;
    memset(vis,0,sizeof(vis));
    while(now>=1)
    {
        if(now<=tempx)
        {
            tempx-=now;
            temp[now]=3;
            vis[now]=1;
        }
        now--;
        if(tempx==0)
            break;
    }
    int cha=(sum-x-y)/2;
    for(i=num;i>=1;i--)
    {
        if(vis[i]==1)
            continue;
        if(i<=cha)
        {
            cha-=i;
            vis[i]=1;
            temp[i]=1;
        }
    }
    if(cha!=0)
        return false;
    for(i=num;i>=1;i--)
        if(vis[i]==0)
            temp[i]=0;
    for(i=1;i<=num;i++)
        ans[i]=temp[i];
    if(flag1==1)
    {
        for(i=1;i<=num;i++)
            if(ans[i]==3)
                ans[i]=2;
    }
    if(flag2==1)
    {
        for(i=1;i<=num;i++)
        {
            if(ans[i]==0)
                ans[i]=1;
            else if(ans[i]==1)
                ans[i]=0;
        }
    }
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=0,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x,&y);
        flag1=0;
        flag2=0;
        if(x<0)
            flag1=1;
        if(y<0)
            flag2=1;
        x=abs(x);
        y=abs(y);
        int tot=0;
        for(i=0;i<=10000;i++)
            if((i*(i+1)/2-x-y>=0)&&((i*(i+1)/2-x-y)%2==0)&&((i*(i+1)/2-x-y)/2<=i))
                fuck[tot++]=i;
        int low=-1,high=tot,mid,cao;
        while(low<high-1)
        {
            mid=(low+high)/2;
            cao=fuck[mid];
            if(check(cao))
                high=mid;
            else
                low=mid;
        }
        printf("Case #%d: ",++cas);
        for(i=1;i<=fuck[high];i++)
        {
            if(ans[i]==0)
                printf("N");
            else if(ans[i]==1)
                printf("S");
            else if(ans[i]==2)
                printf("W");
            else
                printf("E");
        }
        printf("\n");
    }
    return 0;
}
