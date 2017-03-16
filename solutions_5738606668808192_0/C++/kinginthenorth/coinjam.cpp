#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long checkFactor(long long n)
{
	for(int i=2;i<=n/i;i++)
	{
		if(!(n%i))
			return i;
	}
	return 0;
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,j;
	cin>>t;
	cin>>n>>j;
	cout<<"Case #1:"<<endl;
	int i,count=0;
	for(int num=32769;count<50;num+=2)
	{
		int a[16];
		for(i=0;i<16;i++)
		{
			if(num&(1<<i))
			{
				a[i]=1;
			}
			else
			{
				a[i]=0;
			}
		}
		bool flag=true;
		int fact[11];
		long long base,w,x,f;
		for(base=2;base<=10;base++)
		{
			x=0,w=1;
			for(i=0;i<16;i++)
			{
				x+=(w*a[i]);
				w*=base;
			}
			f=checkFactor(x);
			if(!f)
			{
				flag=false;
				break;
			}
			fact[base]=f;
		}
		if(flag)
		{
			count++;
			for(i=15;i>=0;i--)
				cout<<a[i];
			cout<<" ";
			for(i=2;i<=10;i++)
				cout<<fact[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
