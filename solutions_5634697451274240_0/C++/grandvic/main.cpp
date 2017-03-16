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
 
using namespace std;

void solve()
{
	string s; cin >> s;
	int changes = 0, n = s.length();
	for (int i = 1; i < n; ++i)
		changes += (s[i] != s[i - 1]);
	cout << (changes + (s[n - 1] == '-')) << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
//	freopen("i:/input.txt", "rt", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}
