#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
typedef unsigned long long LL;
LL min(LL a,LL b){return a<b?a:b;}
LL reverse(LL x)
{
		LL ans=0;
		while(x!=0)
		{
			ans=ans*10+x%10;
			x=x/10;
		}
		return ans;
}
LL R(LL x)
{
		LL a=0;
		while(x!=0) {a++;x/=10;}
		return a;
}
LL pow(LL a)
{
		LL x=1;
		while(a--) x*=10;
		return x;
}
LL construct(LL x)
{
		LL r=R(x)/2;
		LL y=x;
		int t=0;
		while(t<r)
		{
			t++;
			y/=10;
		}
		LL z=x-y*pow(r);
		return pow(R(x)-1)+z;
}
LL solve(LL x)
{
		if(x<=19) return x;
		LL a=1,ans=1;
		LL digit=2,r=1;
		while(R(a)!=R(x)-1)
		{
				printf("a=%lld\n",a);
				if(a==-1) scanf(" ");
				LL b=pow(digit-1)+pow(r)-1;
				ans+=(b-a+1);
				a=reverse(b);
				if(digit%2==1) r++;
				digit++;
		}
		printf("a=%lld\n",a);
		LL ans1=ans+x-a;
		LL obj=construct(reverse(x));
		ans+=(obj-a+1);
		a=reverse(obj);
		printf("a=%lld\n",a);
		ans+=(x-a);
		if(ans1<ans) ans=ans1;
		return ans;
}
int main()
{
		FILE *in = fopen("in.txt","r");
		FILE *out = fopen("out.txt","w");
		int n,t=0;
		LL x;
		fscanf(in,"%d",&n);
		while(n--)
		{
			t++;
			fscanf(in,"%lld",&x);
			fprintf(out,"Case #%d: %lld\n",t,solve(x));
		}
}
