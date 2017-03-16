#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int, int> Pair;

#define var_dump(x) cerr<<#x<<": "<<x<<'\n'
#define arr_dump(x, n) {cerr<<#x<<"[]: ";for(int i=1;i<=n;++i) cerr<<x[i]<<" ";cerr<<'\n';}

const int MAXN = 100000;

string stra, strb;
long long MaxA[18], MaxB[18], MinA[18], MinB[18], Pw[18];

void Complete(string s, long long To[], int t) {
    for(int i = 0; i < 18; ++i) {
        if(i > 0) To[i] = To[i - 1];
        else To[i] = 0;

        if(s[i] != '?') {
            To[i] += Pw[i] * (s[i] - '0');
        } else {
            To[i] += Pw[i] * t;
        }
    }
}

pair<long long, long long> Solve() {
    Complete(stra, MinA, 0); Complete(strb, MinB, 0);
    Complete(stra, MaxA, 9); Complete(strb, MaxB, 9);

    long long pref = 0;

    long long diff = 1e18;
    pair<long long, long long> sol = {1e18, 1e18};

    for(int i = 17; i >= 0; --i) {

        for(int da = 0; da <= 9; ++da)
        for(int db = 0; db <= 9; ++db) {
            if(stra[i] != '?' && stra[i] != da + '0') continue;
            if(strb[i] != '?' && strb[i] != db + '0') continue;

            if(da == db) {
                if(i != 0) continue;
                return {pref + da, pref + da};
            }

            assert(da != db);


            long long a = pref + Pw[i] * da, b = pref + Pw[i] * db;
            if(i > 0) {
                if(da < db) {a += MaxA[i - 1]; b += MinB[i - 1];}
                else {a += MinA[i - 1]; b += MaxB[i - 1];}
            }

            if(diff > abs(b - a)) {
                diff = abs(b - a);
                sol = {1e18, 1e18};
            }
            if(diff == abs(b - a)) {
                sol = min(sol, make_pair(a, b));
            }
        }

        if(stra[i] == '?' && strb[i] == '?') pref += 0;
        else if(stra[i] == '?') pref += Pw[i] * (strb[i] - '0');
        else if(strb[i] == '?') pref += Pw[i] * (stra[i] - '0');
        else if(stra[i] != strb[i]) break;
        else pref += Pw[i] * (stra[i] - '0');
    }

    return sol;
}

void afis(long long x, int c) {
    if(c == 0) {
        return;
    }
    afis(x / 10, c - 1);
    cout << x % 10;
}

int32_t main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);


    int t;
    cin >> t;

    Pw[0] = 1;
    for(int i = 1; i < 18; ++i)
        Pw[i] = Pw[i - 1] * 10;

    for(int tt = 1; tt <= t; ++tt) {
        stra.clear(); strb.clear();
        cin >> stra >> strb;
        reverse(stra.begin(), stra.end());
        reverse(strb.begin(), strb.end());

        int ll = stra.length();
        for(int l = stra.length(); l < 18; ++l) {
            stra += '0';
            strb += '0';
        }

        auto ret = Solve();
        cout << "Case #" << tt << ": ";
        afis(ret.first, ll);
        cout << " ";
        afis(ret.second, ll);
        cout << '\n';
    }

    return 0;
}
