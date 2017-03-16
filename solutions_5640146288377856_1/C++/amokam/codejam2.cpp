#include<stdio.h>
int main()
{
    int t,r,c,out,w,i,tmp;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&r,&c,&w);
        out=(c/w);
        out=(r-1)*out;
        tmp=(c/w);
        tmp--;
        if(c%w==0)
            tmp+=w;
        else
            tmp+=w+1;
        out=out+tmp;

        printf("Case #%d: %d\n",i,out);
    }
    return 0;
}
