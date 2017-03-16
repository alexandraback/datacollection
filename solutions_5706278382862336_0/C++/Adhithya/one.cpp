#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	if (b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main() {
	// your code goes here
	long long p,q;
	int t,i,b=1;
	string s,ps,qs;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",b++);
		cin >> s;
		int si=s.size();
		for(i=0;i<si;i++)
		{
			if(s[i]=='/')
			break;
		}
		ps=s.substr(0,i);
		qs=s.substr(i+1,si-i-1);
		p=atoll(ps.c_str());
		q=atoll(qs.c_str());
		long long gc=gcd(p,q);
		p/=gc;
		q/=gc;
		long long x=1;
		long long o=0;
		while(x<q)
		{x*=2;o++;}
		if(x!=q)
		printf("impossible\n");
		else
		{
			x=0;
			long long z=0;
			while(x<p)
			x+=pow(2,z++);
			printf("%lld\n",o-z+1);
		}
	}
	return 0;
}
