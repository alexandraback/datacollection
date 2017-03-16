#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;

int cnt[1000];
int res[290];

string s;

void solve(int tn) {
    cin >> s;
    forn(i, 256) cnt[i] = 0, res[i] = 0;
    for (char c: s) ++cnt[tolower(c)];
    res[0] = cnt['z']; forn(i, res[0]) for (char c: "zero") --cnt[c];
    res[4] = cnt['u']; forn(i, res[4]) for (char c: "four") --cnt[c];
    res[3] = cnt['r']; forn(i, res[3]) for (char c: "three") --cnt[c];
    res[2] = cnt['w']; forn(i, res[2]) for (char c: "two") --cnt[c];
    res[1] = cnt['o']; forn(i, res[1]) for (char c: "one") --cnt[c];
    res[6] = cnt['x']; forn(i, res[6]) for (char c: "six") --cnt[c];
    res[7] = cnt['s']; forn(i, res[7]) for (char c: "seven") --cnt[c];
    res[9] = cnt['n']/2; forn(i, res[9]) for (char c: "nine") --cnt[c];
    res[8] = cnt['g']; forn(i, res[8]) for (char c: "eight") --cnt[c];
    res[5] = cnt['f']; forn(i, res[5]) for (char c: "five") --cnt[c];
    cout << "Case #" << tn << ": ";
    forn(i, 10) forn(j, res[i]) cout << i;
    cout << endl;
}

int main() {
#ifdef LOCAL
//     freopen("a.in", "r", stdin);
#endif

    int t;
    cin >> t;
    forn(i, t) solve(i+1);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}
