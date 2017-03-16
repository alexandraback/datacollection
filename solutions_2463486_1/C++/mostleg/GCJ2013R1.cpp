// GCJ2013R1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T;
long long A,B;
int N;
long long save[1000];


bool isP(long long x)
{
	long long y, t;
	y=0;
	t=x;
	while (t)
	{
		y=y*10 + t%10;
		t/=10;
	}
	return x==y;
}

void init()
{
	cin >> T;
	for (long long i=1; i<10000000; i++)
	{
		if (isP(i) && isP(i * i))
		{
			save[N++]=i*i;				
		}
	}
}


void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> A >> B;

		cout << "Case #" << ca << ": ";
		int count=0;	
		for (int i=0; i<N && save[i] <= B; i++)
		{
			if (save[i] >= A)
			{
				count++;
			}
		}
		cout << count << endl;
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\C-large-1.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\C-large-1.out", "w", stdout);
	init();
	work();

	return 0;
}

