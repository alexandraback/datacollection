#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const long long dubs[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,
32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,
1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776};

long long gcd(long long x,long long y)
{
    long long z;
    while ((x>0)&&(y>0))
    {
        if (x>y) x=x%y;
        else y=y%x;
    }
    return (x+y);
}

bool isDub(long long x)
{
    int j=0;
    while(dubs[j]<x) j++;
    if (dubs[j]==x) return true;
    else return false;
}

int degree(long long x)
{
    int j=0;
    while(dubs[j]<x) j++;
    return j;
}

int dubSmaller(long long x)
{
    if (dubs[degree(x)]==x) return degree(x);
    else return degree(x)-1;
}

int main()
{
    FILE *f,*fo;
    int j,i,t;
    static long long p,q,m[50],x;
    char c;

    f=fopen("input.txt","r");
    fo=fopen("output.txt","w");
    fscanf(f,"%d",&t);
    for(j=1;j<=t;j++)
    {
        fscanf(f,"%lld%c%lld",&p,&c,&q);
        x=gcd(p,q);
        p/=x;
        q/=x;
        if (!isDub(q)) fprintf(fo,"Case #%d: impossible\n",j);
        else fprintf(fo,"Case #%d: %d\n",j,degree(q)-dubSmaller(p));
    }
    return 0;
}
