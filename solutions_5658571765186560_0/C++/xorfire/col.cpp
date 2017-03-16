#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

const string ip = "RICHARD", p = "GABRIEL";

string go(int x, int m, int n)
{
	if (m * n % x != 0) return ip;
	if (m < n) swap(m, n);
	if (x <= 2)
		return p;
	else if (x == 3)
		return n == 1 ? ip : p;
	else if (x == 4)
		return (m >= 4 and n >= 3) ? p : ip;
	else if (x == 5)
		return n < 3 ? ip : n == 3 ? (m >= 10 ? p : ip) : p;
	else if (x == 6)
		return n < 3 ? ip : n == 3 ? (m >= 6 ? p : ip) : p;
	else return ip;
}

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";
		int x, m, n;
		cin >> x >> m >> n;
		cout << "Case #" << tt << ": " << go(x, m, n) << "\n";
	}
	return 0;
}