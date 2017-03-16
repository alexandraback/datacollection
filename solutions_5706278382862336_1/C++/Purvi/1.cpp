#include <iostream>
#include <stdio.h>
typedef long long int ll;
using namespace std;
ll gcd(ll a ,ll b)
{
   if(b==0)
   return a;
   else
   return gcd(b,a%b);

}


int main() {
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
	scanf("%d",&t);
	ll p,q,b,g,m,n;
	int ans,c=0,k=0;
	char ch;

	while(t--)
	{
	    k++;
		scanf("%lld %c %lld",&p,&ch,&q);
		if(p==0)
		ans=-1;
		else
		{
		c=0;
		g=gcd(p,q);
		m=p/g;
		n=q/g;
		b=n;
		while(b%2==0)
	   {
	   	 b/=2;
	   }
	   //cout<<b<<endl;
	   if(b!=1)
	   ans=-1;
	   else
	   {
	   	 while(m<n)
	   	 {
	   	 	n/=2;
	   	 	c++;
	   	 }
	   	 ans=c;
	   }
	   }
	   printf("Case #%d: ",k);
	   if(ans==-1)
	   printf("impossible\n");
	   else
	   printf("%d\n",ans);
	}
	return 0;
}
