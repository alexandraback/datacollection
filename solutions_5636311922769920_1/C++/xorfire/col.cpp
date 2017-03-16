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
		cout << "Case #" << tt << ": ";
		if (s * c < k) cout << "IMPOSSIBLE\n";
		else
			for (int i = 0; i < s; i++)
			{
				int ret = 0;
				for (int j = 0; j < c; j++)
					ret = ret * k + min(i * c + j, k - 1);
				cout << ret + 1 << " \n"[i == s - 1];
			}
	}
	return 0;
}