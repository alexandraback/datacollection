/*
 * b.cpp
 *
 *  Created on: 2012-4-14
 *      Author: dabao
 */

#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;


int cases;

int n,s,p;
int t[200];
int cnt=0;

bool myfun(int i,int j) { return (i>j); }

void init()
{
	cin>>n>>s>>p;
	for(int i=0;i<n;++i)
		cin>>t[i];
	cnt=0;
}

void solve()
{
	sort(t,t+n,myfun);

	for(int i=0;i<n;++i)
	{
		if(t[i]+2>=3*p)
			cnt++;
		else if(s>0 && t[i]+4>=3*p && t[i]>=p)
		{
			cnt++;
			s--;
		}
	}
	cout<<cnt<<endl;
}


int main()
{
	cin>>cases;
	cin.ignore();

	for(int ii=1;ii<=cases;++ii)
	{
		init();
		cout<<"Case #"<<ii<<": ";
		solve();
	}
}


