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

char multi(char x, char y, int* sign)
{
	if (x=='1') return y;
	if (y=='1') return x;
	if (x==y)
	{
		*sign=- (*sign);
		return '1';
	}
	if (x=='i' && y=='j') return 'k';
	if (x=='i' && y=='k')
	{
		*sign=- (*sign);
		return 'j';
	}
	if (x=='j' && y=='i')
	{
		*sign=- (*sign);
		return 'k';
	}
	if (x=='j' && y=='k')
	{
		return 'i';
	}
	if (x=='k' && y=='i')
		return 'j';
	if (x=='k' && y=='j')
	{
		*sign=- (*sign);
		return 'i';
	}
}

void test(string str)
{
	int cmp=0;
	int sign=1;
	char tmp='1';
	for (int i=0;i<str.length();i++)
	{
		tmp=multi(tmp,str[i], &sign);
		if (cmp==0 && sign==1 && tmp=='i')
		{
			cmp++;
			sign=1;
			tmp='1';
		}
		else if (cmp==1 && sign==1 && tmp=='j')
		{
			cmp++;
			sign=1;
			tmp='1';
		}
		else if (cmp==2 && sign==1 && tmp=='k' && i==str.length()-1)
		{
			cmp++;
			sign=1;
			tmp='1';
		}
	}
	if (cmp==3) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int cst;
	int p[1100];
	cin>>cst;
	for (int cs=1;cs<=cst;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		int l,x;
		cin>>l>>x;
		string str;
		cin>>str;
		string tot="";
		if (x>20) x%4+20;
		for (int i=1;i<=x;i++)
			tot+=str;
		test(tot);
	}
	return 0;
}