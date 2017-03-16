#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
    int t;
	scanf("%d",&t);
	int i;
	for(i=1;i<=t;i++)
	{
       double c,f,x;
	   scanf("%lf %lf %lf",&c,&f,&x);
	   
	   double prod=2.0;
	   double curt=0.0;
	   double mtime=curt+x/prod;
	   bool flag=true;
	   
	   while(flag)
	   {
	      if(curt>mtime)
			  flag=false;
		  else
		  {
		     double t=curt+x/prod;
			 mtime=mtime>t?t:mtime;
			 
			 curt+=c/prod;
			 prod+=f;
		  }
	   }
        
		   printf("Case #%d: %.7lf\n",i,mtime);
	}
    return 0;
}