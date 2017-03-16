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
#define MAX  130
#define sz size()
typedef long long ll ;
typedef pair<int,int> PII ;
const double eps=1e-8;
const double pi=acos(-1.0);

int p[MAX];
int a[MAX][MAX];

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T,cas=1;
    cin>>T;
    while(T--)
    {
        int n ;
        ll m ;
        cin>>n>>m ;
        ll Max=(1LL<<(n-2));
        //cout<<Max<<endl;
        if(m<=Max)
        {
            printf("Case #%d: POSSIBLE\n",cas++);
            memset(a,0,sizeof(a));
            if(m==1)
                a[1][n]=1;
            else
            {
                int k=0;
                ll sum=1;
                while(sum<m)
                {
                    sum+=(1LL<<k);
                    k++;
                }
                k--;
                for(int i=n-k-1;i<=n;i++)
                {
                    for(int j=i+1;j<=n;j++)
                        a[i][j]=1;
                }
                for(int i=n-k-1;i<=n;i++)
                {
                    ll now=1LL<<k;
                    if(m>=now)
                    {
                        m-=now;
                        a[1][i]=1;
                    }
                    if(m==0)  break ;
                    if(k!=0)  k--;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    printf("%d",a[i][j]);
                printf("\n");
            }
        }
        else
            printf("Case #%d: IMPOSSIBLE\n",cas++);
    }
    return 0 ;
}
