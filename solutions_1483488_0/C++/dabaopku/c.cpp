/*
 * c.cpp
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
#include <set>

using namespace std;


int cases;
int a,b,c,d;
int cnt;
int len;
int power;
set<int> found;

void init()
{
	cin>>a>>b;
	cnt=0;
	len=1;
	int t=1;
	while(t<=b)
	{
		len++;
		t*=10;
	}
	power=t/10;
	len--;
}

void solve()
{
	for(int c=a;c<=b;++c)
	{
		found.clear();
		d=c;
		for(int i=0;i<len-1;++i)
		{
			d=d/10+d%10*power;
			if(c<d && d<=b)
			{
				if(found.count(d)==0)
				{
					//cout<<c<<" "<<d<<endl;
					cnt++;
					found.insert(d);
				}
			}
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


