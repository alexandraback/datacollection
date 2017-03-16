#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> st;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 10010;

bool solve() {
    int x, r, c;
    cin >> x >> r >> c;
    if (r > c) {
        swap(r, c);
    }
    if (x == 1) {
        return true;
    }
    if (x == 2) {
        return (r * c) % 2 == 0;
    }
    if (x == 3) {
        return (r * c) % 3 == 0 && r >= 2 && c >= 3;
    }
    if (x == 4) {
        return (r * c) % 4 == 0 && r >= 3 && c >= 4;
    }
    return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    FOR(i, t) {
        printf("Case #%d: %s\n", i + 1, solve() ? "GABRIEL" : "RICHARD");
    }
	return 0;
}

