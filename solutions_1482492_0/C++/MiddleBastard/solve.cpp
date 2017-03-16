#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>
#define ll long double

using namespace std;

int n, nA, t;
ll A;
vector < ll > at, ax;
ll d;


ll calc(ll A)
{
	if (n == 1)
	{
		return sqrt(2 * d / A);
	}
	
	ll v = (ax[1] - ax[0]) / (at[1] - at[0]);
	ll dsk = 4 * v * v + 8 * ax[0] * A;
	ll t1 = (2 * v + sqrt(dsk)) / 2 / A;
	ll dist1 = A * t1 * t1 / 2;
	
	if (dist1 > d)
		return sqrt(2 * d / A);
	
	ll dist2 = d - dist1;
	ll t2 = dist2 / v;
	
	return t1 + t2;
}


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	cin >> t;
	
	cout.setf(ios::fixed);
	cout.precision(7);
	
	
	for (int z = 0; z < t; z++)
	{
		cin >> d >> n >> nA;
		
		at.resize(n);
		ax.resize(n);
		
		cout << "Case #" << z + 1 << ":\n";
		
		for (int i = 0; i < n; i++)
		{
			cin >> at[i] >> ax[i];			
		}
		
		for (int i = 0; i < nA; i++)
		{
			cin >> A;
			cout << calc(A) << endl;
		}
	}

	return 0;
}
