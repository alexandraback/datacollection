#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long need[50],i,ax[50],T,n,n1,r,a[1000],z,ans,t1,fix[1000005],k1,k2,k;


long long rev(long long z)
{
	long long ret=0; r=0;
	while (z>0)
	 {
	 	r++;
	 	a[r]=z%10;
	 	z/=10;
	 } 
	 
	 for (i=1;i<=r;i++)
	  ret=ret*10+a[i];
	  return ret;
}


main()
{
	 freopen ("input.txt","r",stdin);	 freopen ("output.txt","w",stdout);
	 
     cin>>T; t1=T;

  for (k=1;k<=1000000;k++)
   {	
	if (k<=19) {fix[k]=k; continue;}
	 
	k1=fix[k-1]+1;
	if (k%10==0) {fix[k]=k1; continue;}
	
	if (rev(k)>=k)  {fix[k]=k1; continue;}
	
	k2=fix[rev(k)]+1;
	
	 fix[k]=min(k1,k2);
   }
   
     while (T--)
      {
	    cin>>n;
	       
	       cout<<"Case #"<<t1-T<<": "<<fix[n]<<endl;
      }
        
	
}
