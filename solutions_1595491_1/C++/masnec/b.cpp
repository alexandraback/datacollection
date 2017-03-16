#include<stdio.h>
#include<string.h>

int main()
{

    int cas;
    int N,S,P;
    int data;
    int res,res_poten,opt_poten,special,res_real;
    scanf("%d",&cas);
    for(int i=1;i<=cas;++i)
    {
        res=special=res_poten=opt_poten=res_real=0;
        scanf("%d %d %d",&N,&S,&P);

        for(int j=0;j<N;++j)
        {
            scanf("%d",&data);
            if(data>=2)
            {
                if((data+2)/3>=P)
                    res++;
                else if((data+4)/3>=P)
                    res_poten++;
                else
                    opt_poten++;
            }
            else if(data>=P)
                res_real++;
        }

        if(special<S)
        {
            if(res_poten>=(S-special))
            {
                res_real+=(S-special);
                S=special;
            }
            else
            {
                special+=res_poten;
                res_real+=res_poten;
            }
        }
        if(special<S)
        {
            if(opt_poten>=(S-special))
            {
                S=special;
            }
            else
            {
                special+=opt_poten;
            }
        }
        res+=res_real;
        if(res<0)
            res=0;

        printf("Case #%d: %d",i,res);
        if(i<cas)
            printf("\n");
    }
    return 0;
}
