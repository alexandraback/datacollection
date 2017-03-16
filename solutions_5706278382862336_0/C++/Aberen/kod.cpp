#include <iostream>
#include <cstdio>
#define LL long long 
using namespace std;
LL int gcd(LL int a,LL int b){ return (!a)?b:gcd(b%a,a);}
int main()
{
	LL int n;
	char ch;
	scanf(" %lld",&n);
	for(LL int i=1,a,b,y,c,s1,s2;i<=n;i++,y=0){
		scanf(" %lld%c%lld",&a,&ch,&b);
		printf("Case #%lld: ",i);
		if(a>b || b==0){
			puts("impossible");
			continue;
		}
		c=gcd(a,b);
		a/=c;b/=c;s1=0;
		for(int x=1;x<=b;x<<=1,s1++)
			if(x==b) y=1;
		if(!y){
			puts("impossible");
			continue;
		}
		s2=1;
		for(int x=1,say=1;x<=a;x<<=1,say++)
			if(a&x) s2=say;
		
		printf("%lld\n",s1-s2);
	}
	return 0;
}
