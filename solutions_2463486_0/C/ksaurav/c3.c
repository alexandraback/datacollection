#include<stdio.h>
 
int f(int a)
{
        if(a>=484) return 5;
        if(a>=121) return 4;
        if(a>=9) return 3;
        if(a>=4) return 2;
        if(a>=1) return 1;
        return 0;
}
 
int main()
{
        int t,test,a,b;
        scanf("%d",&test);
        for(t=1;t<=test;t++)
        {
                scanf("%d%d",&a,&b);
                printf("Case #%d: %d\n",t,f(b)-f(a-1));
        }
return 0;
 
}
