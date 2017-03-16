#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

struct quat {
    int sign, val;
};

quat operator*(const quat& a, const quat &b) {
    quat res;
    res.sign = a.sign ^ b.sign;

    if (a.val == 0 || b.val == 0) res.val = a.val + b.val;
    else if (a.val == b.val) { res.sign ^= 1; res.val = 0; }
    else  {
        if (a.val == 1) {
            if (b.val == 2) res.val = 3;
            else { res.sign ^= 1; res.val = 2; }
        }
        else if (a.val == 2) {
            if (b.val == 1) { res.sign ^= 1; res.val = 3; }
            else res.val = 1; 
        }
        else {
            if (b.val == 1) res.val = 2;
            else { res.sign ^= 1; res.val = 1; }
        }
    }
    return res;
}

const int MAXN = 1e4 + 100;

int l,x;
quat s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";

        cin >> l >> x;

        quat prod = (quat){0,0};
        forn(i,l) {
            char c; cin >> c;
            s[i] = (quat) {0, c - 'h'};
            prod = prod*s[i];
        }

        quat once = prod; prod = (quat){0,0};
        forn(_,x%4) prod = prod*once;

        if (prod.sign != 1 || prod.val != 0) cout << "NO" << endl;
        else {
            int pre = -1;
            prod = (quat){0,0};
            forn(i,4*l) {
                prod = prod*s[i%l];
                if (prod.sign == 0 && prod.val == 1) {
                    pre = i+1;
                    break;
                }
            }

            reverse(s,s+l);
            int suf = -1;
            prod = (quat){0,0};
            forn(i,4*l) {
                prod = s[i%l]*prod;
                if (prod.sign == 0 && prod.val == 3) {
                    suf = i+1;
                    break;
                }
            }

            if (pre != -1 && suf != -1 && pre+suf < l*x) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    
    return 0;
}
