#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
     if (b == 0) return a;
     return gcd(b, a % b);
}

void solve()
{
	ll P, Q;
	scanf("%lld/%lld\n", &P, &Q);
	ll g = gcd(P, Q);
	P = P / g;
	Q = Q / g;
	ll q = Q;
	int n = 0;
	while (q > 1) {
		if (q % 2 != 0) {
			printf("impossible");
			return;
		}
		q = q / 2;
		++n;
	}

	ll m = ((ll)1) << n;
	int ans = 0;
	while (m > 0) {
		if (P & m) break;
		m = m >> 1;
		++ans;
	}
	printf("%d", ans);
    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
