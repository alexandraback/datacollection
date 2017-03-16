#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
#include <climits>
using namespace std;
#define ll long long
#define x first
#define y second
#define pii pair<int, int>
#define pdd pair<double, double>
#define L(s) (int)(s).size()
#define VI vector<int>
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define inf 1000000000
int t;
string s;
int cnt[10][26];
inline void upd(string cur, int val) {
    for(int i = 0; i < L(cur); ++i) {
        cnt[val][cur[i] - 'A']++;
    }
}

map<VI, VI> dp;
map<VI, int> dig;
queue<VI > q;

int main() {
    upd("ZERO", 0);
    upd("ONE", 1);
    upd("TWO", 2);
    upd("THREE", 3);
    upd("FOUR", 4);
    upd("FIVE", 5);
    upd("SIX", 6);
    upd("SEVEN", 7);
    upd("EIGHT", 8);
    upd("NINE", 9);

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        cerr << tc << endl;
        cin >> s;

        dp.clear();
        VI st(26, 0);
        for(int i = 0; i < L(s); ++i) {
            st[s[i] - 'A']++;
        }

        while(!q.empty()) q.pop();
        q.push(st);
        bool fnd = 0;
        while(!q.empty()) {
            VI cur = q.front();
            q.pop();
            //for(int i = 0; i < 26; ++i) {
             //   cerr << cur[i] << " ";
            //}
            //cerr << endl;
            for(int val = 0; val < 10; ++val) {
                bool ok = 1;
                VI nxt = cur;
                for(int i = 0; i < 26; ++i) {
                    if (cnt[val][i] > cur[i]) {
                        ok = 0;
                        break;
                    }
                    nxt[i] -= cnt[val][i];
                }
                if (ok) {
                    if (!dp.count(nxt)) {
                        dp[nxt] = cur;
                        dig[nxt] = val;
                        q.push(nxt);
                        if (*max_element(all(nxt)) == 0) {
                            fnd = 1;
                            string ans = "";
                            while(nxt != st) {
                                ans += (char)('0' + dig[nxt]);
                                nxt = dp[nxt];
                            }
                            reverse(all(ans));
                            cout << "Case #" << tc << ": " << ans << endl;
                            break;
                        }
                    }
                }
            }
            if (fnd) break;
        }
    }
}
