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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define INF 1000000

char s[52];
int a[52][5];

vector<string> dict;

int main() {
    FILE *f = fopen("garbled_email_dictionary.txt", "r");
    while (fscanf(f, "%s", s) == 1) {
        dict.push_back(s);
    }

    int __;
    scanf("%d", &__);
    forn(_, __) {
eprintf("%d\n", _+1);
        printf("Case #%d: ", _+1);

        scanf("%s", s);
        int n = strlen(s);

        forn(i, n) {
            forn(k, 5) a[i+1][k] = INF;
            for (auto& word : dict) {
                int l = word.length();
                if (l > i+1) continue;

                bool bad = false;

                int changes = 0;
                int first_change = INF;
                int last_change = -5;
                forn(j, l) {
                    if (s[i-l+1+j] != word[j]) {
                        if (j - last_change < 5) { bad = true; break; }
                        changes++;
                        if (first_change == INF) first_change = j;
                        last_change = j;
                    }
                }

                if (bad) continue;

                if (!changes) {
                    forn(k, 5) {
                        a[i+1][k] = min(a[i+1][k], a[i-l+1][max(0,k-l)]);
                    }
                } else {
                    int w = min(l-1-last_change, 4);
                    forn(k, 5) {
                        int that_i = i-l-k;
                        int this_i = i-l+1 + first_change;
                        if (this_i - that_i < 5) continue;
                        a[i+1][w] = min(a[i+1][w], changes + a[i-l+1][k]);
                    }
                }
            }

            forn(k, 4) a[i+1][k] = min(a[i+1][k], a[i+1][k+1]);
        }
        int ans = INF;
        forn(k, 5) ans = min(ans, a[n][k]);

        if (ans == INF) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

