#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

long long trans(string x)
{
	int len=x.length();
	long long res=0;
	for(int i=len-1;i>=0;i--)
	{
		res+=pow(10.0,len-i-1+0.0)*(x[i]-'0');
	}
	return res;
}


long long ta=0,tb=0;

long long ttt(long long ta, long long tb)
{
	if (ta<tb)
	{
		long long t=ta;
		ta=tb;tb=t;
	}
	if (ta==tb) return ta;
	while(ta % tb !=0)
	{
		long long tt=ta % tb;
		ta=tb;tb=tt;
	}
	return tb;
}

bool is2r(long long x)
{
	while (x!=1)
	{
		if (x%2==1) return false;
		x/=2;
	}
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for(int id=1;id<T+1;id++)
	{
		string tmp;
		cin>>tmp;
		string a,b;
		int ff=0;
		for (int i = 0; i < tmp.length(); ++i)
		{
			if (ff==0 && tmp[i]!='/')
				{a=a+tmp[i];}
			else
			{
				if (tmp[i]=='/') 
				{
					ff=1;
				}
				else
				{
					b=b+tmp[i];
				}
			}
		}
		long long ta=trans(a),tb=trans(b);
		long long tr=ttt(ta,tb);
		ta /= tr; tb/=tr;
		// cout <<ta/tr<<' '<<tb/tr<<endl;
		// continue;
		if (!is2r(tb)) {cout <<"Case #"<<id<<": impossible"<<endl;continue;}
		int sum=0;
		while (ta<tb)
		{
			ta*=2;
			sum++;
		}
		cout <<"Case #"<<id<<": "<<sum<<endl;

	}
	return 0;
}