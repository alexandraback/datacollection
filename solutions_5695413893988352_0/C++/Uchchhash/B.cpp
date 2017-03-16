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

vector <int> a[2];
string s[2];
int ten[4]= {1, 10, 100, 1000};

void back(int i, int pos, int y) {
    if (pos == sz(s[i])) {
        a[i].pb(y);
        return;
    }
    if (s[i][pos] == '?') {
        rep(d, 10) {
            back(i, pos+1, y+ten[pos]*d);
        }
    } else {
        back(i, pos+1, y+ten[pos]*(s[i][pos]-'0'));
    }
}

int main () {
    std::ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    repi(cas, 1, tst+1) {
        cin >> s[0] >> s[1];
        a[0].clear(), a[1].clear();
        reverse(all(s[0]));
        reverse(all(s[1]));
        back(0, 0, 0);
        back(1, 0, 0);
        int mn = INT_MAX, c = -1, k = -1;
        rep(i, sz(a[0])) {
            rep(j, sz(a[1])) {
                if (mn > abs(a[0][i]-a[1][j])) {
                    mn = abs(a[0][i]-a[1][j]);
                    c = a[0][i];
                    k = a[1][j];
                } else if (mn == abs(a[0][i]-a[1][j])) {
                    if (c > a[0][i]) {
                        mn = abs(a[0][i]-a[1][j]);
                        c = a[0][i];
                        k = a[1][j];

                    } else if (c == a[0][i] && k > a[1][j]) {
                        mn = abs(a[0][i]-a[1][j]);
                        c = a[0][i];
                        k = a[1][j];
                    }
                }
            }
        }
        cout << "Case #" << cas << ": " << setfill('0') << setw(sz(s[0])) << c << " " << setw(sz(s[1])) << k << "\n";
    }
    return 0;
}
