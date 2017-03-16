#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

long long need[50],i,ax[50],T,n,n1,r,a[1000],z,ans,t1;


main()
{
//	 freopen ("input.txt","r",stdin);	 freopen ("output.txt","w",stdout);
	 
	
	ax[0]=1;
	 for (i=1;i<=20;i++)
	  ax[i]=ax[i-1]*10;
	
	need[1]=1;
	need[2]=10;
	
	 for (i=3;i<=20;i++)
	  {
	    z=i-1;
	  	need[i]=need[i-1] + ax[(z+1)/2]-1 + 1 + ax[z- (z+1)/2 ] -1  + 1;
      }
	  
	
	 cin>>T; t1=T;
     while (T--)
      {
	    cin>>n;  r=0;
	    n1=n;
	      while (n1>0) { r++;a[r]=n1%10; n1/=10;  }
	      ans=need[r];
	      reverse(a+1,a+r+1);
	     
		 for (i=(r+2)/2;i<=r;i++) 
	       if (a[i]) break;
	        
			if (i<=r)
	         {
	            for (i=2;i<(r+2)/2;i++)
				 if (a[i]) break;
				 if (!( a[1]==1 && i>=(r+2)/2)  )
	         	 {
				   for (i=1;i<(r+2)/2;i++) 
	                ans+=ax[i-1] * a[i];
	                ans++;
	             }
	             
	             
	      for (i=r;i>=(r+2)/2;i--)
	       ans+=ax[r-i]*a[i];
	       
	              
			 } else
			 {
			   for (i=(r+2)/2-1;i>=1;i--)
			    if (a[i]) break;
				
				if (i>1 || a[i]>1)
				 {
				  if (i==1 && a[i]==2) ans--;
				 
				  ans+=ax[r-i];
				   a[i]--;
				   
		    	 for (i=1;i<=(r+2)/2;i++) 
	              ans+=ax[i-1] * a[i];
	              ans++;
	      		 	
				 }	
			 }
	       
	       if (n<=19) ans=n;
	       
	       
	       cout<<"Case #"<<t1-T<<": "<<ans<<endl;
      }
        
	
}
