#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <ctime>
#include <functional>
#include <cstring>
#include <map>
#include <cctype>
#include <unordered_map>

using namespace std;
using pr = pair<int, int>;

int solve(int c, int r, int w)
{
	int d = c / w;
	return d * r + w - (c % w ? 0 : 1);
}

int main()
{
	freopen("INPUT.TXT", "r", stdin); freopen("OUTPUT.TXT", "w", stdout);
	int c, r, w, t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> r >> c >> w;
		int res = solve(c, r, w);
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
}