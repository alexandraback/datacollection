#include <cstdio>
#include <algorithm>

using namespace std;

long long put[20],put1[20],d[20];
int v[20],cif[20],din[1000010];

void brut()
{
    din[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(i==10000)
        {
            i=10000;
        }
        int nr=0,x=0;
        for(int j=i;j;j/=10) cif[++nr]=j%10;
        for(int j=1;j<=nr;j++) x=x*10+cif[j];
        if(x<i && i%10) din[i]=1+min(din[i-1],din[x]);
        else din[i]=din[i-1]+1;
    }
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    //brut();
    put[0]=1;
    for(int i=1;i<=16;i++)
    {
        put[i]=put[i-1]*10;
        put1[i]=put1[i-1]*10+9;
    }
    d[1]=9;
    for(int i=2;i<=16;i++) d[i]=put1[(i+1)/2]+put1[i/2]+1+d[i-1];
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int nr=0;
        long long n,n1,sol=0,ncop;
        scanf("%lld",&n);
        ncop=n;
        if(n<=20) sol=n;
        else
        {
            if(n%10==0)
            {
                sol=1;
                n--;
            }
            n1=n;
            for(;n1;n1/=10) v[++nr]=n1%10;
            for(int i=(nr+1)/2+1;i<=nr;i++) n1=n1*10+v[i];
            if(n1==1) sol--;
            sol+=n%put[(nr+1)/2]+n1+1+d[nr-1];
        }
        printf("Case #%d: %lld\n",t,sol);
    }
    return 0;
}
