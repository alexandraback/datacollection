#include <stdio.h>

int main()
{
    int t; 
    scanf("%d",&t);
    for(int ccnt=1; ccnt<=t; ++ccnt)
    {
        long long int p,q;
        int resp=-1;
        scanf("%lld/%lld",&p,&q);

        for(int i=0; i<40; ++i)
        {
            p=p<<1;
            if(p>=q)
            {
                p-=q;
                if(resp<0)
                    resp=i;
            }
        }

        printf("Case #%d: ",ccnt);
        if(p!=0)
            printf("impossible\n");
        else
            printf("%d\n", resp+1);
    }
    return 0;
}
