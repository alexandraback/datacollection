#include<stdio.h>
#include<stdlib.h>

int main()
{
    freopen("A-large.in","rt",stdin);
    freopen("output2.txt","wt",stdout);
    int t,j,r,c,w,var,ans;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        ans=0;
        scanf("%d %d %d",&r,&c,&w);
        var=c/w;
        var*=r;
        if(c%w==0)
            ans=var+w-1;
        else
            ans=var+w;

        printf("Case #%d: %d\n",j,ans);

    }
    return 0;
}
