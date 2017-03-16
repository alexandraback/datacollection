#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int p[1005][1005];
int v[1005];
bool flag=false;
int n;
void dfs(int k)
{
    if(flag==true) return ;
    v[k]=1;
    for(int i=0;i<n;i++)
    if(p[k][i]!=-1)
    {
        if(v[i]==1)
        {
            flag=1;
            break;
        }
        dfs(i);
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,d,i,j,x,k;
    string s,s2,s1;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        flag=false;
        printf("Case #%d: ",cas);
        memset(p,-1,sizeof(p));
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&d);
            for(j=0; j<d; j++)
            {
                scanf("%d",&x);
                x--;
                p[i][x]=1;

            }
        }
        for(i=0;i<n;i++)
        {
            memset(v,0,sizeof(v));
            dfs(i);
            if(flag==true) break;
        }
        if(flag==true)
            puts("Yes");
        else puts("No");
    }
    return 0;
}
