#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long Num;
//                       0  1  2  3  4  5  6 
const int min_size[] = { 0, 1, 1, 2, 3, 3, 3 };

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	if (x < y)
	{
		swap(x, y);
	}
	if (n >= 7)
	{
		cout << "RICHARD" << endl;
		return;
	}
	else
	{
		if ((x * y) % n != 0)
		{
			cout << "RICHARD" << endl;
			return;
		}
		if (x < n)
		{
			cout << "RICHARD" << endl;
			return;
		}
		if (y < min_size[n])
		{
			cout << "RICHARD" << endl;
			return;
		}
		cout << "GABRIEL" << endl;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(0);
#ifdef GRANDVIC_DEBUG
	//freopen("d:/input.txt", "rt", stdin);
#endif
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}
