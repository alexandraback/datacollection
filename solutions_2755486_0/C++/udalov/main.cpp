#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (auto it : v)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct Attack {
    int left;
    int w, e, delta_p;
    int s, delta_s;
    int delta_d;
};

#define SHIFT 20000000
int wall[40000000];

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        printf("Case #%d: ", _+1);
        
        memset(wall, 0, sizeof wall);
        map<int, vector<Attack> > m;

        int n;
        scanf("%d", &n);
        forn(i, n) {
            int di,ni,w,e,s,dd,dp,ds;
            scanf("%d%d%d%d%d%d%d%d", &di,&ni,&w,&e,&s,&dd,&dp,&ds);
            Attack a = {.left=ni, .w=w, .e=e, .delta_p=dp, .s=s, .delta_s=ds, .delta_d=dd};
            m[di].push_back(a);
        }

        int ans = 0;
        while (!m.empty()) {
            int t = m.begin()->first;
            vector<Attack> v = m.begin()->second;
            m.erase(m.begin());

            for (auto a : v) {
                // eprintf("attack at time %d from %d to %d with s %d, delta_p %d\n", t, a.w, a.e, a.s, a.delta_p);
                for (int i = a.w; i < a.e; i++) {
                    if (a.s > wall[i+SHIFT]) {
                        // eprintf("succeed\n");
                        ans++;
                        break;
                    }
                }
            }

            for (auto a : v) {
                for (int i = a.w; i < a.e; i++) {
                    wall[i+SHIFT] = max(wall[i+SHIFT], a.s);
                }
                if (a.left > 1) {
                    Attack b = {.left=a.left-1, .w=a.w+a.delta_p, .e=a.e+a.delta_p, .s=a.s+a.delta_s,
                        .delta_p=a.delta_p, .delta_s=a.delta_s, .delta_d=a.delta_d};
                    m[t + a.delta_d].push_back(b);
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}

