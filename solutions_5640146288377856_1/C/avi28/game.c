#include<stdio.h>
int main()
{
int t,c,r,w,ans,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{
    scanf("%d %d %d",&r,&c,&w);
    if(w==c)
        ans=r-1+c;
    else if(w==1)
        ans=r*c;
    else if(c%w==0)
        ans=w+(r*(c/w))-1;
    else
        ans=r*(c/w)+w;
printf("Case #%d: %d\n",i+1,ans);
}
return 0;
}
