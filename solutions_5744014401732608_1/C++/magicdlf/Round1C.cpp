// Round1C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "string.h"
#include "stdio.h"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		long long B,M;
		cin>>B>>M;
		int g[55][55]={};
		for(int i=0;i<B-1;i++)
		{
			for(int j=i+1;j<B-1;j++)
			{
				g[i][j]=1;
			}
		}
		int cur=1;
		long long m=M-1;
		g[0][B-1]=1;
		while(m)
		{
			if(m%2)
			{
				g[cur][B-1]=1;
			}
			m/=2;
			cur++;
		}
		
		cout<<"Case #"<<tc+1<<": ";
		if(M>(1LL<<(B-2))) cout<<"IMPOSSIBLE"<<endl;
		else
		{
			cout<<"POSSIBLE"<<endl;
			for(int i=0;i<B;i++)
			{
				for(int j=0;j<B;j++)
				{
					cout<<g[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}