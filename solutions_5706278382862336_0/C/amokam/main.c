#include<stdio.h>
int main()
{
    unsigned long long int p,q;
    int gens,gencount,t,i,flag;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        gens=0;
        gencount=0;
        flag=0;
        scanf("%llu/%llu",&p,&q);
        while(p<q && gens<=40)
        {
            if(p==0)
            {
                flag=1;
                break;
            }
            else
            {
                if(q%2!=0)
                {
                    flag=1;
                    break;
                }
                else
                {
                    q=q/2;
                    gens++;
                }
            }
        }
        gencount=gens;
        if(flag==0)
        {
            p=p-q;
            while(p<q && gencount<=40)
            {
                if(p==0)
                {
                    break;
                }
                else
                {
                    if(q%2!=0)
                    {
                        flag=1;
                        break;
                    }
                    else
                    {
                        q=q/2;
                        gencount++;
                        if(p>q)
                        {
                            p=p-q;
                        }
                    }
                }
            }
        }
        if(flag==1 || gencount>40)
        {
            printf("Case #%d: impossible\n",i);
        }
        else
        {
            printf("Case #%d: %d\n",i,gens);
        }
    }
    return(0);
}
