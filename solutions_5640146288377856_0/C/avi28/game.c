#include<stdio.h>
int main()
{
int t,c,r,w,ans,i;
scanf("%d",&t);
for(i=0;i<t;i++)
{
    scanf("%d %d %d",&r,&c,&w);
    if(w==c || w==1)
        ans=c;
    else if(c%w==0)
        ans=w+c/w-1;
    else
        ans=r*c/w+w;
printf("Case #%d: %d\n",i+1,ans);
}
return 0;
}
