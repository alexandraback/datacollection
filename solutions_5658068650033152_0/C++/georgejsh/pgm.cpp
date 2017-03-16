#include<stdio.h>
#define MAX 1000000007
int main()
{
 int t;
 int i,j,k,n,m,res,l;
 for(scanf("%d",&t),i=0;i<t;i++)
 {
  printf("Case #%d: ",i+1);
  scanf("%d%d%d",&n,&m,&k);
  if(m<n)
   l=m,m=n,n=l;
  j=(n-2)*(m-2);
  if(j<=0)
   printf("%d\n",k);
  else
  {
   res=0;
   for(l=1;l<=j;)

	{

	if(l==1)
	  res=4,l++;
	 else if(l<=m-2)
	  res+=2,l++;
	 else if(l%(m-2)==0)
	  res++,l++;
	 else if(l%(m-2)==1)
	  res++,l++;
	 else
	  l++;
if(l+res>=k)
 break;
	  }
	  //printf("%d",res);
k=k-res-l+1;
    res+=k;
   printf("%d\n",res);
  }
  
 }
 return 0;
}