#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define R 23
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
	freopen("C-large.in","r",stdin);
	freopen("output1.txt","w",stdout);
	int t,n,j;
	cin>>t;
	cin>>n>>j;
	cout<<"Case #1:"<<endl;
	int i,count=0;
	int ans[R][16];
	for(int num=32769;count<R;num+=2)
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
		if(flag&&(fact[2]==3 && fact[3]==2 && fact[4]==3 && fact[5]==2 && fact[6]==7 && fact[7]==2 && fact[8]==3 && fact[9]==2 && fact[10]==3))
		{
			for(i=15;i>=0;i--)
				ans[count][15-i]=a[i];
			count++;
		}
	}
	count=0;
	int k;
	for(i=0;count<500;i++)
	{
		for(j=0;(j<R&&count<500);j++)
		{
			for(k=0;k<16;k++)
				cout<<ans[i][k];
			for(k=0;k<16;k++)
				cout<<ans[j][k];
			cout<<" 3 2 3 2 7 2 3 2 3 "<<endl;
			count++;
		}
	}
	return 0;
}
