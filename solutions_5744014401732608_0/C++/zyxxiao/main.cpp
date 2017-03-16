/*    brioso     */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;
#define MAX 1005
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

int n,m;
int ans;
int sum;

void dfs(int x){
}

int p[MAX];
int a[MAX][MAX];

int main()
{
    freopen("B-small-attempt0 (2).in","r",stdin);
    freopen("output.out","w",stdout);
    int T,cas=1;
    cin>>T;
    while(T--)
    {
        int n ;
        ll m ;
        cin>>n>>m ;
        ll Max=(1LL<<(n-2));
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
                int sd = 0;

                while(sum<m)
                {
                    sum+=(1LL<<k);
                    k++;
                    sd++;
                }
                k--;
                for(int i=n-k-1;i<=n;i++)
                {
                    for(int j=i+1;j<=n;j++)
                        a[i][j]=1;
                        sd--;
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
            dfs(1);
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
/*

unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：18446744073709551615

__int64的最大值：9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615

*/
