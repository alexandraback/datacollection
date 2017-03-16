#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;
void getPQ(long long &P,long long &Q,string str)
{
	long long num=0;
	//str+='/';
	for(int i=0;i<str.length();i++)
	{
		if(str[i]!='/')
			num=num*10+str[i]-'0';
		else
		{
			P=num;
			num=0;
		}
	}
	Q=num;
}
long long GCD(long long a,long long b)
{
	if(b==0) return a;
	return GCD(b,a%b);
}
bool getN(long long data,long long& N)
{
	N=0;
	long long mode=0;
	while(data!=1)
	{
		mode=data%2;
		if(mode==1) return false;
		data=data>>1;
		N++;
	}
	return true;
}
long long getN2(long long data)
{
	long long res=0;
//	int temp=data>>1;
	while(data>1)
	{
		data=data>>1;
		res++;
	}
	return res;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	long long P,Q;
	long long gcdpq;
	long long res=0;
	cin>>T;
	string str;
	getline(cin,str);
	for(int t=0;t<T;t++)
	{
		getline(cin,str);
		getPQ(P,Q,str);
		gcdpq=GCD(P,Q);
		P=P/gcdpq;
		Q=Q/gcdpq;
		if(getN(Q,res))
		{
			res=res-getN2(P);
			cout<<"Case #"<<t+1<<": "<<res<<endl;
		}
		else
		{
			cout<<"Case #"<<t+1<<": impossible"<<endl;
		}
	}
	return 0;
}