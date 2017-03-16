// GCJ2013R2C.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

#pragma warning(disable:4996)

using namespace std;

int T,X,Y;
string s;
int n;

void init()
{
	cin >> T;
}


void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> X >> Y;

		cout << "Case #" << ca << ": ";

		int x,y;
		x=0;
		y=0;
		int i=0;
		if (X < 0)
		{
			while (x != X)
			{			
				cout << "EW";
				x--;
			}
		}
		else
		{
			while (x != X)
			{			
				cout << "WE";
				x++;
			}
		}
		
		if (Y < 0)
		{
			while (y != Y)
			{			
				cout << "NS";
				y--;
			}
		}
		else
		{
			while (y != Y)
			{			
				cout << "SN";
				y++;
			}
		}
		
		cout << endl;
		
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\B-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\B-small-attempt0.out", "w", stdout);
	init();
	work();

	return 0;
}



