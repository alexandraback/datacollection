// Round1C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "string"
#include "string.h"
#include "stdio.h"

using namespace std;

long long gcd(long long a, long long b)
{
	if(a<b) return gcd(b,a);
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		long long p,q;
		char ch;
		cin>>p>>ch>>q;
		int t=0;
		int s=0;
		if(p==0)
		{
			cout<<"Case #"<<tc+1<<": "<<"impossible"<<endl;
			continue;
		}
		long long r=gcd(p,q);
		q=q/r;
		p=p/r;
		while(q>1)
		{
			s++;
			if(q%2==1 && q>1)
			{
				t=-1;
				break;
			}
			q=q/2;
			if(p>=q)
			{
				t=s;
				while(q%2==0)
					q/=2;
				if(q!=1)
					t=-1;	
				break;
			}
		}
		if(t==-1)
		{
			cout<<"Case #"<<tc+1<<": "<<"impossible"<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": "<<t<<endl;
		}
	}
	return 0;
}