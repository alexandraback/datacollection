// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

bool f(int a)
{
	while(a!=1){
		if(a%2==1)
			return 0;
		a/=2;
	}
	return 1;
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	freopen("c:\\users\\admin\\desktop\\a.in","r",stdin);
	freopen("c:\\users\\admin\\desktop\\ans.txt","w",stdout);
	int p,q,n;
	char c;
	cin>>n;
	for(int times=1;times<=n;times++)
	{
		cin>>p>>c>>q;
		cout<<"Case #"<<times<<": ";
		if(!f(q))
			cout<<"impossible"<<endl;
		else
		{
			int ge=0;
			while(p<q){
				p*=2;
				ge++;
			}
			cout<<ge<<endl;
		}

	}
	return 0;
}
