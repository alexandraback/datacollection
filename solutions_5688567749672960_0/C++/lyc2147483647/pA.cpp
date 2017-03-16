#include<cstdio>
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
typedef long long LL;
map<LL,LL>mymap;
map<LL,bool>calc;
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
		int a=0;
		while(x!=0) {a++;x/=10;}
		return a;
}
LL solve(LL x)
{
//		printf("QQ %lld\n",x);
		if(x<10) return x;
		if(mymap.count(x)>0) return mymap[x];
		LL b = reverse(x),a;
		if(R(b)!=R(x)||b>=x) a=1+solve(x-1);
		else a= 1+min(solve(x-1),solve(reverse(x)));
		mymap[x] = a;
		return a;
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
