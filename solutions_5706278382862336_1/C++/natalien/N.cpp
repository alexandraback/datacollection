#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
vector<unsigned long long> xar(41);
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	unsigned long long t;
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	unsigned long long m=1;
	bool ch;
	for(int i=0; i<41; i++)
	{
		xar[i]=m;
		m*=2;
	}
	int t;
	cin>>t;
	unsigned long long p,q;
	unsigned long long g;
	for(int s=0; s<t; s++)
	{
		scanf("%lld/%lld", &p,&q);
		g=gcd(q,p);
		q/=g;
		p/=g;
		ch=false;
		for(int i=0; i<41; i++)
		{
			if(q==xar[i])
			{
				ch=true;
				break;
			}
		}
		cout<<"Case #"<<s+1<<": ";
		if(!ch)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		if(p>=q/2)
		{
			cout<<1<<endl;
			continue;
		}
		double m=(double)q/(double)p;
		int ind;
		for(int i=0; i<41; i++)
		{
			if(xar[i]>=m)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	//system("pause");
	return 0;
}