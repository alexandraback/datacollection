#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
int n,m;
int adj[10][10],jum[10];
int way[10];
//int dp(int idx)
//{
//    int i;
//    if(idx==n-1)
//    {
//        return 1;
//    }
//    int sum=0;
//    for(i=idx+1;i<n;i++)
//    {
//        if(adj[idx][i])
//        {
//            sum+=dp(i);
//        }
//    }
//    return jum[idx]=sum;
//}
int yh=0;
void gen(int idx)
{
    int i,j;
    if(idx>=n*n)
    {
        memset(jum,-1,sizeof jum);
        if(way[n-1]==m)
        {
            printf("POSSIBLE\n");
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(adj[i][j])
                        printf("1");
                    else
                        printf("0");
                }
                printf("\n");
            }
            yh=1;
        }
        return;
    }
    adj[idx/n][idx%n]=0;
    gen(idx+1);
    if(yh)return;
    if(idx%n>idx/n&&idx/n!=n-1)
    {
        way[idx%n]+=way[idx/n];
        if(way[idx%n]<=m)
        {
            adj[idx/n][idx%n]=1;
            gen(idx+1);
        }
        way[idx%n]-=way[idx/n];
    }
    return;
}
int main()
{
    int t,T,i,j,k;
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        yh=0;
        memset(adj,0,sizeof adj);
        memset(way,0,sizeof way);
        scanf("%d %d",&n,&m);
        printf("Case #%d: ",t);
        way[0]=1;
        gen(0);
        if(yh==0)
        {
            printf("IMPOSSIBLE\n");
        }
    }
}


