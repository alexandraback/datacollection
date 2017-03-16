#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

const int maxn = 1005;

int n;
int P[maxn], D[maxn], N[maxn];
bool in[maxn], cyc[maxn];
int stk[maxn], sze;
int ma2[maxn];

void go(int casenum) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        P[i]--;
    }
    memset(D, 0, sizeof(D));
    memset(N, 0, sizeof(N));
    memset(in, 0, sizeof(in));
    memset(cyc, 0, sizeof(cyc));
    memset(ma2, 0, sizeof(ma2));
    sze = 0;

    for (int i = 0; i < n; i++)
        if (!D[i]) {
            int c = i;
            while (1) {
                if (D[c]) {
                    for (int j = 0; j < sze; j++) {
                        D[stk[j]] = D[c] + sze - j;
                        N[stk[j]] = cyc[c] ? c : N[c];
                        in[stk[j]] = 0;
                    }
                    sze = 0;
                    break;
                } else if (in[c]) {
                    int x = 0;
                    for (int j = 0; j < sze; j++)
                        if (stk[j] == c) {
                            for (int k = j; k < sze; k++)
                                cyc[stk[k]] = 1;
                            x = sze - j;
                            break;
                        }
                    assert(x);

                    //cout << sze << endl;

                    for (int j = 0; j < sze; j++) {
                        //cout << stk[j] << endl;
                        D[stk[j]] = max(x, sze - j);
                        N[stk[j]] = cyc[stk[j]] ? stk[j] : c;
                        in[stk[j]] = 0;
                    }
                    sze = 0;
                    break;
                } else {
                    stk[sze++] = c;
                    in[c] = 1;
                    c = P[c];
                }
            }
        }

    int ma = 0;
    for (int i = 0; i < n; i++) {
        //cout << D[i] << endl;
        int x = N[i];
        //cout << i << ' ' << x << endl;
        if (P[P[x]] == x)
            ma2[x] = max(ma2[x], D[i] - 1);
        else if (cyc[i])
            ma = max(ma, D[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) sum += ma2[i];

    cout << "Case #" << casenum << ": " << max(ma, sum) << '\n';
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) go(i);
}
