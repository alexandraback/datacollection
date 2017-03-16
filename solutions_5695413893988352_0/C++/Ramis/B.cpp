#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
#include <stdlib.h>
using namespace std;

void smain();
int main(){
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/B-small-attempt1.in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#ifndef M_PI
#define M_PI 3.14159265358979311599796346854418516
#endif
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-9
#define N 20
/* --------- END TEMPLATE CODE --------- */
char a[N], b[N];
vector<pair<int, int> > d[N][N][N];

void upd(pair<int, int> &v, pair<int, int> x) {
    if (v.first == -1 || abs(x.first - x.second) < abs(v.first - v.second) || (abs(x.first - x.second) == abs(v.first - v.second) && x < v)) 
        v = x;
}
void calc(vector<pair<int, int> > &v, pair<int, int> x) {
    if (v.empty()) v.push_back(x);
    else {
        int df = v.front().first - v.front().second;
        if (df < 0) df = -df;
        if (abs(x.first - x.second) < df) {
            v.clear();
            v.push_back(x);
        } else if (abs(x.first - x.second) == df) {
            v.push_back(x);
        }
    }
}
string tos(int x, int n) {
    string res;
    for(; x; x /= 10) res.push_back(x % 10 + '0');
    for(; (int)res.length() < n; ) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}

pair<int, int> naive(int n) {
    pair<int, int> ans(-1, -1);
    forn(i, 1000) forn(j, 1000) {
        string ta = tos(i, n);
        if ((int)ta.length() != n) continue;
        bool ok = true;
        forn(k, n) if (a[k] != '?' && ta[k] != a[k]) ok = false;
        if (!ok) continue;
        string tb = tos(j, n);
        if ((int)tb.length() != n) continue;
        forn(k, n) if (b[k] != '?' && tb[k] != b[k]) ok = false;
        if (!ok) continue;
        upd(ans, mp(i, j));
    }
    return ans;
}

void smain() {
    int n;
    cin >> n;
    for (int cas = 1; cin >> a >> b; ++cas) {
        n = strlen(a);
        forn(i, n + 1) forn(j, 11) forn(k, 11) d[i][j][k].clear();
        d[0][0][0].push_back(mp(0, 0));
        forn(i, n) {
            forn(j, 10) forn(k, 10) for (auto it : d[i][j][k]) {
                forn(x, 10) if (a[i] == '?' || a[i] - '0' == x) {
                    forn(y, 10) if (b[i] == '?' || b[i] - '0' == y) {
                        int va = it.first * 10 + x;
                        int vb = it.second * 10 + y;
                        calc(d[i+1][x][y], mp(va, vb));
                    }
                }
            }
        }
        pair<int, int> ans(-1, -1);
        forn(i, 10) forn(j, 10) for (auto it : d[n][i][j]) {
            upd(ans, it);
        }
        /*pair<int, int> res = naive(n);
        if (res != ans) {
            cerr << "Expected " << tos(res.first, n) << ' ' << tos(res.second, n) << endl;
            cerr << "Found " << tos(ans.first, n) << ' ' << tos(ans.second, n) << endl;
            cerr << "For " << a << ' ' << b << endl;
            return;
        }*/

        string ra = tos(ans.first, n);
        string rb = tos(ans.second, n);
        cout << "Case #" << cas << ": " << ra << ' ' << rb << endl;
        cerr << "Case #" << cas << ": " << ra << ' ' << rb << endl;
    }
}
