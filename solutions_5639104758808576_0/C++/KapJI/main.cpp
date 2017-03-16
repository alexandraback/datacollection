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
const int MAXN = 150;

int solve() {
    int s;
    scanf("%d", &s);
    fprintf(stderr, "s = %d\n", s);
    int ans = 0, sum = 0;
    for (int i = 0; i <= s; ++i) {
        char c;
        scanf(" %c", &c);
        ans = max(ans, i - sum);
        sum += c - '0';
    }
    return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    FOR(i, t) {
        printf("Case #%d: %d\n", i + 1, solve());
    }
	return 0;
}

