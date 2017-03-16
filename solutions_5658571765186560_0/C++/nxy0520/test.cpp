// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	freopen("D-small-attempt6.in","r",stdin);
	freopen("D-small-attempt6.out","w",stdout);
	int cst;
	cin>>cst;
	for (int cs=1;cs<=cst;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		int x,r,c;
		cin>>x>>r>>c;
		if (x>max(r,c)) cout<<"RICHARD"<<endl;
		else if (x>=7) cout<<"RICHARD"<<endl;
		else if (r*c%x!=0) cout<<"RICHARD"<<endl;
		else if (min(r,c)<(x+1)/2) cout<<"RICHARD"<<endl;
		else
		{
			if (x<=3) cout<<"GABRIEL"<<endl;
			if (x==4) 
			{
				if (max(r,c)>3 && min(r,c)>2) cout<<"GABRIEL"<<endl;
				else cout<<"RICHARD"<<endl;
			}
			if (x==5)
			{
				if (min(r,c)>3) cout<<"GABRIEL"<<endl;
				else cout<<"RICHARD"<<endl;
			}
			if (x==6)
			{
				if (min(r,c)>3) cout<<"GABRIEL"<<endl;
				else cout<<"RICHARD"<<endl;
			}
			
		}
	}
	return 0;
}