#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
typedef long long LL;
const int mn=100,ml=20;
int f[mn][100];
int v[mn];
int n,E,R,tmp;
LL ans=0;
int main()
{
    int Q,T,i,j,k;
    scanf("%d",&Q);
    fo(T,1,Q)
    {
        scanf("%d%d%d",&E,&R,&n);
        fo(i,1,n)scanf("%d",v+i);
        f[0][E]=0;
        memset(f,0,sizeof f);
        fo(i,0,n-1)
            fo(j,0,E)
            {
                int top=min(j+R,E);
                fo(k,0,top)
                {
                    tmp=f[i][j]+k*v[i+1];
                    if(tmp>f[i+1][top-k])f[i+1][top-k]=tmp;
                }
            }
        int ans=0;
        fo(i,0,E)if(f[n][i]>ans)ans=f[n][i];
        printf("Case #%d: %d\n",T,ans);
    }
    return 0;
}
