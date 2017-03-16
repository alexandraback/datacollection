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

void solve()
{
	int k, c, s; cin >> k >> c >> s;
	if (k == s)
	{
		for (int i = 1; i <= k; ++i)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}
