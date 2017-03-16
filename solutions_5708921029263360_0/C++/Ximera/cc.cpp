#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int c[3][15][15];
//vector<pair<int, pair<int, int>>> ans;
int j, p, s, k, ans;
vector<vector<vector<int>>> used;
vector<pair<int, pair<int, int>>> v, d;

void rec(int cur, int jj, int pp, int ss) {
    if(jj == j + 1) {
        if(cur > ans) {
            ans = cur;
            d = v;
        }
    } else if(pp == p + 1) {
        rec(cur, jj + 1, 1, 1);
    } else if(ss == s + 1) {
        rec(cur, jj, pp + 1, 1);
    } else {
        if(c[0][jj][pp] < k && c[1][jj][ss] < k && c[2][pp][ss] < k) {
            c[0][jj][pp]++;
            c[1][jj][ss]++;
            c[2][pp][ss]++;
            v.pb({jj, {pp, ss}});
            rec(cur + 1, jj, pp, ss + 1);
            v.pop_back();
            c[0][jj][pp]--;
            c[1][jj][ss]--;
            c[2][pp][ss]--;
        }
        rec(cur, jj, pp, ss + 1);
    }
}

int main() {
inp("input.txt");
out("output1.txt");
    int t;
    used.resize(20);
    for(t = 0; t < 20; t++) {
        used[t].resize(20);
        for(int tt = 0; tt < 20; tt++)
            used[t][tt].resize(20);

    }

    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++) {
        scanf("%d%d%d%d", &j, &p, &s, &k);
        ans = 0;
        d.clear();
        rec(0, 1, 1, 1);
        cerr << tt << "\n";
        printf("Case #%d: %d\n", tt, ans);
        for(auto x: d) {
            printf("%d %d %d\n", x.fi, x.se.fi, x.se.se);
        }
   }
    return 0;
}
