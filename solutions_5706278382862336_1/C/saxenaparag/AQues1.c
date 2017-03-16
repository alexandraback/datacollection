#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int GreatestCommonDivisor(long long int A, long long int B) 
{
	return (B != 0)?GreatestCommonDivisor(B, A%B):A;
}

int main()
{
    int T,i=1,k,flag;
    long long int P,Q,m,n;
    scanf("%d",&T);
    while(T--)
    {
    	flag=0;
        scanf("%lld/%lld",&P,&Q);
        if(P>Q)
            m=GreatestCommonDivisor(P,Q);
        else
            m=GreatestCommonDivisor(Q,P);
        P=P/m;
        Q=Q/m;
        n=1;
        k=0;
        while(n<Q)
            n*=2;
        while(Q>P)
        {
            P*=2;
            k++;
        }
        if(n==Q)
            flag=1;
        if(flag==0)
            printf("Case #%d: impossible\n",i);
        else
            printf("Case #%d: %d\n",i,k);
        i++;
    }
    return 0;
}
