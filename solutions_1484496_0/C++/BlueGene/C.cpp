/*
Title: C
Data: 2012-5-5
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

#define InputFileName		"C-small-attempt0.in"
#define OutputFileName		"C-small-attempt0.out"

using namespace std;

const int MaxN = 510;

int TestCase, T, n;
long long a[MaxN];
map<long long, int> Hash;

inline bool Check()
{
	long long Sum;
	Hash.clear();
	for (int opt = 0, i; opt < 1 << n; ++opt)
	{
		for (Sum = i = 0; i < n; ++i)
			if ((opt >> i) & 1)
				Sum += a[i];
		if (! Hash[Sum])
			Hash[Sum] = opt;
		else
		{
			for (int i = 0; i < n; ++i)
				if ((Hash[Sum] >> i) & 1)
					cout << a[i] << " ";
			cout << endl;
			for (int i = 0; i < n; ++i)
				if ((opt >> i) & 1)
					cout << a[i] << " ";
			cout << endl;
			return 1;
		}
	}
	return 0;
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
		cout << "Case #" << T << ":" << endl;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		if (! Check())
			cout << "Impossible" << endl;
	}
	return 0;
}
