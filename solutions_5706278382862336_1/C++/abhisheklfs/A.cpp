#include <iostream>
#include <cstdio>
using namespace std;
long long int gcd(long long int a,long long int b)
{
 	 if(b<a)return gcd(b,a);
 	 if(a==0) return b;
 	 else return gcd(b%a,a);
}
bool check(long long int p)
{
 	 long long int x=1;
 	 while(p>=x)
 	 {
	  			if(x==p)return 1;
	  			x*=2;
	 }
	 return 0;
 }
int main()
{
 	freopen("in.txt","r",stdin);
 	freopen("out.txt","w",stdout);
 	
 	int tc;char ch;int co=1;
 	long long int p,q;
 	int res;
 	scanf("%d",&tc);
 	while(tc--)
 	{
  	 		  res=0;
  	 		  cin>>p>>ch>>q;
//	 		  scanf("%lld%lld",&p,&q); 
	 		  long long int g=gcd(p,q);
	 		  p/=g;
	 		  q/=g;
	 		  if(check(q))
	 		  {
			   				if(2*p>=q)
			   				{
							 		 res=1;
		 		 			}
		 		 			else
		 		 			{
							 	while(2*p<q)
							 	{
								 			res++;
								 			q/=2;
				 			 	}
				 			 	res+=1;
							}
							printf("Case #%d: %d\n",co++,res);
			  }
			  else
			  {
			   	  printf("Case #%d: impossible\n",co++);
			  }
  	}
}
