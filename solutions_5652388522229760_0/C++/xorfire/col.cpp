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
		if (n == 0)
			cout << "Case #" << tt << ": INSOMNIA\n";
		else
		{
			int cur = n, seen = 0;
			bool was[10] = {};
			while (true)
			{
				int buff = cur;
				while (buff > 0)
				{
					int dig = buff % 10;
					if (!was[dig]) seen++;
					was[dig] = true;
					buff /= 10;
				}
				if (seen == 10) break;
				cur += n;
			}
			cout << "Case #" << tt << ": " << cur << "\n";
		}
	}
	return 0;
}