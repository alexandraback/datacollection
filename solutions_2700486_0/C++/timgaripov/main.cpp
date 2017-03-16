#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define len(x) (int((x).size()))
#ifdef LOCALD
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#ifdef __linux__
#define I64d "%lld"
#else
#define I64d "%I64d"
#endif

typedef long long int int64;
typedef long double ext;

const int inf = 1000000000;


using namespace std;

const int maxx = 100;
const int zero = 50;
const int maxn = 21;

int tests;
int n, tx, ty;


int main()
{
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
    assert(freopen("debug.txt", "wt", stderr));
	scanf("%d", &tests);
	cout.precision(6);
	cout.setf(ios::fixed);
	for (int test = 0; test < tests; test++){
		eprintf("TEST %d\n", test);
		scanf("%d %d %d", &n, &tx, &ty);
		tx = abs(tx);
		int l = (tx + ty) / 2;
		ext res;
		if (n <= (1 + 2 * (l - 1)) * ((l - 1) + 1))
			res = 0.0;
		else if (n >= (1 + 2 * l) * (l + 1))
			res = 1.0;
		else{
			int k = n - (1 + 2 * (l - 1)) * ((l - 1) + 1);
			int t = ty + 1;
			if (tx == 0)
				res = 0.0;
			else{
				ext q = 1.0;
				for (int i = 0; i < k; i++)
					q = q * 0.5;
				res = 0.0;
				for (int i = 0; i <= k - t; i++){
					res += q;
					q = q * (k - i) / ext(i + 1);
				}
			}
		}
		cout << "Case #" << test + 1 << ": " << res << "\n";
	}
    return 0;
}
