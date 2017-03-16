#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int p[1005],d;
int f()
{
	int m=0;
	for(int i=1000;i>=1;i--)
	{
		if(p[i]>0)
		{
			m=i;
			break;
		}
	}
	if(m<=3)
		return m;
	int c=p[m],ret=100000;
	for(int i=1;i<m;i++)
	{
		p[m]=0;
		p[i]+=c;
		p[m-i]+=c;
		ret=min(ret,c+f());
		p[i]-=c;
		p[m-i]-=c;
		p[m]=c;
	}
	return min(m,ret);
}
int main()
{
	freopen ("input.in","r",stdin);
	freopen ("output.txt","w",stdout);
	int t;
	cin>>t;
	int k=0;
	while(t--)
	{
		int ans=0,x;
		k++;
		cin>>d;
		memset(p,0,sizeof(p));
		for(int i=0;i<d;i++)
		{
			cin>>x;
			p[x]++;
		}
		ans=f();
		cout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}