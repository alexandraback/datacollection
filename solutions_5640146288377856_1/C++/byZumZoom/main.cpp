#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define INF 2147483647
#define PI acos(-1.0)

using namespace std;

int main(int argc, const char ** argv)
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test)
	{
		int r, c, w;
		cin >> r >> c >> w;

		int ans = c / w;
		ans *= r;
		if(c % w == 0)
			ans += w - 1;
		else
			ans += w;


		cout << "Case #" << test << ": " << ans  << endl;
	}

	return 0;
}
