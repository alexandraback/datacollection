#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(a) int(a.size())
#define pb push_back

string C, J;
ll res, opC, opJ, n;

void optimize(string & C, string & J, int i) {
    int si;
    if (C[i] < J[i]) si = -1;
    else si = 1;
    
    if (si == -1) {
        for (int j = i; j < n; j++) {
            if (C[j] == '?') C[j] = '9';
            if (J[j] == '?') J[j] = '0';
        }
    }
    else {
        for (int j = i; j < n; j++) {
            if (C[j] == '?') C[j] = '0';
            if (J[j] == '?') J[j] = '9';
        }
    }
}

ll toNum(string s) {
    ll res = 0;
    int n = sz(s);
    for (int i = 0; i < n; i++)
        res = res * 10LL + (s[i] - '0');
    return res;
}

string dep(string a, int n) {
    while (sz(a) < n) a = "0" + a;
    return a;
}

string toString(ll x) {
    if (x == 0) return "0";
    string res = "";
    while (x) {
        res = char(x % 10 + '0') + res;
        x /= 10;
    }
    return res;
}

void checkGood(string CC, string JJ) {
    ll c = toNum(CC), j = toNum(JJ);
    ll cur = abs(c - j);
    if (cur < res || (cur == res && c < opC) || (cur == res && c == opC && j < opJ)) {
        res = cur;
        opC = c;
        opJ = j;
    }
}

void dq(int pos, string C, string J) {
//    cout << C << " " << J << endl;
    if (C[pos] != '?' && J[pos] != '?' && J[pos] != C[pos]) {
        optimize(C, J, pos);
        checkGood(C, J);
        return;
    }
    if (pos == n) {
        checkGood(C, J);
        return;
    }
    if (C[pos] != '?') {
        J[pos] = C[pos];
        dq(pos + 1, C, J);
        
        if (C[pos] != '0') {
            J[pos] = C[pos] - 1;
            string CC = C, JJ = J;
            optimize(CC, JJ, pos);
            checkGood(CC, JJ);
        }
        
        if (C[pos] != '9') {
            J[pos] = C[pos] + 1;
            string CC = C, JJ = J;
            optimize(CC, JJ, pos);
            checkGood(CC, JJ);
        }
    }
    else if (J[pos] != '?') {
        C[pos] = J[pos];
        dq(pos + 1, C, J);
        
        if (J[pos] != '0') {
            C[pos] = J[pos] - 1;
            string CC = C, JJ = J;
            optimize(CC, JJ, pos);
            checkGood(CC, JJ);
        }
        
        if (J[pos] != '9') {
            C[pos] = J[pos] + 1;
            string CC = C, JJ = J;
            optimize(CC, JJ, pos);
            checkGood(CC, JJ);
        }
    }
    else {
        string CC = C, JJ = J;
        CC[pos] = '1', JJ[pos] = '0';
        optimize(CC, JJ, pos);
        checkGood(CC, JJ);
        CC = C, JJ = J; 
        CC[pos] = '0', JJ[pos] = '1';
        optimize(CC, JJ, pos);
        checkGood(CC, JJ);
        C[pos] = J[pos] = '0';
        dq(pos + 1, C, J);
    }
}

void solve() {

    n = sz(C);
    res = 1e9, opC = 1e9, opJ = 1e9;
    dq(0, C, J);
    
    cout << dep(toString(opC), n) << " " << dep(toString(opJ), n);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; cin >> T;
    for (int te = 1; te <= T; te++) {
        cin >> C >> J;
        cout << "Case #" << te << ": ";
        solve();
        cout << endl;
    }
    
    return 0;
}

