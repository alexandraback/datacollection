#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


vector<int> kmp(string s) { // compute the border array of S, res[i] = border of S[0..i]
    int n = s.length(), k = 0;
    vector<int> res(n, 0);
    for (int i=1; i<n; ++i) {
        while(k>0 && s[k] != s[i]) k = res[k-1];
        if (s[k] == s[i]) ++k;
        res[i] = k;
    }
    return res;
}

void solve(int t) {
    int k, l, s;
    string a, b;
    cin >> k >> l >> s;
    cin >> a;
    cin >> b;

    int table[100];
    for (char c='A'; c<='Z'; ++c) {
        table[c-'A'] = 0;
    }
    for (int i=0; i<k; ++i) {
        ++table[a[i]-'A'];
    }
    double prob = 1;
    for (int i=0; i<l; ++i) {
        prob *= (double)table[b[i]-'A'] / k;
    }

    if (prob == 0) {
        printf("Case #%d: %.7f\n", t, 0.);
        return;
    }

    vector<int> x = kmp(b);
    int save = x.back();
    
    double minus = prob * (s - b.length() + 1);
    double plus = 0.;
    if (s >= l) {
        plus += 1;
        s -= l;
        plus += s / (l - save); 
    }
    printf("Case #%d: %.7f\n", t, plus - minus);
}

int main() {
    int t;
    cin >> t;
    for (int tt=1; tt<=t; ++tt) {
        solve(tt);
    }
}
