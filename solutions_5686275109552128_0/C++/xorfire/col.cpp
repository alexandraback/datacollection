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
		vector <int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		int ret = 1000;
		for (int x = 0; x < ret; x++)
		{
			int l = 1, r = 1000;
			while (l < r)
			{
				int y = (l + r) / 2, ct = 0;
				for (int i = 0; i < n; i++)
					ct += (a[i] - 1) / y;
				if (ct <= x) r = y;
				else l = y + 1;
			}
			if (ret > x + l) ret = x + l;
		}
		cout << "Case #" << tt << ": " << ret << "\n";
	}
	return 0;
}