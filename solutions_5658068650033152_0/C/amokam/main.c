#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,n,m,k,count,toremove;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        count=0;
        scanf("%d %d %d",&n,&m,&k);
 label1:    if(n==1 || m==1 || k==1 || k==2 || k==3 || k==4)
        {
            printf("Case #%d: %d\n",i,k);
        }
        else
        {
            toremove=(n*m)-k;
            if(toremove<=4)
            {
                count=2*(n+m-4) + 4 - toremove;
                printf("Case #%d: %d\n",i,count);
            }
            else
            {
                toremove=toremove-4;
                if(toremove%n==0)
                {
                    m-=(toremove/n);
                    goto label1;
                }
                else if(toremove%m==0)
                {
                    n-=(toremove/m);
                    goto label1;
                }
                else
                {
                    while(toremove%n!=0 && toremove%m!=0)
                    {
                        toremove--;
                        k++;
                    }
                    goto label1;
                }
            }
        }

    }
    return 0;
}
