/*
Title: A
Data: 2012-5-6
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define InputFileName		"A-large.in"
#define OutputFileName		"A-large.out"

using namespace std;

const int MaxN = 300;
const double EPS = 1E-12;

int TestCase, T, n;
double x, y[MaxN], J[MaxN];

inline bool Check(const double k, const int i)
{
	double Sum = 0;
	for (int j = 1; j <= n; ++j)
		Sum += max((J[i]-J[j])/x+k, 0.0);
	return Sum > 1.0-EPS; 
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++T)
	{
		cin >> n;
		x = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> J[i];
			x += J[i];
		}
		for (int i = 1; i <= n; ++i)
			for (double l = y[i] = 0, r = 1, mid = (l+r)/2; fabs(l-r) > 1E-12; mid = (l+r)/2)
				y[i] = Check(mid, i) ? r = mid : l = mid;
		cout << "Case #" << T << ":" << setprecision(10) << fixed;
		for (int i = 1; i <= n; ++i)
			cout << " " << y[i]*100;
		cout << endl;
	}
	return 0;
}
