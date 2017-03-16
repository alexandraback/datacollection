#include <stdio.h>
#include <string.h>
#include <stdlib.h>


long long int gcd(long long int u, long long int v) {
return (v != 0)?gcd(v, u%v):u;
}

int main()
{
	long long int a,b,m,n;
	    int i,t,j,k,fo;
    
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        fo=0;
        scanf("%lld/%lld",&a,&b);
        if(a>b)
            m=gcd(a,b);
        else
            m=gcd(b,a);
        a=a/m;
        b=b/m;
        n=1;
        k=0;
        while(n<b)
            n*=2;
        while(b>a)
        {
            a*=2;
            k++;
        }
        if(n==b)
            fo=1;
        if(fo==0)
            printf("Case #%d: impossible\n",i);
        else
            printf("Case #%d: %d\n",i,k);
    }
    return 0;
}
