// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

int main(){
    iostream_init();
    int T;
    cin >> T;
    REP(testnum, T) {
        cout << "Case #" << testnum+1 << ": ";

        string s;
        cin >> s;
        vector<string> v = {
            "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
        };
        map<char, int> cnt;
        REP(i, s.size()) {
            cnt[s[i]] ++;
        }
        vector<int> ans(10);
        string key = "ZWUXG";
        REP(i, key.size()) {
            ans[2 * i] = cnt[key[i]];
        }

        REP(i, key.size()) {
            int k = 2 * i;
            for(char c : v[k]) {
                cnt[c] -= ans[k];
            }
        }

        string key2 = "OTFS";
        REP(i, key2.size()) {
            int k = i * 2 + 1;
            ans[k] = cnt[key2[i]];
            for(char c : v[k]) {
                cnt[c] -= ans[k];
            }
        }

        ans[9] = cnt['E'];

        REP(i, 10) {
            REP(_, ans[i]) {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}

