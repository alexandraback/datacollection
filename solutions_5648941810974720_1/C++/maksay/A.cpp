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

    freopen("A-large.in", "r", stdin);
    freopen("output2.txt", "w", stdout);

    cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        cerr << tc << endl;
        cin >> s;

        VI st(26, 0);
        for(int i = 0; i < L(s); ++i) {
            st[s[i] - 'A']++;
        }

        int ord[10] = {0,2,6,4,5,7,3,8,1,9};
        string ans = "";
        for(int act = 0; act < 10; ++act) {
            while(1) {
                bool ok = 1;
                for(int i = 0; i < 26; ++i) {
                    if (st[i] < cnt[ord[act]][i]) {
                        ok = 0;
                    }
                }
                if (!ok) break;
                for(int i = 0; i < 26; ++i) {
                    st[i] -= cnt[ord[act]][i];
                }
                ans += (char)('0' + ord[act]);
            }
        }
        sort(all(ans));
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
