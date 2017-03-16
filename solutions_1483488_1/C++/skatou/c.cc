/*
 * Sat Apr 14 07:55:44 CST 2012
 */
#define see(n) cerr << #n << " = " << n << endl
#define seeArray(n, a) cerr << #a << " = ";\
    for (int __i__ = 0; __i__ < (int) n; ++__i__)\
        cerr << a[__i__] << " ";\
    cerr << endl;
#define seeArray2(n, m, a) cerr << #a << " = " << endl;\
    for (int __i__ = 0; __i__ < (int) n; ++__i__) {\
        for (int __j__ = 0; __j__ < (int) m; ++__j__)\
            cerr << a[__i__][__j__] << " ";\
        cerr << endl;\
    }
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <sstream>
#include <cctype>
#include <ctime>
#include <numeric>
using namespace std;
const int dir[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };
const int inf = 1000000000;
const long long infll = 1000000000000000000LL;
const double eps = 1e-10;
const double pi = acos(-1.0);

int cases, cas = 1;
set<pair<int, int> > pairs;
int from, to;

void doit(int num) {
    char buf[16]; sprintf(buf, "%d", num); int len = (int) strlen(buf);
    for (int start = 1; start < len; ++start) {
        int tmp = 0; for (int i = start; i < len; ++i) {
            tmp = tmp * 10 + buf[i] - '0';
        }
        for (int i = 0; i < start; ++i) {
            tmp = tmp * 10 + buf[i] - '0';
        }
        if (tmp >= from && tmp <= to && tmp != num) {
            int tmp2 = num; if (tmp > tmp2) {
                swap(tmp, tmp2);
            }
            pairs.insert(make_pair(tmp, tmp2));
        }
    }
}

int main() {
    for (scanf("%d", &cases); cases--; ++cas) {
        cin >> from >> to; pairs.clear();
        for (int i = from; i <= to; ++i) {
            doit(i);
        }
        printf("Case #%d: %d\n", cas, (int) pairs.size());
    }
    return 0;
}
