#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int t, n;
pair<int, int> p[1024];

void solve() {
    scanf("%d", &n);
    set<int> ss;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].second, &p[i].first);
        ss.insert(i);
    }
    sort(p, p + n);
    int star = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (star >= p[i].first) {
            ++res;
            star += (ss.find(i) == ss.end() ? 1 : 2);
            ss.erase(i);
        } else {
            while (true) {
                bool f = false;
                for (set<int>::reverse_iterator j = ss.rbegin(); j != ss.rend(); ++j) {
                    if (star < p[*j].second)
                        continue;
                    f = true;
                    ++star;
                    ++res;
                    ss.erase(*j);
                    break;
                }
                if (!f || star >= p[i].first)
                    break;
            }
            if (star < p[i].first) {
                printf("Case #%d: Too Bad\n", ++t);
                return;
            }
            ++res;
            star += (ss.find(i) == ss.end() ? 1 : 2);
            ss.erase(i);
        }
            //printf("-- %d %d %d\n", i, star, res);
    }
    printf("Case #%d: %d\n", ++t, res);
}

int main() {
    freopen("B.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
