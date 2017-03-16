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
	if(X>=7) return 0;
	if(R>=X-1 && C>=X-1) return 1;
	return 0;
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