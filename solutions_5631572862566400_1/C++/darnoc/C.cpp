#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <deque>

using namespace std;

#define N 1004

bool c2[N];
int lp[N];
int x[N];
int v[N];

int main()
{
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    int k = 0;
    for (int t = 1; t <= T; t++) {
        memset(lp, 0, sizeof(lp));
        int n; cin >> n;

        for (int i = 0; i < n; i++) {
            int bf; cin >> bf;
            x[i] = bf - 1;
        }
        for (int i = 0; i < n; i++) {
            c2[i] = x[x[i]] == i;
        }
        int maxcy = 0;
        for (int i = 0; i < n; i++) {
            ++k;
            int c = i, l = 0;

            for (;;l++) {
                if (c2[c]) {
                    lp[c] = max(lp[c], l);
                    break;
                }
                if (l && c == i) {
                    maxcy = max(maxcy, l);
                    break;
                }
                if (v[c] == k) break;
                v[c] = k;
                c = x[c];
            }
        }
        int ps = 0;
        for (int i = 0; i < n; i++) {
            ps += c2[i] + lp[i];
        }
        int a = max(maxcy, ps);

        printf("Case #%d: %d\n", t, a);

    }


    return 0;
}
