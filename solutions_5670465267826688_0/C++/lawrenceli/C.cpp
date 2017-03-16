#include <bits/stdc++.h>
using namespace std;

int tab[5][5] = {{1, 2, 3, 4},
                 {2, -1, 4, -3},
                 {3, -4, -1, 2},
                 {4, 3, -2, -1}};

int sgn(int a) { return a<0 ? -1 : 1; }

int mult(int a, int b) {
    return sgn(a) * sgn(b) * tab[abs(a)-1][abs(b)-1];
}

typedef long long ll;

const int MAXN = 40100;

int L;
ll X;
int ar[MAXN], pre[MAXN], suf[MAXN];

int pw(int b, ll e) {
    if (!e) return 1;
    if (e&1) return mult(b, pw(b, e-1));
    int res = pw(b, e/2);
    return mult(res, res);
}

void go(int casenum) {
    cin >> L >> X;
    string s; cin >> s;
    assert(s.length() == L);
    for (int i=0; i<L; i++) ar[i] = ar[i+L] = ar[i+2*L] = ar[i+3*L] = s[i]-'i'+2;

    pre[0] = 1;
    for (int i=1; i<=4*L; i++) pre[i] = mult(pre[i-1], ar[i-1]);
    suf[4*L] = 1;
    for (int i=4*L-1; i>=0; i--) suf[i] = mult(ar[i], suf[i+1]);

    if (pw(pre[L], X) != -1) {
        printf("Case #%d: NO\n", casenum);
        return;
    }

    int a = -1, b = -1;
    for (int i=1; i<=4*L; i++)
        if (pre[i] == 2) { a = i; break; }
    for (int i=4*L-1; i>=0; i--)
        if (suf[i] == 4) { b = 4*L-i; break; }

    if (a == -1 || b == -1 || a+b >= L*X)
        printf("Case #%d: NO\n", casenum);
    else
        printf("Case #%d: YES\n", casenum);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i=1; i<=t; i++) go(i);
}
