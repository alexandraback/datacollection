// Round1B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "string.h"
#include "stdio.h"
#include "fstream"

using namespace std;
	
double C(int n, int k)
{
	double ans=1.0;
	for(int i=n;i>=n-k+1;i--)
	{
		ans*=i;
	}
	for(int i=1;i<=k;i++)
		ans/=i;
	return ans;
}

int main()
{
	C(2,2);
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N,X,Y;
		cin>>N>>X>>Y;
		int lv=(abs(X)+Y)/2+1;
		int r1=lv*(2*lv-1);
		lv--;
		int r2=lv*(2*lv-1);
		cout<<"Case #"<<tc+1<<": ";
		if(N>=r1)
		{
			cout<<"1.0"<<endl;
			continue;
		}
		else if(N<=r2)
		{
			cout<<"0.0"<<endl;
			continue;
		}
		else if(X==0)
		{
			if(N==r1)
				cout<<"1.0"<<endl;
			else
				cout<<"0.0"<<endl;
			continue;
		}
		int n=N-r2;
		int x=Y+1;
		double ans=0.0;
		double p=1.0;
		for(int i=0;i<n;i++)
			p*=0.5;
		for(int i=x;i<=n;i++)
		{
			ans+=p*C(n,i);
		}
		cout.precision(10);
		cout<<ans<<endl;
	}
	return 0;
}