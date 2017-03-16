#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
int t,meg,n,i,k,b,a[1000001],cnt,p=1;
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&b,&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
sort(a,a+n);
meg=0;
for(i=0;i<n;i++)
if(a[i]<b)
b=b+a[i];
else
{
cnt=0;
k=b;
while(a[i]>=k)
{
k=k+(k-1);
cnt++;
if(cnt>n)
break;
}
if(n-i<=cnt)
{
meg+=(n-i);
break;
}
else
{
b=k+a[i];
meg+=cnt;
}
}
if(meg>n)
meg=n;
printf("Case #%d: %d\n",p,meg);p++;
}
return 0;
}
