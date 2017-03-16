#include<stdio.h>


int main()
{
int t,i,j,n,a[1000],b[1000],c[1000],s,min,ans,chk[1000],x=1,stars,count;
scanf("%d",&t);
while(t--)
{
printf("Case #%d: ",x);
x++;
s=stars=ans=0;
for(i=0;i<1000;i++)
 c[i]=chk[i]=0;
scanf("%d",&n);
for(i=0;i<n;i++)
 scanf("%d %d",&a[i],&b[i]);
while(1)
{
count=0;
for(i=0;i<1000;i++)
 c[i]=0;
for(i=0;i<n;i++)
 if(((a[i]<=stars)||(b[i]<=stars))&&chk[i]==0)
   c[i]=a[i]+b[i]+1;
for(i=0;i<1000;i++)
 if(c[i])
  break;
min=i;
for(i=0;i<1000;i++)
 {
  if(c[i])
   {
    if((a[min]+b[min])>(a[i]+b[i]))
     min=i;
   }
 }
if(b[min]<=stars)
 {
  stars+=2;
  chk[min]=1;
  ans++;
 }
else
 {
  stars++;
  ans++;
 }
//printf("stars=%d\n",stars);
count=0;
for(i=0;i<n;i++)
 if(chk[i]==1)
  count++;
if(count==n)
 {
  printf("%d\n",ans);
  break;
 }
for(i=0;i<1000;i++)
 if(c[i])
  count++;
//printf("count=%d\n",count);
if(count==0)
 {
  printf("Too Bad\n");
  break;
 }
}
if(count==0)
 continue;
}

return 0;
}
