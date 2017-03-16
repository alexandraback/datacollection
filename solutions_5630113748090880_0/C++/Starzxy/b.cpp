#include<cstdio>
#include<bitset>

using namespace std;

int T;
int n;
bitset<2510>v;

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        v.reset();
        for(int i=1;i<=n*2-1;i++)
            for(int j=1;j<=n;j++)
            {
                int temp;
                scanf("%d",&temp);
                v.flip(temp);
            }

        printf("Case #%d:",t);
        for(int i=1;i<=2500;i++)
            if(v.test(i))
                printf(" %d",i);
        printf("\n");
    }
    return 0;
}
