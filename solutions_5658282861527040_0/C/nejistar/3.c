# include <stdio.h>

int main()
{
freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
int t,a,b,k,i,j,count,s;
scanf("%d",&t);
for(s=1;s<=t;s++)
{
count=0;
printf("Case #%d: ",s);
scanf("%d%d%d",&a,&b,&k);
for(i=0;i<a;i++)
{
for(j=0;j<b;j++)
{
if((i&j)<k)
count++;
}}
printf("%d\n",count);
}
return 0;
}
