#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int a[1000]={0},t;
cin>>t;
	for (int i=0;i<t;i++)
	{
	int dummy;
	cin>>dummy;
	string l;
	cin>>l;
		for (int j=0;j<l.length();j++)
		{
		a[j]=l[j]-'0';
		}
		int friends=0,ovators=0;
		for (int j=0;j<=l.length();j++)
		{
			if(a[j]==0) continue;
			if (j>ovators){friends+=j-ovators;ovators=j;}
			ovators+=a[j];
		}
		cout<<"Case #"<<i+1<<": "<<friends<<"\n";
	}
}