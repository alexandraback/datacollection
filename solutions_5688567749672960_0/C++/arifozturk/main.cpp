#include <cstdio>
#define NMAX 1000023
#define LMAX NMAX-23
int dyn[NMAX];
int t,n;
int op(int n)
{
    int nr=0;
    while(n!=0)
    {
        nr*=10;
        nr+=n%10;
        n/=10;
    }
    return nr;
}
int min(int a,int b)
{
    if(a>b) return b;
    return a;
}
int main()
{
    freopen ("input.in","r",stdin);
    freopen ("output.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=9;i++) dyn[i]=i;
    for(int i=10;i<=LMAX;i++) dyn[i]=NMAX;
    for(int i=9;i<LMAX;i++)
    {
        int num=op(i);
        dyn[i+1]=min(dyn[i]+1,dyn[i+1]);
        if(num>i)
        {
            dyn[num]=min(dyn[num],dyn[i]+1);
        }
    }
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",i,dyn[n]);
    }
}
