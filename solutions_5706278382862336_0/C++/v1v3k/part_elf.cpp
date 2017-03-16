#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <set>
#include <cstring>
#include <sstream>
#include <stack>
#include <map>
#include <numeric>
using namespace std;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define out(x) cout << (x) << endl;
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
const int INF = (long long) 1e9;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		ll p, q;
		scanf("%lld/%lld", &p, &q);
		ll g = gcd(p, q);
		p /= g;
		q /= g;
		int flag = 0;

		ll cq = q;

		while (cq > 1) {
			if (cq % 2 != 0) {
				flag = 1;
				break;
			}
			cq /= 2;
		}

		if (flag) {
			printf("Case #%d: impossible\n", t);
			continue;
		}

		int times = 0;
		while (p < q) {
			p *= 2LL;
			times++;
		}
		printf("Case #%d: %d\n", t, times);
	}
	return 0;
}