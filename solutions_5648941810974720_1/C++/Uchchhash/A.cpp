#include <bits/stdc++.h>

using namespace std;

#define mem(a, v) memset(a, v, sizeof (a))
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define rep(i, n) for (int i = 0; i < int(n); i ++)
#define repi(i, a, n) for (int i = (a); i < int(n); i ++)
#define repe(x, v) for (auto x: (v))

string get_number(string s) {
    string ret = "";
    vector <int> cnt(26), ans(10);
    repe(c, s) {
        cnt[c-'A']++;
    }
    ans[0] = cnt['Z' - 'A'];
    cnt['E'-'A'] -= cnt['Z' - 'A'];
    cnt['R'-'A'] -= cnt['Z' - 'A'];
    cnt['O'-'A'] -= cnt['Z' - 'A'];
    cnt['Z'-'A'] = 0;

    ans[2] = cnt['W'-'A'];
    cnt['T'-'A'] -= cnt['W' - 'A'];
    cnt['O'-'A'] -= cnt['W' - 'A'];
    cnt['W'-'A'] = 0;

    ans[4] = cnt['U'-'A'];
    cnt['F'-'A'] -= cnt['U'-'A'];
    cnt['O'-'A'] -= cnt['U'-'A'];
    cnt['R'-'A'] -= cnt['U'-'A'];
    cnt['U'-'A'] = 0;

    ans[6] = cnt['X'-'A'];
    cnt['S'-'A'] -= cnt['X'-'A'];
    cnt['I'-'A'] -= cnt['X'-'A'];
    cnt['X'-'A'] = 0;

    ans[8] = cnt['G'-'A'];
    cnt['E'-'A'] -= cnt['G'-'A'];
    cnt['I'-'A'] -= cnt['G'-'A'];
    cnt['H'-'A'] -= cnt['G'-'A'];
    cnt['T'-'A'] -= cnt['G'-'A'];
    cnt['G'-'A'] = 0;

    ans[1] = cnt['O'-'A'];
    cnt['N'-'A'] -= cnt['O'-'A'];
    cnt['E'-'A'] -= cnt['O'-'A'];
    cnt['O'-'A'] =0;

    ans[3] = cnt['H'-'A'];
    cnt['T'-'A'] -= cnt['H'-'A'];
    cnt['R'-'A'] -= cnt['H'-'A'];
    cnt['E'-'A'] -= 2*cnt['H'-'A'];
    cnt['H'-'A'] = 0;

    ans[5] = cnt['F'-'A'];
    ans[7] = cnt['S'-'A'];
    ans[9] = (cnt['N'-'A']-cnt['S'-'A'])/2;
    rep(i, 10) {
        ret += string(ans[i], '0'+i);
    }
    return ret;
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    repi(cas, 1, tst+1) {
        string s;
        cin >> s;
        cout << "Case #" << cas << ": "<< get_number(s) << "\n";
    }
    return 0;
}
