#include <cstdio>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int MOD = 1000000007;

int n;
char s[111][111];
int p[111];
bool have[26];
string t;


int main() {
    int nt;
    assert(scanf("%d", &nt) == 1);
    for (int tt = 1; tt <= nt; tt++) {
        eprintf("test %d\n", tt);
        assert(scanf("%d", &n) == 1);
        for (int i = 0; i < n; i++) {
            assert(scanf("%s", s[i]) == 1);
        }
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        int res = 0;
        do {
            bool ok = true;
            t = "";
            for (int i = 0; i < n; i++) {
                t += string(s[p[i]]);
            }
            int m = t.size();
            for (int i = 0; i < 26; i++) {
                have[i] = false;
            }
            for (int i = 0; i < m; ) {
                int c = t[i] - 'a';
                if (have[c]) {
                    ok = false;
                    break;
                }
                have[c] = true;
                int j = i;
                while (j < m && t[j] == t[i]) {
                    j++;
                }
                i = j;
            }
            if (ok) {
                res++;
            }
        } while (next_permutation(p + 0, p + n));
        eprintf("test %d done\n", tt);
        printf("Case #%d: %d\n", tt, res);
        fflush(stdout);
    }
    return 0;
}
