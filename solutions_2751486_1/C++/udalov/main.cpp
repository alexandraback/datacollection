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
typedef long long LL;

char s[1000500];
int m;
int cons[1000500];

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        printf("Case #%d: ", _+1);
        scanf("%s%d", s, &m);

        int n = strlen(s);
        cons[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            if (vowel(s[i])) cons[i] = 0;
            else cons[i] = cons[i+1] + 1;
        }

        int last = -1;
        LL ans = 0;
        for (int i = n-1; i >= 0; i--) {
            if (cons[i] >= m) {
                ans += n - i - (m-1);
                last = i;
            } else if (last != -1) {
                ans += n - last - (m-1);
            }
            // printf("i %d ans %lld\n", i, ans);
        }

        printf("%lld\n", ans);
    }
    return 0;
}

