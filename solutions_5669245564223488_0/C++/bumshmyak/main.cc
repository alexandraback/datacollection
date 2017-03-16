// ptcxvmat 
// 1271 


#include <iostream>
#include <cmath>
#include <vector>
#include <memory.h>
#include <iterator>
#include <sstream>

// 7
// iivvvv vvvvvvvgg ggggggq qqqqpp qqkkkkkkk   ppppppppppbbbbbb bbeeeeeee

using namespace std;

typedef long long ll;

const int MOD = 1000000007; 

char b[101][2];

int main() {
    int n_tests;
    cin >> n_tests;
    for (int t = 1; t <= n_tests; ++t) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < a[i].size(); ++j) {
                a[i][j] -= 'a';
            }
        }

        int have = 0;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            int d = 0;
            for (int j = 0; j + 1 < a[i].size(); ++j) {
                if (a[i][j] != a[i][j + 1]) {
                    ++d;
                }
            }
            if (d > 1) {
                int d1 = 0;
                for (int j = 0; j + 1 < a[i].size(); ++j) {
                    if (a[i][j] != a[i][j + 1]) {
                        d1++;
                        if (d1 < d) {
                            if (have & (1 << a[i][j + 1])) {
                                good = false;
                            }
                            have |= (1 << a[i][j + 1]);
                        }
                    }
                }

            }
        }
        memset(b, 0, sizeof(b));

        int ans = 0;
        if (good) {
            for (int i = 0; i < n; ++i) {
                b[i][0] = a[i][0];
                b[i][1] = a[i][a[i].size() - 1];
            }
            vector<int> p(n);
            for (int i = 0; i < n; ++i) {
                p[i] = i;
            }

            do {
                good = true;
                int have = 0;
                int cur;
                int next;
                cur = b[p[0]][0];
                next = b[p[0]][1];
                have |= (1 << cur);
                have |= (1 << next);

                for (int i = 1; i < n && good; ++i) {
                    cur = b[p[i]][0];
                    if (cur != next) {
                        if (have & (1 << cur)) {
                            good = false;
                        }
                    }
                    next = b[p[i]][1];
                    if (cur != next) {
                        if (have & (1 << next)) {
                            good = false;
                        }
                    }
                    have |= (1 << cur);
                    have |= (1 << next);                    
                }             
                ans += good;
            } while (next_permutation(p.begin(), p.end()));
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}

