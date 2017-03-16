#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef pair<int, int> P;
typedef unsigned int uint;
typedef unsigned long long ull;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};

const int inf = 1000000009;
const double eps = 1e-8;
const string R = "RICHARD", G = "GABRIEL";

bool check(int x, int r, int c, int i, int j, int len) {
    int lu = i * j, ld = i * (r - j - 1), ru = (len - i - 1) * j, rd = (len - i - 1) * (r - j - 1);
    if (c <= len) {
	if (lu % x == 0 && ld % x == 0 && ru % x == 0 && rd % x == 0)
	    return false;
    } else {
	for (int k = 0; k <= c - len; k++) {
	    if (k == 0) {
		if (lu % x == 0 && ld % x == 0 && (ru + rd + r * (c-len)) % x == 0)
		    return false;
		
	    } else if (k == c-len-1) {
		if ((lu + ld + r * k) % x == 0 && ru % x == 0 && rd % x == 0)
		    return false;
	    } else {
		if ((lu + ld + r * k) % x == 0 && (ru + rd + r * (c-len-k)) % x == 0)
		    return false;
	    }
	}
    }
    return true;
}

string solve() {
    int x, r, c;
    cin >> x >> r >> c;
    if (r > c) swap(r, c);
    if (x >= 7) return R;
    if (x > c) return R;
    if ((r * c) % x != 0) return R;
    for (int i = 1; i+1 <= x-i; i++) {
	if (i + 1 > r || x - i > c)
	    return R;
    }
    if (x - r + 1 >= r) {
	int len = x - r + 1;
	for (int i = 0; i < len; i++) {
	    for (int j = 0; j <= r / 2; j++) {
		if (check(x, r, c, i, j, len)) {
		    return R;
		}
	    }
	}
    }

    return G;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
	cout << "Case #" << i << ": " << solve() << endl;
    }
}
