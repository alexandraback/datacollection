#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>

#define all(x) (x).begin(),(x).end()

using namespace std;

const int nmax = 1e5;
int a[nmax];
int n;
int sum;

bool ok(int c, double v)
{
	double points = sum * v + a[c];
	double req = 0;
	for (int i = 0; i < n; i ++)
		if (i != c)
			if (a[i] < points)
				req += (points - a[i]) / double(sum);			
	return req + v > 1;
}	

void solve(int case_number)
{
	cin >> n;
	sum = 0;
	for (int i = 0; i < n; i ++)
	{
		cin >> a[i];
		sum += a[i];
	}
	printf("Case #%d:", case_number);
	for (int i = 0; i < n; i ++)
	{
		double l = 0;
		double r = 1;
		for (int j = 0; j < 200; j ++)
		{
			double m = (l + r) / 2;
			if (ok(i, m))
				r = m;
			else 
				l = m;
		}
		printf(" %.10lf", r * 100);
	}
	printf("\n");
}


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i ++)
		solve(i + 1);
	return 0;
};
