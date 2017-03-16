#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>

#define LL long long
#define FN "ex"
#define MOD 1000000007

using namespace std;
LL d[300][300], to[300], hm[300], str[300], fin[300], ins[300];
string s;
LL T, n, m, ans, num, fail;

int main() {
    freopen(FN".in", "r", stdin);
    freopen(FN".out", "w", stdout);
    cin >> T;
    for (LL iter = 0; iter < T; iter++) {
        cin >> n;
        fail = 0;
        ans = 1;
        num = 0;
        for (LL i = 0; i < n; i++) {
            str[i] = 0;
            fin[i] = 0;
        }
        for (LL c = 'a'; c <= 'z'; c++) {
            to[c] = 0;
            hm[c] = 0;
            ins[c] = 0;
            for (LL c2 = 'a'; c2 <= 'z'; c2++) d[c][c2] = 0;
        }

        for (LL i = 0; i < n; i++) {
            cin >> s;
            LL l = s.length();
            str[i] = s[0];
            fin[i] = s[l - 1];
            for (LL j = 1; j < l - 1; j++) {
                if ((s[j] != str[i]) && (s[j] != fin[i])) {
                    if ((ins[s[j]] == 0) || (ins[s[j]] == i + 1)) ins[s[j]] = i + 1;
                    else fail = 1;
                }
            }
//            cerr << i + 1 << ") " << (char)str[i] << " " << (char)fin[i] << endl;
        }

        for (LL i = 0; i < n; i++) {
            if ((ins[str[i]] != 0) || (ins[fin[i]] != 0)) fail = 1;
        }

        for (LL i = 0; i < n; i++) d[str[i]][fin[i]]++;
        for (LL c = 'a'; c <= 'z'; c++) {
            LL temp = 0;
            for (LL c2 = 'a'; c2 <= 'z'; c2++) {
                if (c == c2) continue;
                temp += d[c][c2];
            }
            if (temp > 1) fail = 1;
            temp = 0;
            for (LL c2 = 'a'; c2 <= 'z'; c2++) {
                if (c == c2) continue;
                temp += d[c][c2];
            }
            if (temp > 1) fail = 1;
        }
        for (LL c = 'a'; c <= 'z'; c++) {
            if (d[c][c] == 0) continue;
            LL temp = 1;
            for (LL i = 1; i <= d[c][c]; i++) temp = (temp * i) % MOD;
            d[c][c] = temp;
            for (LL c2 = 'a'; c2 <= 'z'; c2++) {
                if (c == c2) continue;
                if (d[c][c2] != 0) {
                    d[c][c2] = (d[c][c2] * d[c][c]) % MOD;
                    d[c][c] = 0;
                    break;
                }
                if (d[c2][c] != 0) {
                    d[c2][c] = (d[c2][c] * d[c][c]) % MOD;
                    d[c][c] = 0;
                    break;
                }
            }
        }

        for (LL c = 'a'; c <= 'z'; c++) {
            if (d[c][c] != 0) {
                ans = (ans * d[c][c]) % MOD;
                d[c][c] = 0;
                num++;
            }
        }
        for (LL c = 'a'; c <= 'z'; c++) {
            for (LL c2 = 'a'; c2 <= 'z'; c2++) {
                if (d[c][c2] != 0) {
                    to[c] = c2;
                    hm[c] = d[c][c2];
                }
            }
        }

        for (LL c = 'a'; c <= 'z'; c++) {
            if (to[c] == 0) continue;
            if (to[to[c]] == 0) continue;
            if (to[to[c]] == c) fail = 1;
                hm[c] = (hm[c] * hm[to[c]]) % MOD;
                LL temp = to[c];
                to[c] = to[to[c]];
                to[temp] = 0;
                hm[temp] = 0;
                c--;
        }

        for (LL c = 'a'; c <= 'z'; c++) {
            if (to[c] != 0) {
                ans = (ans * hm[c]) % MOD;
                num++;
            }
        }
        for (LL i = 1; i <= num; i++) ans = (ans * i) % MOD;
//        cerr << num << endl;
        if (fail) cout << "Case #" << iter + 1 << ": 0" << endl;
        else cout << "Case #" << iter + 1 << ": " << ans << endl;
    }
}



