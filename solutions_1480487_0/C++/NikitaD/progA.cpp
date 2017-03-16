
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (i = 0; i < (int)(n); ++i)
#define sz(v) ((v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))
#define updMax(a, b) ((a) = max((a), (b)))
#define updMin(a, b) ((a) = min((a), (b)))

const int maxn = 200 + 5;

const ld eps = 1e-10;

int s[maxn];
int n, x;

bool ok(int num, ld y)
{
	ld pnt = s[num] + x * y;
	y = 1 - y;
	int i;
	forn(i, n) {
		if (i == num)
			continue;
		if (s[i] < pnt - eps) {
			ld t = (pnt - s[i]) / (ld)x;
			if (t > y + eps)
				return true;
			y -= t;
		}
	}
	return abs(y) < eps;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout << fixed << setprecision(12);

	int t, it, i, j, k;
	scanf("%d", &t);
	for (it = 0; it < t; ++it) {
		cout << "Case #" << it + 1 << ":";
		scanf("%d", &n);
		x = 0;
		forn(i, n) {
			scanf("%d", &s[i]);
			x += s[i];
		}
		forn(i, n) {
			ld l = 0, r = 1.0, y;
			for (k = 0; k < 200; ++k) {
				y = (l + r) * 0.5;
				if (ok(i, y))
					r = y;
				else
					l = y;
			}
			cout << " " << l * 100;
		}
		cout << "\n";
	}

	return 0;
}