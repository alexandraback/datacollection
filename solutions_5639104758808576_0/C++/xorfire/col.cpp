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

		int n; cin >> n;
		string s; cin >> s;
		int mx = 0, sum = 0;
		for (int i = 0; i <= n; i++)
		{
			if (mx < i - sum) mx = i - sum;
			sum += s[i] - '0';
		}
		if (tt > 1) cout << "\n";
		cout << "Case #" << tt << ": " << mx;
	}
	return 0;
}