#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<time.h>
#include<cmath>
#include<vector>
#include <iomanip>
#define PB(u)  push_back(u);
#define AA   first
#define BB   second
#define inf 0x3f3f3f3f
using namespace std ;
#define MAX  10030
#define sz size()
typedef long long ll ;
typedef pair<int,int> PII ;
const double eps=1e-8;
const double pi=acos(-1.0);

int a[12][12][12];

int x[MAX],y[MAX],z[MAX];

int main()
{
   freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T,cas=1;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int n,m,q,Max;
        cin>>n>>m>>q>>Max;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=1;k<=q;k++)
                {
                    bool ok=true;
                    if(a[i][j][k])
                        ok=false ;
                    int sum=0;
                    for(int l=1;l<=q;l++)
                    {
                        if(a[i][j][l])
                            sum++;
                    }
                    if(sum>=Max)  ok=false ;
                    sum=0;
                    for(int l=1;l<=n;l++)
                    {
                        if(a[l][j][k])
                            sum++;
                    }
                    if(sum>=Max)  ok=false ;
                    sum=0;
                    for(int l=1;l<=m;l++)
                    {
                        if(a[i][l][k])
                            sum++;
                    }
                    if(sum>=Max)  ok=false ;
                    if(ok)
                    {
                        a[i][j][k]=1;
                        x[cnt]=i;
                        y[cnt]=j;
                        z[cnt]=k;
                        cnt++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",cas++,cnt);
        for(int i=0;i<cnt;i++)
        {
            printf("%d %d %d\n",x[i],y[i],z[i]);
        }
    }
    return 0 ;
}
