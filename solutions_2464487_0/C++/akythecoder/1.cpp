#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdlib>

using namespace std;

int main()
{

int t1=0;
cin>>t1;
long long n1=1;
long long r,l;
long long lim=0;

while(n1<=t1)
{
	cin>>r>>l;
	long long count=0;
	for(long long i=0;;i+=2)
	{
		lim=(r+i+1)*(r+i+1)-(r+i)*(r+i);
		l=l-lim;
		if(l>=0)count++;
		else break;
	}
	cout<<"Case #"<<n1<<":"<<" "<<count<<endl;
	n1++;
}
return 0;
}