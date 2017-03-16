#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define pb push_back
#define mp make_pair
#define DEBUG
#ifdef DEBUG
    #define debug(x) cerr << #x << " = " << (x) << endl;
#else
    #define debug(x)
#endif


#define PROBLEM_NAME "C"

int main(){
    ios_base::sync_with_stdio(false);

    freopen(PROBLEM_NAME".test.in", "r", stdin);
    freopen(PROBLEM_NAME".test.out", "w", stdout);

    ll T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        int j, p, s, k;
        cin >> j >> p >> s >> k;

        vector<vector<int>> S;

        for (int a = 0; a < j; a++) {
            for (int b = 0; b < p; b++) {
                for (int c = 0; c < s; c++) {
                    S.pb({a + 1, b + 1, c + 1});
//                    cout << S[S.size() - 1][0] << " " << S[S.size() - 1][1] << " " << S[S.size() - 1][2] << " " << endl;
                }
            }
        }

        vector<vector<int>> best;

        for (int m = 0; m < 1 << S.size(); m++) {
            if (__builtin_popcount(m) <= best.size()) {
                continue;
            }

            bool ok = true;

            int freq[4 * 4 * 4];
            memset(freq, 0, sizeof(freq));

            for (int i = 0; i < S.size(); i++) {
                if ((1 << i) & m) {
                    const auto& x = S[i];
                    freq[16 * x[0] + 4 * x[1] +    0]++;
                    freq[16 * x[0] + 4 *    0 + x[2]]++;
                    freq[16 *    0 + 4 * x[1] + x[2]]++;
                }
            }

            for (int i = 0; i < 4 * 4 * 4; i++) {
                if (freq[i] > k) {
//                    cout << "! " << x[0] << " "<< x[1] << " " << x[2] << " -> " << ms.count(x) << endl;
                    ok = false;
                    break;
                }
            }

            if (ok) {
                best.resize(0);
                for (int i = 0; i < S.size(); i++) {
                    if ((1 << i) & m) {
                        best.pb(S[i]);
                    }
                }
            }
        }

        cout << "Case #" << test << ": " << best.size() << endl;
        for (const auto& x : best) {
            cout << x[0] << " " << x[1] << " " << x[2] << endl;
        }
    }

    return 0;
}
