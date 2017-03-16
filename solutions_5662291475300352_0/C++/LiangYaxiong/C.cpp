/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

const int max_n = 1000 + 10;

int t, n, d[max_n], h[max_n], m[max_n];
vector<pair<int, int> > hikers;

int count_hikers() {
    if (hikers.size() > 2)
        return -1;
    if (hikers.size() == 1)
        return 0;
    sort(hikers.begin(), hikers.end());
    int d1 = hikers[0].first, m1 = hikers[0].second;
    int d2 = hikers[1].first, m2 = hikers[1].second;
    if (m1 == m2)
        return 0;
    if (m1 > m2) {
        if ((360LL + d1 - d2) * m2 > (360LL - d1) * (m1 - m2))
            return 0;
        else
            return 1;
    } else {
        if ((360LL + d2 - d1) * m1 > (360LL - d2) * (m2 - m1))
            return 0;
        else
            return 1;
    }
}

void solve() {
    scanf("%d", &n);
    hikers.clear();
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &d[i], &h[i], &m[i]);
        for (int j = 0; j < h[i]; ++j)
            hikers.push_back(make_pair(d[i], m[i] + j));
    }
    printf("Case #%d: %d\n", ++t, count_hikers());
}

int main() {
    freopen("out2.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
