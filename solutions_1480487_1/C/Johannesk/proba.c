#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv)
{
    int t,i,n,j,s[300],x,nelem,nop;
    double per,target;

    assert (scanf("%d ",&t) == 1);
    for(i=1;i<=t;i++)
    {
        assert (scanf("%d ",&n) == 1);
        x=0;
        for(j=0;j<n;j++)
        {
            assert (scanf("%d ",&s[j]) == 1);
            x=x+s[j];
        }
        target=(double)(2*x)/n;
        nelem=0;
        nop=0;
        for(j=0;j<n;j++)
        {
            if(s[j]<target)
            {
                nelem++;
            }
            else
            {
                nop=nop+s[j];
            }
        }  
        target=(double)(2*x-nop)/nelem;
        printf("Case #%d: ",i,target);
        for(j=0;j<n;j++)
        {
            per=(target-s[j])/x;
            per=per*100;
            if(s[j]<target)
                printf("%f ",per);
            else
                printf("0.000000 ");
        }
        printf("\n");
    }
    return 0;
}
