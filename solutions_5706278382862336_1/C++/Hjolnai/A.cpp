#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

pair<long long, long long> stripNums(string str)
{
	pair<long long, long long> a;
	a.first=0;
	a.second=0;
	char c=str[0];
	int l=0;
	while(c>='0'&&c<='9')
	{
		a.first*=10;
		a.first+=c-'0';
		l++;
		c=str[l];
	}
	l++;
	c=str[l];
	while(l<str.length())
	{
		a.second*=10;
		a.second+=c-'0';
		l++;
		c=str[l];
	}
	
	return a;
	
}
long long gcd(long long a, long long b)
{
	long long c;
	if(a>b)
	{
		c=b;
		b=a;
		a=c;
	}
	//now a<b
	if(a==0)
		return b;
	return gcd(a, b%a);
}
int main()
{
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
	{
		long long P, Q;
		string A;
		cin>>A;
		pair<long long, long long> tmp=stripNums(A);
		P=tmp.first;
		Q=tmp.second;
		long long g=gcd(P,Q);
		P/=g;
		Q/=g;
		bool isValid=false;
		long long k=1;
		for(int i=0; i<42; i++)
		{
			if(Q==k)
				isValid=true;
			k*=2;
		}
		if(!isValid)
		{
			cout<<"Case #"<<t+1<<": impossible"<<endl;
		}
		else{
			while(P>1)
			{
				P/=2;
				Q/=2;
			}
			k=1;
			int L=0;
			while(k<Q)
			{
				k*=2;
				L++;
			}
			cout<<"Case #"<<t+1<<": "<<L<<endl;
		}
	}
	
	return 0;
}