// QualRound.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

int solve()
{
	int X,R,C;
	cin>>X>>R>>C;
	if(R*C%X) return 0;
	if(X<=2) return 1;
	if(X==3)
	{
		if(R>=2 && C>=2) return 1;
		return 0;
	}
	if(X==4)
	{
		if(R>=3 && C>=3) return 1;
		return 0;
	}
	if(X==5)
	{
		if(R>=4 && C>=4) return 1;
		return 0;
	}
	if(X==6)
	{
		if(R>=6 && C>=6) return 1;
		return 0;
	}
	if(X>=7) return 0;
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		cout<<"Case #"<<tc+1<<": ";
		if(solve())
		{
			cout<<"GABRIEL"<<endl;
		}
		else
		{
			cout<<"RICHARD"<<endl;
		}
	}
}