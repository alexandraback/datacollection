#include<bits/stdc++.h>
using namespace std;
const int L=16;
const long long Inf=1ll<<60;
int T,a[L]={},tot=0;
long long n,p[L]={1};
long long calc(int pos)
{
	int b[L]={};
	copy(a,a+L,b);
	long long s1=0,s2=0;
	for(int i=pos;i>=1;--i)
		s1=s1*10+b[i];
	if(s1==0)
	{
		s1+=p[pos];
		int tmp=pos;
		while(b[pos+1]==0)
			b[++pos]=9;
		--b[pos+1];
		pos=tmp;
	}
	for(int i=pos+1;i<=tot;++i)
		s2=s2*10+b[i];
	--s2;
	return s1+s2+bool(s2);
}
int main()
{	
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	for(int i=1;i<L;++i)
		p[i]=p[i-1]*10;
	cin>>T;
	for(int testcase=1;testcase<=T;++testcase)
	{
		tot=0;
		long long ans1=0,ans2=Inf;
		cin>>n;
		for(long long x=n; x; x/=10)
			a[++tot]=x%10;
		for(int i=1;i<tot;++i)
			ans1+=p[i/2]+p[(i+1)/2]-1;
		if(tot==1)
			ans1=a[1],ans2=0;
		else
			if(n==p[tot-1])
				ans2=0;
			else
				for(int i=1;i<tot;++i)
					ans2=min(ans2,calc(i));
		cout<<"Case #"<<testcase<<": "<<ans1+ans2<<endl;
	}
	return 0;
}
