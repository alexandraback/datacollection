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

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";
		string s; cin >> s;
		int n = s.size(), ret = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '-' and (i == 0 or s[i - 1] == '+'))
				ret += 2;
		if (s[0] == '-') ret--;
		cout << "Case #" << tt << ": " << ret << "\n";
	}
	return 0;
}