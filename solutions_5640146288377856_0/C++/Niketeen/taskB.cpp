#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;
typedef long long ll;
const double eps = 1e-9;
const int mod = 1e9 + 7;



int main(){
	//freopen("A-small-attempt0 (4).in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t)
	{
		int r, c, w;
		cin >> r >> c >> w;
		int ans = (r - 1) * c / w;

		int ptr = 1;
		while (c - ptr + 1 >= 2 * w)
		{
			ans++;
			ptr += w;
		}
		ans += w + 1;
		if (c - ptr + 1 == w)
			ans--;
		cout << "Case #" << t << ": " << ans << "\n";

	}



	return 0;
}