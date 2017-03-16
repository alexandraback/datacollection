#include <cstdio>
#include <iostream>
using namespace std;
long long ans[1000];
int num;
int T; 
long long a, b; 
int main()
{
	long long i;
	for (i=1;i<=10000000;++i)
	{
		long long j = i*i;
		int t=i; 
		int a[100], tot = 0;
		while (j!=0)
		{
			a[tot++]= j%10;
			j/=10;
		}
		bool pan = true;
		for (int k=0;k<tot/2;++k)
			if (a[k]!=a[tot-1-k])
				pan=false;
		tot=0;
		while (t!=0)
		{
			a[tot++]=t%10;
			t/=10;
		}
		for (int k=0;k<tot/2;++k)
			if (a[k]!=a[tot-1-k])
				pan=false;		
		if (pan)
			ans[num++]=i*i;
	}
	cin>>T;
	for (int I=1;I<=T;++I)
	{
		cin>>a>>b;
		int tans=0;
		for (int j=0;j<num;++j)
			if (ans[j]>=a && ans[j]<= b)
				++tans;
		printf("Case #%d: %d\n", I, tans);
	}
}
