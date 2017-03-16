#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define AUTO(it, expr) __typeof__(expr) it = (expr)
#define FOR(it, c) for (AUTO(it, (c).begin()); (it) != (c).end(); ++(it))
int s[1<<10];
pair<int, int> p[1<<10];

int main() {
    int t;
    cin >> t;
    REP (i, t) {
        int n;
        cin >> n;
        REP (j, n) {
            cin >> p[j].second>> p[j].first;
        }

        sort(p, p + n, greater<pair<int, int> >());

        memset(s, 0, sizeof s);
        int acc = 0, nc = 0;

        for (;;) {
            int j;
            for (j = 0; j < n; ++j)
                if (s[j] != 2)
                    goto work;
            break;
            
            work:
            for (j = 0; j < n; ++j)
                if (s[j] == 0 && p[j].first <= nc)
                    break;
            if (j < n) {
                ++acc;
                nc += 2;
                s[j] = 2;
                //                printf("%d: 0 -> 2\n", j);
            } else {
                for (j = 0; j < n; ++j)
                    if ((s[j] == 1 && p[j].first <= nc))
                        break;
                if (j < n) {
                    ++acc;
                    ++nc;
                    ++s[j];
                    //  printf("%d: 1 -> 2\n", j);
                } else {
                    for (j = 0; j < n; ++j)
                        if (s[j] == 0 && p[j].second <= nc)
                            break;
                    if (j < n) {
                        ++acc;
                        ++nc;
                        ++s[j];
                        //  printf("%d: 0 -> 1\n", j);
                    } else {
                        acc = -1;
                        break;
                    }
                }
            }
        }

        printf("Case #%d: ", i + 1);
        if (acc < 0) puts("Too Bad");
        else printf("%d\n", acc);
    }
}
