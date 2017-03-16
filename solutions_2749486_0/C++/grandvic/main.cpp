/*
 * main.cpp
 *
 *  Created on: 12.05.2013
 *      Author: grand
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

void solve()
{
	int X,Y;
	cin>>X>>Y;
	int x=0, y=0;

	char nap = 'E';
	int step = 1;
	while(true)
	{
		if(x==X)
			break;
		if(nap=='E')
		{
			x += step;
			nap = 'W';
			cout<<'E';
		}
		else
		{
			x -= step;
			nap = 'E';
			cout<<'W';
		}
		++step;
	}

	if(y>Y)
	{
		cout<<'N';
		y+=step;
		nap = 'S';
	}
	else
	{
		cout<<'S';
		y-= step;
		nap = 'N';
	}
	++step;

	while(true)
	{
		if(y==Y)
			break;
		if(nap=='N')
		{
			y += step;
			nap = 'S';
			cout<<'N';
		}
		else
		{
			y -= step;
			nap = 'N';
			cout<<'S';
		}
		++step;
	}
	cout<<endl;
}

int main()
{
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout<<"Case #"<<t<<": ";
		solve();
	}

	return 0;
}
