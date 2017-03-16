#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;


long long pw(long long a,long long n)
{
	long long i=1;
	if(n==0)
	return 1;
	while(n)
	{
		i*=n;
		n--;
	}
	return i;
}

string tar,key,sol;
long long tmp,i,l,k,n,cnt,mx;

void func()
{
	if (sol.size()==n)
	{
		tmp=0;
		for(i=0;i<n;i++)
		if(sol.substr(i,l)==tar)
		{++cnt;++tmp;}
		mx=max(mx, tmp);
		return;
	}
	for(i=0;i<k;i++)
	{
		sol+=key[i];
		func();
  		sol.erase(sol.size()-1);
	}
}



int main() 
{
	freopen("input.txt","r",stdin);
	freopen("outputB.txt","w",stdout);
	long long T,t,
	string s;
	cin>>T;
	for(t=0;t<T;t++)
	{
		cin>>k>>l>>n;
		cin>>key>>tar;
		cnt=mx=0;
		x=pw(k,n);
		func();
		cout<<cout<<"Case #"<<t+1<<": "<<setprecision(16)<<1.0*mx-1.0*cnt/(1.0*x)<<"\n";
	}
	return 0;
}
