#include<stdio.h>
using namespace std;
int a[100][100];
void doit()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    if(n<65&&m>(1LL<<(n-2)))
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        a[i][j]=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++)
            a[i][j]=1;
    a[0][n-1]=1;
    int now=n-2;
    m-=1;
    while(m)
    {
        if(m%2 == 1)
        {
            a[0][now] = 1;
        }
        now--;
        m/=2;
    }
    printf("POSSIBLE\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d",a[i][j]);
        printf("\n");
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        doit();
    }
}
