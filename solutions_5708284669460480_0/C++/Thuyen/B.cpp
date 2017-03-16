#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(a) int(a.size())
#define reset(a, x) memset(a, x, sizeof(a))

#define FOR(i, a, b)   for(int i = a; i <= b; ++i)
#define FORD(i, a, b)  for(int i = a; i >= b; --i)
#define REP(i, n)      for(int i = 0, _n = n; i < _n; ++i)
#define REPD(i, n)     for(int i = n - 1; i >= 0; --i)
#define FORSZ(i, x)    for(int i = 0; i < sz(x); ++i)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vii;

#define oo 1000000007
#define eps 1E-9

int T, K, L, S;

int maxCnt;

string keys, target;

double res;

void process(int idx, string cur) {
    if (idx == S) {
//        cout << cur << endl;
        int cnt = 0;
        for (int i = 0; i <= cur.size() - target.size(); ++i) {
            bool ok = 1;
            for (int j = i; j < i + target.size(); ++j)
                if (cur[j] != target[j - i]) {
                    ok = 0;
                    break;
                }
            cnt += ok;
        }
        res = res + cnt;
        maxCnt = max(maxCnt, cnt);
        return;
    }
    for (int i = 0; i < keys.size(); ++i) {
        cur[idx] = keys[i];
        process(idx + 1, cur);
    }
}

int main() {
    #ifdef LOCAL_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> K >> L >> S;
        cin >> keys >> target;

        maxCnt = 0;

        res = 0;
        process(0, string(S, ' '));

        for (int i = 0; i < S; ++i)
            res /= K;

        printf("Case #%d: %.10f\n", t, maxCnt - res);
//        cout << maxCnt << endl;
    }
}
