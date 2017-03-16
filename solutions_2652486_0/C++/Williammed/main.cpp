#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

int n,m,r,k,Max;
int s[100],num[100],ans[100],s2[100];
struct Q
{
    set<int> value;
}dp[10][10][10];
set<int>::iterator iter;

void gen_data(int depth,int val)
{
    if(depth==3)
    {
        dp[s[0]][s[1]][s[2]].value.insert(val);
        return;
    }
    gen_data(depth+1,val);
    gen_data(depth+1,val*s[depth]);
}
void DFS(int depth)
{
    if(depth==3)
    {
        gen_data(0,1);
        return;
    }
    for(int i=2;i<=5;i++)
    {
        s[depth]=i;
        DFS(depth+1);
    }
}
void Find(int depth)
{
    if(depth==n)
    {
        int tmp=0;
        for(int i=0;i<k;i++)
        {
            iter=dp[s[0]][s[1]][s[2]].value.find(num[i]);
            if(iter!=dp[s[0]][s[1]][s[2]].value.end())
               tmp++;
        }
        if(tmp>Max)
        {
            Max=tmp;
            for(int i=0;i<n;i++)
               ans[i]=s[i];
        }
        return;
    }
    for(int i=2;i<=m;i++)
    {
        s[depth]=i;
        Find(depth+1);
    }
}
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    int cas,t=1;

    DFS(0);
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #%d:\n",t++);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<k;j++)
               scanf("%d",&num[j]);
            Max=0;
            Find(0);
            for(int i=0;i<n;i++)
               printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
