#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

lol p[1100000], a[1100000], b[1100000];
lol code[200];
char matrix[100][100];

lol sign(lol a) {
    return (a > 0 ? 1: -1);
}

int main() {
    must;
//    inp("input.txt");
//    out("output.txt");
    lol t, tt, i, j, n, ans, l, x, ll, rr;
    string s, d;
    cin >> t;
    code[1] = 1; code['i'] = 2; code['j'] = 3; code['k'] = 4;
    matrix[1][1] = 1; matrix[1][2] = 'i'; matrix[1][3] = 'j'; matrix[1][4] = 'k';
    matrix[2][1] = 'i'; matrix[2][2] = -1; matrix[2][3] = 'k'; matrix[2][4] = -'j';
    matrix[3][1] = 'j'; matrix[3][2] = -'k'; matrix[3][3] = -1; matrix[3][4] = 'i';
    matrix[4][1] = 'k'; matrix[4][2] = 'j'; matrix[4][3] = -'i'; matrix[4][4] = -1;
    for(tt = 1; tt <= t; tt++) {
        ans = 0;
        cin >> l >> x >> s;
        d = "";
        if(x >= 20)
            x = (x - 20) % 20 + 20;
        while(x)
            d += s, x--;
        a[d.size()] = 1;
        for(i = d.size() - 1; i >= 0; i--)
            a[i] = sign(a[i + 1]) * matrix[code[d[i]]][code[abs(a[i + 1])]];
        b[0] = d[0];
        for(i = 1; i < d.size(); i++)
            b[i] = sign(b[i - 1]) * matrix[code[abs(b[i - 1])]][code[d[i]]];
        ll = d.size() + 5;
        rr = -5;
        for(i = 0; i < d.size(); i++) {
            if(i + 1 < d.size() && b[i] == 'i' && a[i + 1] == 'i')
                ll = min(ll, i);
            if(i > 0 && a[i] == 'k' && b[i - 1] == 'k')
                rr = max(rr, i);
        }
        cout << "Case #" << tt << ": " << (ll < rr ? "YES\n": "NO\n");
    }
}
