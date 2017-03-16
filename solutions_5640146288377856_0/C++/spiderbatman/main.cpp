#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>

#define INF 2000000000
#define MOD 1000000007

using namespace std;


int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testCount;
	cin >> testCount;
	for (int testNum = 1; testNum <= testCount; testNum++) {
		cout << "Case #" << testNum << ": ";
		int r, c, w;
		cin >> r >> c >> w;
		int ans = 0;
		ans += c / w;
		ans *= r;
		ans += w;
		if (c % w == 0) {
			ans--;
		}
		cout << ans << endl;
	}	
	return 0;
}