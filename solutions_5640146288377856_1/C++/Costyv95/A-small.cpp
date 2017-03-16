#include <cstdio>
int T,n,m,w;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&T);

    for (int i=1;i<=T;i++)
    {
        scanf("%d%d%d",&n,&m,&w);

        if (w==m)
        {
            printf("Case #%d: %d\n",i,m+n-1);
            continue;
        }

        if (w==1)
        {
            printf("Case #%d: %d\n",i,m*n);
        }
        else
        {
            int add = m/w -1;
            if (m%w == 0) add--;
            printf("Case #%d: %d\n",i,(w+1+add)*n);
        }
    }

    return 0;
}
