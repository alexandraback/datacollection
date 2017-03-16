// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

bool f(__int64 a)
{
	while(a!=1){
		if(a%2==1)
			return 0;
		a/=2;
	}
	return 1;
}
__int64 m(__int64 p,__int64 q)
{
	while(q%p!=0){
		__int64 t=q%p;
		q=p;
		p=t;
	}
	return p;
}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("c:\\users\\admin\\desktop\\a.in","r",stdin);
	freopen("c:\\users\\admin\\desktop\\ans.txt","w",stdout);
	__int64 p,q;
	int n;
	char c;
	cin>>n;
	for(int times=1;times<=n;times++)
	{
		cin>>p>>c>>q;
		cout<<"Case #"<<times<<": ";
		__int64 mm=m(p,q);
		if(mm!=1)
		{
			p/=mm;
			q/=mm;
		}
		if(!f(q))
			cout<<"impossible"<<endl;
		else
		{
			int ge=0;
			while(p<q){
				p*=2;
				ge++;
			}
			if(ge>40)
				cout<<"impossible"<<endl;
			else
				cout<<ge<<endl;
		}

	}
	return 0;
}
