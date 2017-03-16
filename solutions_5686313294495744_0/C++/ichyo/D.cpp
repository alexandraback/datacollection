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
    REP(casenum, T) {
        cout << "Case #" << casenum+1 << ": ";
        int N;
        cin >> N;
        vector<string> left(N);
        vector<string> right(N);
        REP(i, N) {
            cin >> left[i] >> right[i];
        }
        map<string, int> lk, rk;
        REP(i, N) {
            if(!lk.count(left[i])) {
                int t = lk.size();
                lk[left[i]] = t;
            }
            if(!rk.count(right[i])) {
                int t = rk.size();
                rk[right[i]] = t;
            }
        }
        vector<int> li(N), ri(N);
        REP(i, N) li[i] = lk[left[i]];
        REP(i, N) ri[i] = rk[right[i]];
        int dp[1 << 16] = {};
        REP(s, 1 << N) {
            REP(i, N) if(!(s >> i & 1)) {
                auto check = [&](vector<int>& v, int x) {
                    REP(k, N) if((s >> k & 1) && v[k] == x) {
                        return true;
                    }
                    return false;
                };
                if(check(li, li[i]) && check(ri, ri[i])) {
                    dp[s | (1 << i)] = max(dp[s | (1 << i)], dp[s] + 1);
                } else {
                    dp[s | (1 << i)] = max(dp[s | (1 << i)], dp[s] + 0);
                }
            }
        }
        cout << dp[(1 << N) - 1] << endl;
    }
    return 0;
}

