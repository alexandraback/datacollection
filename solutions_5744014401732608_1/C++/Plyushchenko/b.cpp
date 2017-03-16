#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

#define mp make_pair
#define pb push_back
#define problem "test"
//typedef __int128 ll;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 100;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

int n, e[z][z];
ll m;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		cout << "Case #" << test << ": ";
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			memset(e[i], 0, sizeof(e[i]));
		if (n == 2)
		{
			if (m == 1)
			{
				cout << "POSSIBLE\n01\n00\n";
				continue;
			}
			else
			{
				cout << "IMPOSSIBLE\n";
				continue;
			}

		}
		if ((1ll << (n - 2)) < m)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		int i;
		for (i = 1; (1ll << (i - 1)) < m; i++)
		{
//		    cerr << "i = " << i << "\n";
			for (int j = 0; j < i; j++)
				e[j][i] = 1;
		}
		e[0][n - 1] = 1;
		m--;
		int p = 1;
		while (m)
		{
			if (m % 2)
				e[p][n - 1] = 1;
			m /= 2;
			p++;
		}
		cout << "POSSIBLE\n";
		for (int j = 0; j < n; j++, cout << "\n")
			for (int k = 0; k < n; k++)
				cout << e[j][k];											
	}	
	
	return 0;
}