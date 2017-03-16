#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 4040;

vector<string> sh;
vector<string> a[700], b[700];
vector<string> c;

void pre()
{
    fstream cin("dict.txt", ios::in);

    string s;
    while (cin >> s) {
        if (s.length() <= 2u)
            sh.pb(s);
        else {
            a[(s[0]-'a')*26 + s[1]-'a'].pb(s);
            b[(s[1]-'a')*26 + s[2]-'a'].pb(s);
        }
        c.pb(s);
    }
}

int n;
string s;
int d[maxn][10];;

int solve()
{
    cin >> s;
    n = s.length();
    forn(i, n+1) forn(j, 5) d[i][j] = inf;
    d[0][4] = 0;

    forn(i, n) {
        vector<string> p = c;
        /*
        vector<string> p = sh;
        if (i < n-1)
            p.insert(p.end(), all(a[(s[i+0]-'a')*26 + s[i+1]-'a']));
        if (i < n-2)
            p.insert(p.end(), all(b[(s[i+1]-'a')*26 + s[i+2]-'a']));
        */
        
        
        forn(j, p.size()) if (i + (int)p[j].size() <= n) {
            if (p[j].size() > 1u && p[j][0] != s[i] && p[j][1] != s[i+1]) continue;
            vi misses(1, -100);
            bool bad_word = false;
            forn(k, p[j].size()) {
                if (p[j][k] != s[i+k]) {
                    if (i+k - misses.back() < 5) {
                        bad_word = true;
                        break;
                    }
                    misses.pb(i+k);
                }
                if (bad_word)
                    break;
            }
            if (bad_word)
                continue;

            forn(k, 5) if (d[i][k] != inf) {
                misses[0] = i-k-1;
                if (misses.size() > 1u && misses[1] - misses[0] < 5)
                    continue;
                int ni = i+p[j].size();
                int nk = min(4, ni - misses.back() - 1); // REALLY -1?
                d[ni][nk] = min(d[ni][nk], d[i][k] + (int)misses.size()- 1);
            }
        }
        //forn(k, 5) cout << d[i][k] << " "; cout << endl;
    }
    int res = inf;
    forn(i, 5) res = min(res, d[n][i]);
    return res;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    pre();

    int t;
    cin >> t;
    forn(i, t) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
        cerr << i << endl;
    }

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}
