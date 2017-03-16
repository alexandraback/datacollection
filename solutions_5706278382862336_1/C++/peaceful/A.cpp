#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
typedef long long ll;
#define mset(a, val) memset(a, val, sizeof(a))
#define up(i, s, t) for (ll i = (s); i < (t); i += 1)
#define down(i, s, t) for (ll i = (s); i > (t); i -= 1)
#define rd1(a) scanf("%d", &a)
#define rd2(a, b) scanf("%d %d", &a, &b)
#define rd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define rd4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define pii pair<int, int>

using namespace std;
const int MAXINT = 0x6fffffff;
const ll MAXLONG = (ll) 1 << 60;

template <typename T>
T gcd(T a, T b) {
  while (b != 0) {
    T t = b;
    b = a % b;
    a = t;
  }
  return a;
}

ll ba[50];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	
	up(i, 0, 50) {
		ll tmp = pow(2.0, 1.0 * i);
		ba[i] = tmp;
	}

	int t;
	cin >> t;
	up(ca, 1, t + 1) {
		printf("Case #%lld: ", ca);

		ll a, b;
		scanf("%lld/%lld", &a, &b);

		ll g = gcd(a, b);
		a /= g;
		b /= g;

		int big = -1;
		up(i, 0, 50) {
			if (ba[i] == b) {
				big = i;
				break;
			}
		}
		
		if (big == -1) {
			puts("impossible");
			continue;
		}
		
		int res = 1;
		while (true) {
			if (a * 2 >= b) {
				break;
			}
			res ++;
			b /= 2;
		}

		printf("%d\n", res);
	}
    return 0;
}