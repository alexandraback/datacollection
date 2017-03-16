#include <cstdio>
#include <utility>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int (x)=(b); x<=(e); ++(x))
#define FORD(x, b, e) for(int (x)=(b); x>=(e); --(x))
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define PII pair<int, int>

typedef long double LD;

int main() {
    // string s;
    // cin >> s;
    // int n = s.size();
    // VI P(n);
    // P[0] = -1;
    // int i = 1, j = 0;
    // while (i < n) {
        // while (j >= 0 && s[i] != s[j])
            // j = P[j];
        // P[++i] = ++j;
    // }
    // REP(i, n+1)
        // cout << i << ": " << P[i] << endl;
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int K, L, S;
        cin >> K >> L >> S;
        string kb, tg;
        cin >> kb >> tg;

        VI P(L + 1, 0);
        P[0] = -1;
        int i = 1, j = 0;
        while (i < L) {
            while (j >= 0 && tg[i] != tg[j])
                j = P[j];
            P[++i] = ++j;
        }
        vector<vector<LD>> E(L, vector<LD>(S+1));
        REP(i, L)
            E[i][0] = 0;
        for (int j = 1; j <= S; j++) {
            for (int i = 0; i < L; i++) {
                E[i][j] = 0;
                for (int k = 0; k < K; k++) {
                    int x = i;
                    while (x >= 0 && tg[x] != kb[k])
                        x = P[x];
                    x++;
                    if (x == L)
                        E[i][j] += (LD)1 / K * (1 + E[P[L]][j-1]);
                    else
                        E[i][j] += (LD)1 / K * E[x][j - 1];
                }
            }
        }
        P[0] = 0;
        i = 0;
        j = 0;
        int m = 0;
        bool ok = true;
        for (auto &&c : tg) {
            bool ok1 = false;
            for (auto &&c1 : kb)
                if (c == c1)
                    ok1 = true;
            ok = ok && ok1;
        }
        if (ok) {
            while (i < S) {
                if (i + (L - j) <= S) {
                    i += L - j;
                    j = P[L];
                    m++;
                }
                else break;
            }
        }
        cout << fixed;
        cout.precision(20);
        cout << "Case #" << z << ": " << m - E[0][S] << endl;
    }
    return 0;
}
