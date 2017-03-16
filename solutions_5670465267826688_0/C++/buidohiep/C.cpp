#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define sz(x) (int)x.size()

typedef pair<int, int> II;
const int inf = 1e9;
const int Nmax = 10100;

const string dic = "ijk";
string s;
int n, signL[Nmax], signR[Nmax], pos[333];
char L[Nmax], R[Nmax];

char combine(char x, char y, int &sign) {
    if (x == '1') return y;
    if (y == '1') return x;
    if (x == y) {
        sign = -sign;
        return '1';
    }
    int posx = pos[x],
        posy = pos[y];
    if ((posx + 1) % 3 == posy) return dic[(posx + 2) % 3];
    sign = -sign;
    return dic[(posx + 1) % 3];
}

bool solve(){
    FOR(i, 0, 2) pos[dic[i]] = i;
    n = sz(s);
    if (n < 3) return false;
    L[0] = s[0];
    signL[0] = 1;
    R[n - 1] = s[n - 1];
    signR[n - 1] = 1;
    FOR(i, 1, n - 1) {
        signL[i] = signL[i - 1];
        L[i] = combine(L[i - 1], s[i], signL[i]);
    }
    REP(i, n - 2, 0) {
        signR[i] = signR[i + 1];
        R[i] = combine(s[i], R[i + 1], signR[i]);
    }
    FOR(i, 1, n - 2) if (signL[i - 1] == 1 && L[i - 1] == 'i') {
        int curSign = 1;
        char cur = '1';
        FOR(j, i, n - 2) {
            cur = combine(cur, s[j], curSign);
            if ((curSign == 1 && cur == 'j') && (signR[j + 1] == 1 && R[j + 1] == 'k')) return true;
        }
    }
    return false;
}

int main() {
  //  freopen("C-small-attempt1.in", "r", stdin);
  //  freopen("ans.out", "w", stdout);
    int test;
    cin >> test;
    FOR(t, 1, test) {
        int x;
        string s0;
        cin >> n >> x;
        cin >> s0;
        s = "";
        FOR(i, 1, x) s = s + s0;
        cout << "Case #" << t << ": ";
        if (solve()) cout << "YES" << endl; else cout << "NO" << endl;
    }
    return 0;
}
