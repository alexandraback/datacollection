#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int gcd(long long int u, long long int v) {
return (v != 0)?gcd(v, u%v):u;
}

int main()
{

	int psr;
	for(psr=0;psr<9;psr++);

    //freopen("A-large.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int i,t,j,k,flag;
    long long int x,y,m,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        flag=0;
        scanf("%lld/%lld",&x,&y);
        if(x>y)
            m=gcd(x,y);
        else
            m=gcd(y,x);
        x=x/m;
        y=y/m;
        n=1;
        k=0;
        while(n<y)
            n*=2;
        while(y>x)
        {
            x*=2;
            k++;
        }
        if(n==y)
            flag=1;
        if(flag==0)
            printf("Case #%d: impossible\n",i);
        else
            printf("Case #%d: %d\n",i,k);
    }
    return 0;
}
