#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

ll gcd( ll a, ll b ) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	forn(it, t) {
		ll p, q;
		scanf("%I64d/%I64d", &p, &q);

		ll g = gcd(p, q);
		p /= g;
		q /= g;

		if  ((q & (q - 1)) != 0) {
			printf("Case #%d: impossible\n", it+1);
			continue;
		}

		int res = -1;
		for (int i = 0; i <= 41; ++i) {
			ll part = 1ll << i;
			// q / part <= p
			if  (q <= part * p) {
				res = i;
				break;
			}	
		}

		printf("Case #%d: %d\n", it+1, res);
	}

	return 0;
}
