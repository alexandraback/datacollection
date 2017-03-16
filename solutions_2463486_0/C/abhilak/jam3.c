#include<stdio.h>
 
int count(int a)
{
        if(a>=484) return 5;
        else if(a>=121) return 4;
        else if(a>=9) return 3;
        else if(a>=4) return 2;
        else if(a>=1) return 1;
        else return 0;
}
 
int main()
{
        int t,testcase,a,b;
        scanf("%d",&testcase);
        for(t=1;t<=testcase;t++)
        {
                scanf("%d%d",&a,&b);
                printf("Case #%d: %d\n",t,count(b)-count(a-1));
        }
return 0;
 
}
