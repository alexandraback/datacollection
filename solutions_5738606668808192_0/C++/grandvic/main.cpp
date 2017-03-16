#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <deque>
#include <iterator>
#include <string>
#include <limits>
#include <sstream>
 
using namespace std;

const string preffix = "1";
const string postfix = "1 3 4 5 6 7 8 9 10 11";

string formBin(int x, int bits)
{
	stringstream ss;

	for (int i = 0; i < bits; ++i)
	{
		ss << (x % 2);
		x >>= 1;
	}

	return ss.str();
}

void solve()
{
	int n, j; cin >> n >> j;
	n = (n - 2) / 2;
	for (int i = 0; i < j; ++i)
	{
		string s = formBin(i, n);
		cout << preffix << s << s << postfix << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
//	freopen("i:/input.txt", "rt", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ":" << endl;
		solve();
	}
}
