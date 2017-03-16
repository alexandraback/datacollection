#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int n, s;
vector<int> q;
vector<int> qq;
const double eps = 1e-9;

double minval(double v, int j)
{
	if (j+1 < n)
	{
		if ((qq[j+1]-qq[j]) * j > v)
			return qq[j] + v/j;
		return minval(v - (qq[j+1]-qq[j]) * j, j+1);
	}
	return qq[j] + v/j;
}

bool good(double v)
{
	return (v * s + qq[0]) >= minval(s * (1-v), 1);
}

double solve(int i)
{
	double L = 0, R = 1;
	while (R-L > eps)
	{
		double C = (L+R)/2;
		if (good(C))
			R = C;
		else
			L = C;
	}
	return (L+R)/2;
}

int main()
{
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i)
	{
		s = 0;
		q.clear();
		cin >> n;
		for (int j=0; j<n; ++j)
		{
			int t;
			cin >> t;
			s += t;
			q.push_back(t);
		}
		cout << "Case #" << i << ": ";
		for (int j=0; j<n; ++j)
		{
			qq = q;
			swap(qq[0], qq[j]);
			stable_sort(qq.begin()+1, qq.end());
			cout << fixed << setprecision(6) << solve(j)*100 << ' ';
		}
		cout << endl;
	}
	return 0;
}
