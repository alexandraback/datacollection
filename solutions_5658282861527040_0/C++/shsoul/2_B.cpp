#include<stdio.h>
int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("B-small-attempt0 (1).out","w",stdout);
    int t,ca=1;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,k,i,j,p,num=0;
        scanf("%d %d %d",&a,&b,&k);
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if((i&j)<k)num++;
            }
        }
        printf("Case #%d: %d\n",ca++,num);
    }
}
