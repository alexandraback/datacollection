#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;
void getPQ(int &P,int &Q,string str)
{
	int num=0;
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
int GCD(int a,int b)
{
	if(b==0) return a;
	return GCD(b,a%b);
}
bool getN(int data,int& N)
{
	N=0;
	int mode=0;
	while(data!=1)
	{
		mode=data%2;
		if(mode==1) return false;
		data=data>>1;
		N++;
	}
	return true;
}
int getN2(int data)
{
	int res=0;
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
	freopen("A-small-attempt0.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	int P,Q;
	int gcdpq;
	int res=0;
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