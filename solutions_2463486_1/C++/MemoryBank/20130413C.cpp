#include <fstream>
#include <iostream>

using namespace std;

const long long maxd=20;

long long a[10000],s[10000];
long long b[maxd],c[maxd],d[maxd];
long long t,tt,i,j,f,p,l,r,ans;

ifstream fin("C.in");
ofstream fout("C.txt");

	void test()
	{
		memset(c,0,sizeof(c));
		for(i=0;i<maxd;i++)
		for(j=0;j<maxd;j++)
			c[i+j]+=b[i]*b[j];
		f=1;
		for(i=0;i<maxd;i++)
			if(c[i]>=10)
				f=0;
		if(f)
		{
			a[p]=0;
			for(i=maxd-1;i>=0;i--)
				a[p]=a[p]*10+c[i];
			s[p]=0;
			for(i=maxd-1;i>=0;i--)
				s[p]=s[p]*10+b[i];
			p++;
		}
	}
	
	void search(long long dep)
	{
		if(dep>4)
			return;
		memset(b,0,sizeof(b));
		for(i=0;i<dep;i++)
			b[i]=d[i];
		for(i=dep;i<2*dep;i++)
			b[i]=b[2*dep-1-i];
		test();
		b[dep]=0;
		for(i=dep+1;i<=2*dep;i++)
			b[i]=b[2*dep-i];
		test();
		b[dep]=1;
		for(i=dep+1;i<=2*dep;i++)
			b[i]=b[2*dep-i];
		test();
		b[dep]=2;
		for(i=dep+1;i<=2*dep;i++)
			b[i]=b[2*dep-i];
		test();

		d[dep]=0;
		search(dep+1);
		d[dep]=1;
		search(dep+1);
		d[dep]=2;
		search(dep+1);
	}

int main()
{
	a[0]=1;s[0]=1;
	a[1]=4;s[1]=2;
	a[2]=9;s[2]=3;
	p=3;

	d[0]=1;
	search(1);
	memset(b,0,sizeof(b));
	d[0]=2;
	search(1);

	fin>>t;
	for(tt=1;tt<=t;tt++)
	{
		ans=0;
		fin>>l>>r;
		for(i=0;i<p;i++)
			if(l<=a[i] && a[i]<=r)
				ans++;
		fout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;
}