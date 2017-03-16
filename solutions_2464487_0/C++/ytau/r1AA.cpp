#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>

using namespace std;

#define INF 2000000000
#define INFL 9000000000000000000LL
#define INFF 1.0e18
#define EPS 1.0e-8

int T;
long long r, t, ans;

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%lld%lld", &r, &t);
		ans = 0;
		while (2 * r + 1 <= t) {
			t -= 2 * r + 1;
			r += 2;
			ans++;
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}

