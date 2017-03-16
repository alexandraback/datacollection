#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int rcd[105],num[105],s[105];
int main()
{
      freopen("a.in","r",stdin);
      freopen("a.out","w",stdout);
      int T,n,a,b;
      double L,R,m,ss,ans,x; 
      scanf("%d",&T);
      for(int cas=1;cas<=T;cas++)
      {
			 	    scanf("%d",&n);
		 	      printf("Case #%d:",cas);
			 	  //  memset(num,0,sizeof(num));
			 	//    memset(rcd,0,sizeof(rcd));
			 	    s[0]=0;
			 	    for(int i=1;i<=n;i++)
					  {
		            scanf("%d",&s[i]);
					      s[0]+=s[i]; 
					  }
					//  for(int i=1;i<=100;i++){rcd[i]+=rcd[i-1];num[i]+=num[i-1];}
						for(int i=1;i<=n;i++) 			
						{
	 			          L=0.0,R=100.0;ans=100;
	 			          
								 	while(L<R)	 
								 	{
									 	   m=(L+R)/2;
										   x=m/100*s[0]+s[i];
									     a=0;
											 b=0;
											 for(int j=1;j<=n;j++)
											 if(i!=j&&s[j]<=x){a+=s[j];b++;}
											 if(b==0){L=m+1e-8;continue;}
									     ss=((double)s[0]*(1-m/100.0)+a)/double(b);
									     if(ss-x>1e-8)L=m+1e-8;
									     else {ans=m;R=m-1e-8;}
								    								
						       }
							 		 printf(" %.6lf",ans+1e-8);	 
										 
						 				 
										 
					  }
			 				 puts("");
							 
      }


      return 0;
}
