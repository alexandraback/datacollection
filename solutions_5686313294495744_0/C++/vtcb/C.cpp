#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for(int a = b; a < c; a++)

#define dbg(x) cerr << x << endl;
#define _ << ", " << 

typedef unsigned long long ull;
typedef pair<int, int> ii;

int n;
string a[1011];
string b[1011];

bool eq[2][1011][1011];

int main() {
    ios_base::sync_with_stdio(false);

    int T;

    cin >> T;

    fr(cas, 1, T+1) {
        cin >> n;
        fr(i, 0, n) cin >> a[i] >> b[i];

        fr(i, 0, n) {
            fr(j, 0, n) {
                eq[0][i][j] = eq[0][j][i] = a[i] == a[j];
                eq[1][i][j] = eq[1][j][i] = b[i] == b[j];
            }
        }
        int ans = 0;

        fr(mask, 0, 1 << n) {
            vector<int> real;
            vector<int> faked;

            fr(i, 0, n) {
                if(mask & (1 << i)) {
                    real.push_back(i);
                } else {
                    faked.push_back(i);
                }
            }

            bool ok = true;
            fr(i, 0, faked.size()) {
                bool can[2] = {false, false};
                bool cur = false;

                fr(j, 0, real.size()) {
                    can[0] = can[0] || eq[0][faked[i]][real[j]];
                    can[1] = can[1] || eq[1][faked[i]][real[j]];

                    cur = can[0] && can[1];
                    if(cur) break;
                }
                ok = ok && cur;
                if(!ok) break;
            }

            if(ok) {
                ans = max(ans, (int) faked.size());
            }
        }

        cout << "Case #" << cas << ": " << ans << endl;
    }

    return 0;
}
