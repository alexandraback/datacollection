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

string s, d;
lol const INF = (lol) INFINITY;
lol ans;
string ansS, ansD;

void solve(int cur, int dif) {
    if(abs(dif) >= ans)
        return;
    if(cur == s.size()) {
        if(abs(dif) < ans || (abs(dif) == ans && ansS < s) || (abs(dif) == ans && ansS == s && ansD < d)) {
            ansS = s;
            ansD = d;
            ans = abs(dif);
        }
        return;
    }
    dif *= 10;
//    cout << cur << ' ' << dif << "\n";
    for(int l = '0'; l <= '9'; l++) {
        int flag = 0;
        if(s[cur] != '?') {
            l = s[cur];
            flag |= 1;
        }
        for(int r = '0'; r <= '9'; r++) {
            if(d[cur] != '?') {
                r = d[cur];
                flag |= 2;
            }
            if(flag == 3 || dif == 0 || abs(dif + l - r) <= abs(dif)) {
                int prs = s[cur];
                int prd = d[cur];
                s[cur] = l;
                d[cur] = r;
                solve(cur + 1, dif + l - r);
                s[cur] = prs;
                d[cur] = prd;
            }
            if(d[cur] != '?') {
                flag &= 1;
                break;
            }
        }

        if(s[cur] != '?')
            break;
    }

}

int main() {
    inp("input.txt");
    out("output.txt");
    int t, tt;
    cin >> t;
    for(tt = 1; tt <= t; tt++) {
        cin >> s >> d;
        assert(s.size() == d.size());
        ans = INF;
        solve(0, 0);
        cout << "Case #" << tt << ": " << ansS << ' ' << ansD << "\n";
    }
    return 0;
}
