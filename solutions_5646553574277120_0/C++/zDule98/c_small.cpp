#include <cstdio>
using namespace std;

int a[1000];

int main()
{
    int t;
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    for(int wt = 1; wt <= t; wt++)
    {
        int c1,d,v;
        scanf("%d %d %d",&c1,&d,&v);
        long long c= c1;
        for(int i = 0; i < d; i++)
            scanf("%d",&a[i]);
        long long tren = 0;
        a[d] = 1000000001;
        int uzet = 0;
        int sol = 0;
        while(tren < v)
        {
           // printf("%d\n",uzet);
            if (tren >= a[uzet]-1)
                tren += c*a[uzet++];
            else
            {
                tren += c*(tren+1);
                sol++;
            }
        }
        printf("Case #%d: %d\n",wt,sol);
    }

    return 0;
}
