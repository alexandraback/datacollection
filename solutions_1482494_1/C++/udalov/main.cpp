#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (auto it = (v).begin(); it != (v).end(); ++it)
#define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define sz(v) ((int)((v).size()))
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long LL;

int a[1024], b[1024];

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        int n;
        scanf("%d", &n);
        set<iii> s1;
        set<iii> s2;
        forn(i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[i] = x;
            b[i] = y;
            s1.insert(iii(ii(x, -y), i));
            s2.insert(iii(ii(y, 0), i));
        }
        int have = 0;
        int ans = 0;
        while (!s1.empty() || !s2.empty()) {
/*printf("sets: ");
forit(it, s1) printf("%d ", it->second);
printf("   ");
forit(it, s2) printf("%d ", it->second);
printf("     have %d ans %d\n", have, ans);*/
            if (!s2.empty()) {
                int i = s2.begin()->second;
//printf("1st i = %d  %d %d\n", i, a[i], b[i]);
                if (b[i] <= have) {
                    iii z = iii(ii(a[i], -b[i]), i);
                    if (s1.find(z) != s1.end()) s1.erase(z), have += 1;
                    s2.erase(iii(ii(b[i], 0), i));
                    have += 1;
                    ans++;
                    continue;
                }
            }
            if (s1.empty()) goto no;
            int i = s1.begin()->second;
//printf("2nd i = %d  %d %d\n", i, a[i], b[i]);
            if (a[i] > have) goto no;
            s1.erase(iii(ii(a[i], -b[i]), i));
            have += 1;
            ans++;
        }
        printf("Case #%d: %d\n", _+1, ans);
        continue;
        no: printf("Case #%d: Too Bad\n", _+1);
    }
    return 0;
}

