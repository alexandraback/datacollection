#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

pair<pair<int, int>, int> greedy(char *a, char *b) {
    int x(0), y(0), i;
    int px, py;
    for (i = 0; a[i]; i++) {
        px = x;
        py = y;
        if (px != py) {
            if (a[i] == '?') {
                if (px > py) { x = x * 10; }
                else { x = x * 10 + 9; }
            }
            else { x = x * 10 + a[i] - '0'; }
            if (b[i] == '?') {
                if (px > py) { y = y * 10 + 9; }
                else { y = y * 10; }
            }
            else { y = y * 10 + b[i] - '0'; }
        }
        else if (px == py) {
            if (a[i] != '?' && b[i] != '?') {
                x = x * 10 + a[i] - '0';
                y = y * 10 + b[i] - '0';
            }
            else if (a[i] == '?' && b[i] != '?') { x = y = x * 10 + b[i] - '0'; }
            else if (a[i] != '?' && b[i] == '?') { x = y = x * 10 + a[i] - '0'; }
            else if (a[i] == '?' && b[i] == '?') { x = y = x * 10; }
        }
    }
    return {{x, y}, abs(x-y)};
}


int main() {
    int t, tt, cc, cj, i, clen;
    cin >> tt;
    char c[100], j[100];
    xrep(t, 1, tt+1) {
        cc = cj = clen = 0;
        cin >> c >> j;
        int point = INF, e = 0;
        for (clen = 0; c[clen]; clen++);
        auto ans = greedy(c, j);
        for (i = 0; c[i]; i++) {
            if (c[i] != j[i] && c[i] != '?' && j[i] != '?') {
                point = i;
                e = c[i] > j[i];
                break;
            }
        }
        if (point != INF) {
            for (i = point - 1; i >= 0; i--) {
                if (c[i] != j[i]) {
                    if (e && c[i] != '9' && j[i] != '0') {
                        if (c[i] == '?') { c[i] = j[i] - 1; }
                        else if (j[i] == '?') { j[i] = c[i] + 1; }
                    }
                    else if (!e && c[i] != '0' && j[i] != '9') {
                        if (c[i] == '?') { c[i] = j[i] + 1; }
                        else if (j[i] == '?') { j[i] = c[i] - 1; }
                    }
                    break;
                }
                else if (c[i] == j[i] && c[i] == '?') {
                    if (e) {
                        c[i] = '0';
                        j[i] = '1';
                    }
                    else {
                        c[i] = '1';
                        j[i] = '0';
                    }
                    break;
                }
            }
        }
        auto ans2 = greedy(c, j);
        if (ans.second > ans2.second || (ans.second == ans2.second && ans2.first.first < ans.first.first) || (ans.second == ans2.second && ans.first.first == ans2.first.first && ans2.first.second < ans.first.second)) { ans = ans2; }
        cout << "Case #" << t << ": " << setfill('0') << setw(clen) << ans.first.first << ' ' << setfill('0') << setw(clen) << ans.first.second << endl;
    }
}
