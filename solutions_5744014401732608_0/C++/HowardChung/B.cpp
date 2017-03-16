#include<stdio.h>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    freopen("B-small-attempt2.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);

    for(int C = 1; C <= T; C++)
    {
        ll n,m;
        scanf("%lld %lld",&n,&m);

        printf("Case #%d:",C);

        if( m > (1<<(n-2)) )
            printf(" IMPOSSIBLE\n");
        else
        {
            printf(" POSSIBLE\n");
            for(int i = 0; i < n; i++)
            {
                if ( i == 0 && m != (1<<(n-2)) )
                {
                    printf("0");
                    int pw = n-3;
                    for(int j = 0; j < n-2; j++)
                    {
                        printf("%d",(m&(1<<pw))== 0? 0 : 1);
                        pw--;
                    }

                    printf("0");
                }
                else
                {
                    for(int j = 0; j < n; j++)
                        printf("%d",j<=i? 0 : 1);
                }
                puts("");
            }
        }
    }
}
