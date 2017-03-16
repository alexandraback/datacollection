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
typedef __int128 ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 111111;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

string s, t, ans;
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
		cin >> s;
		t = s[0];
		for (int j = 1; j < s.size(); j++)
		{
			if (s[j] >= t[0])
				t = s[j] + t;
			else
				t = t + s[j];
		}
		cout << "Case #" << test << ": " << t << "\n";
	}
	
	return 0;
}