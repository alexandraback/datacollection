#include <cstdio>
#define ll (long long)
int c,n,mx,ans,T,q,i;
int v[110];

long long val;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&T);

    for (q=1;q<=T;q++)
    {
        scanf("%d%d%d",&c,&n,&mx);

        val = 1;
        ans = 0;

        for (i=1;i<=n;i++)
            scanf("%d",&v[i]);

        for (i=1;val<=mx;)
        {
            if (i<=n)
            {
                while (val<v[i])
                {
                    ans++;
                    val =ll val+ll val*c;
                }
                val =ll val+ll v[i]*c;
                i++;
            }
            else
            {
                while (val<=mx)
                {
                     ans++;
                     val =ll val+ll val*c;
                }
            }
        }

        printf("Case #%d: %d\n",q,ans);
    }


    return 0;
}
