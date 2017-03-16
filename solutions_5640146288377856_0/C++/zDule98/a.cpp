#include <cstdio>

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int wt = 1; wt <= t; wt++)
    {
        int r,c,w;
        scanf("%d %d %d",&r,&c,&w);
        int sol = 0;
        if (c % w == 0)
            sol = r*(c/w) +w-1;
        else
            sol = r*(c/w) +w;

        printf("Case #%d: %d\n",wt,sol);
    }

    return 0;
}
