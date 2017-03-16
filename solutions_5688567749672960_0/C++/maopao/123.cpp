#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int n;
int num[10001005];
//void dfs(int x,int ans)
//{
//    if(x==n)
//    {
//        res=min(res,ans);
//        return ;
//    }
//    int tnum[11],pos=0;
//    int t=x;
//    while(t)
//    {
//        tnum[pos++]=t%10;
//        t/=10;
//    }
//    int xx=0;
//    for(int i=0;i<pos;i++)
//    {
//        xx=10*xx+tnum[i];
//    }
//    if(xx>=10&&xx>x&&xx<n)
//    dfs(xx,ans+1);
//
//    dfs(x+1,ans+1);
//}
int fan(int x)
{
    int tnum[11],pos=0;
    int t=x;
    while(t)
    {
        tnum[pos++]=t%10;
        t/=10;
    }
    int xx=0;
    for(int i=0; i<pos; i++)
    {
        xx=10*xx+tnum[i];
    }
    return xx;
}

int main()
{
    for(int i=1; i<1000005; i++)
        num[i]=9999999;
    num[0]=0;
    for(int i=1; i<1000005; i++)
    {
        if(i%10==0)
            num[i]=num[i-1]+1;
        else
        {
            int tnum=fan(i);
//            num[i]=num[i-1];
            num[i]=min(num[i-1]+1,num[tnum]+1);
        }
//        printf("%d %d\n",i,num[i]);
    }
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
//        res=9999999;
        scanf("%d",&n);
//        dfs(1,0);
        printf("Case #%d: %d\n",cas,num[n]);
    }
    return 0;
}
