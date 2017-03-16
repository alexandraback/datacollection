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
using namespace std;

void smain();
int main(){
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/A-large.in.txt","rt",stdin);
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
#define LL __int128
#define mp(a,b) make_pair(a,b)
#define INF 2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-6
#define N 111
/* --------- END TEMPLATE CODE --------- */

string naive(const string &s) {
    int n = s.length();
    int m = 1 << n;
    string res = s, p(n, ' ');
    deque<char> t;
    forn(mask, m) {
        t.clear();
        forn(i, n) { 
            if ((mask >> i) & 1) {
                t.push_back(s[i]);
            } else {
                t.push_front(s[i]);
            }
        }
        int i = 0;
        for (auto c : t) p[i++] = c;
        res = max(res, p);
    }
    return res;
}

deque<char> f(const string &s, int n) {
    if (n == 0) return deque<char>();
    int m = 0;
    forn(i, n) if (s[i] >= s[m]) m = i;
    deque<char> res = f(s, m);
    res.push_front(s[m]);
    for (int i = m + 1; i < n; ++i) res.push_back(s[i]);
    return res;
}

string solve(const string &s) {
    deque<char> t = f(s, s.length());
    string res;
    for (auto c : t) res.push_back(c);
    return res;
}

void smain() {
    string s;
    int n;
    cin >> n;
    for (int cas = 1; cin >> s; ++cas) {
        string res = solve(s);
        cout << "Case #" << cas << ": " << res << endl;
        cerr << "Case #" << cas << ": " << res << endl;
    }
}
