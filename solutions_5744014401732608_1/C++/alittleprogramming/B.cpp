//OUM HARI OUM, OUM TATSAT
// OUM NAMA VAGABATE BASUDEBAY
// OUM NAMA MA SWARASATI OUM NAMA

#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

#define cl(vctr) vctr.clear()
#define ms(v, ar) memset(ar, v, sizeof(ar))

const double pi=(double)(2.0 * acos( 0.0 ));
const int inf=1 << 30;
const double eps=1E-9;
const double e = exp(1.0);
const int sz=100000 + 5;
const int mod=1000000000 + 7;

using namespace std;
typedef long long int ll;

ll ar[55][55],bt[55];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("Bout.in","w",stdout);
    int t,T;
    ll n,m,i,j,k,l,a;
    scanf("%d",&t);T=t;
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        printf("Case #%d: ",T-t);
        a=1ll<<(n-2);
        if(m>a)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        ms(0,ar);
        if(m==a)
        {
            for(k=1;k<n;k++)
                {
                    for(l=k+1;l<=n;l++)
                        ar[k][l]=1;
                }

        }
        else
        {
            for(i=n-1,j=0;i>1;i--)
            {
                bt[j++]=i;
            }
            for(i=j-1;i>=0;i--)
            {
                if(m&(1ll<<i))
                {
                    ar[1][bt[i]]=1;
                    for(k=bt[i];k<n;k++)
                    {
                        for(l=k+1;l<=n;l++)
                            ar[k][l]=1;
                    }
                }
            }
        }
        for(k=1;k<=n;k++)
                {
                    for(l=1;l<=n;l++)
                    {
                            printf("%lld",ar[k][l]);
                    }
                        printf("\n");
                }
    }

    return 0;
}
