#include <cstdio>

using namespace std;

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int n,k,s;
        scanf("%d%d%d",&n,&k,&s);
        if(k*s<n) printf("Case #%d: IMPOSSIBLE\n",t);
        else
        {
            printf("Case #%d:",t);
            for(int i=0;i<n;i+=k)
            {
                long long x=i;
                for(int j=1;j<k;j++)
                    if(i+j<n) x=x*n+i+j;
                    else x=x*n;
                printf(" %lld",x+1);
            }
            printf("\n");
        }
    }
    return 0;
}
