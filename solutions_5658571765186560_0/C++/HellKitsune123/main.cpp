#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int tt;
int x, a, b;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        scanf("%d%d%d", &x, &a, &b);
        //printf("%d %d %d    ", x, a, b);
        if (a > b) swap(a, b);
        if (((a * b) % x != 0) ||
            (x > 2 * a) ||
            (a == 2 && x >= 5) ||
            (x > b) ||
            (a > 2 && x >= 7) ||
            (a == 3 && x == 6) ||
            (a == 2 && x == 4)) {
            printf("Case #%d: RICHARD\n", test);
        } else {
            printf("Case #%d: GABRIEL\n", test);
        }
    }
	return 0;
}
