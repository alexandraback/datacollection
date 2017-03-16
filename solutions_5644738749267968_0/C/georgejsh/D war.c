#include<stdio.h>
#define MAX 1000000007
int main()
{
 int t;
 double a[10],b[10],temp;
 int n,i,j,k,l;
 for(scanf("%d",&t),l=0;l<t;l++)
 {
  printf("Case #%d: ",l+1);
  scanf("%d",&n);
  for(i=0;i<n;i++)
   scanf("%lf",&a[i]);
  for(i=0;i<n;i++)
   scanf("%lf",&b[i]);
  for(i=0;i<n;i++)
   for(j=0;j<n-1;j++)
    if(a[j]>a[j+1])
	{
	 temp=a[j],a[j]=a[j+1],a[j+1]=temp;
	}
  for(i=0;i<n;i++)
   for(j=0;j<n-1;j++)
    if(b[j]>b[j+1])
	{
	 temp=b[j],b[j]=b[j+1],b[j+1]=temp;
	}
	
  for(i=0,j=0;i<n;i++)
  {
   k=0;
   for(;j<n;j++)
   {
    if(b[j]>a[i])
	{
	j++;
	k=1;
	break;
	}
   }
   if(j==n)
    break;
  }
  if(k)
   i++;
 // printf("%d\n\n",i);
  if(i==0)
   printf("%d %d\n",n-i,n-i);
  else if(n-i!=0)
  printf("%d %d\n",2*(n-i),n-i);
  else if(n>=2)
   printf("1 0\n");
  else if(n==1)
   printf("%d %d\n",2*(n-i),n-i);
 /* for(i=0;i<n;i++)
   printf("%lf ",a[i]);
  printf("\n");
 */ //for(i=0;i<n;i++)
  // printf("%lf ",b[i]);
  
 }
 return 0;
}