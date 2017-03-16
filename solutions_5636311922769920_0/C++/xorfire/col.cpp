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
		int k, c, s; cin >> k >> c >> s;
		assert(k == s);
		cout << "Case #" << tt << ": ";
		for (int i = 0; i < k; i++)
		{
			int ret = 0;
			for (int j = 0; j < c; j++)
				ret = ret * k + i;
			cout << ret + 1 << " \n"[i == k - 1];
		}
	}
	return 0;
}