// GCJ2014R2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T;
long long p,q;

void init()
{
	scanf("%d",&T);
}

long long gcd(long long x, long long y)
{
	if (x>y) return gcd(y,x);

	if (y%x == 0) return x;
	return gcd(y%x, x);
}

int solve()
{
	long long g = gcd(p, q);
	p/=g;
	q/=g;
	long long left = q;
	int count = 0;
	int stop = 0;
	while (left>1) {
		if (left%2 == 0) {
			left/=2;
		} else if (left != 1) {
			return -1;
		}
		p=p/2;
		if (p>0) {
			stop++;
		}
		count++;
	}

	return count-stop;
}

void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		scanf("%lld/%lld", &p, &q);
				
		cout << "Case #" << ca << ": ";		
		int ret = solve();
		if (ret > 0) {
			cout << ret << endl;
		} else {
			cout << "impossible" << endl;
		}			 
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\A--large.in", "r", stdin);
	//freopen("C:\\Users\\yuazh\\Downloads\\A--large.out", "w", stdout);
	init();
	work();

	return 0;
}

