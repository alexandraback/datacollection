#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100][100];
void full_connect(int top)
{
    for (int i=1;i<=top-1;++i)
        for (int j=i+1;j<=top;++j)
            a[i][j]=1;
}
void outp(int b)
{
    for (int i=1;i<=b;++i)
    {
        for (int j=1;j<=b;++j)
            printf("%d",a[i][j]);
        if (i<b) printf("\n");
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int testcases;
    scanf("%d",&testcases);
    for (int ii=1;ii<=testcases;++ii)
    {
        int b;
        long long m;
        scanf("%d%lld",&b,&m);
        printf("Case #%d: ",ii);
        if (log(m)/log(2)>b-2) printf("IMPOSSIBLE");
        else
        {
            printf("POSSIBLE\n");
            memset(a,0,sizeof(a));
            long long i,j;
            for (i=1,j=0;i>0 && i<=m;i*=2,j++);
            // 2^j=i>m
            bool flag=false;
            for (int k=j;k>=0;--k)
                if (m&(1LL<<k))
                {
                    if (!flag)
                    {
                        full_connect(k+2);
                        flag=true;
                    }
                    if (k+2!=b) a[k+2][b]=1;
                }
            outp(b);
        }
        if (ii<testcases) printf("\n");
    }
    return 0;
}
