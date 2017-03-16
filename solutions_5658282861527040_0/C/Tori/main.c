#include <stdio.h>
#include <stdlib.h>

int main()
{

    int t,j;
    unsigned long int a,ai,b,bi,k,ki,count;

    scanf("%d",&t);
    getchar();

    for(j=0;j<t;j++)
    {
        scanf("%ld %ld %ld",&a,&b,&k);
        count = 0;
        for(ai=0;ai<a;ai++)
            for(bi=0;bi<b;bi++)
                for(ki=0;ki<k;ki++)
                if((ai&bi)==ki)count++;

        printf("Case #%d: %ld",j+1,count);
        if(j!=t-1)printf("\n");
    }
    return 0;
}
