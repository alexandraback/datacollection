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
#define forit(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int a[128];

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        printf("Case #%d: ", _+1);
        
        int A, n;
        scanf("%d%d", &A, &n);
        forn(i, n) scanf("%d", &a[i]);
        sort(a, a + n);

        int ans = n;
        int cur = 0;
        forn(i, n) {
            if (a[i] >= A) {
                if (A == 1) break;
                while (a[i] >= A) A += A-1, cur++;
            }
            A += a[i];
            ans = min(ans, cur + n-i-1);
        }

        printf("%d\n", ans);
    }
    return 0;
}

