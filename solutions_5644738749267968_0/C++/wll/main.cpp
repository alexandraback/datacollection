#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


int min(int a,int b)
{
	return a<b?a:b;
}

int comp(double a,double b)
{
	return a<b;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
    int t;
	scanf("%d",&t);
	int i; 
	for(i=1;i<=t;i++)
	{   
	   int n;
	   scanf("%d",&n);
       int j,k;
	   double a[1010];
	   double b[1010];
	   for(j=0;j<n;j++)
		   scanf("%lf",&a[j]);
       for(j=0;j<n;j++)
		   scanf("%lf",&b[j]);
       sort(a,a+n,comp);
	   sort(b,b+n,comp);
       j=n-1;
	   k=n-1;
	   int ans=0;
	   int war=0;
	   while(j>=0&&k>=0)
	   {
	      if(a[j]>b[k])
		  {
		     ans++;
			 j--;
			 k--;
		  }
		  else
		  {
		     k--;
		  }
	   }
	   j=n-1;
	   k=n-1;
	   while(j>=0&&k>=0)
	   {
	      if(b[j]>a[k])
		  {
		     war++;
			 j--;
			 k--;
		  }
		  else
		  {
		     k--;
		  }
	   }
	   war=n-war;
	printf("Case #%d: %d %d\n",i,ans,war);
	}
      return 0;
}