

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

vv<ld> a, b, a2, b2;

void solve() {
    int n;
    scanf("%d", &n);
    db(n);
    a.clear(); b.clear();
    rep (i, n) { a.pb(0); scanf("%Lf", &a.back()); db(a[i]); }
    rep (i, n) { b.pb(0); scanf("%Lf", &b.back()); db(b[i]); }
    sort(all(a));
    sort(all(b));
    int INF = 10000;

    a2 = a; b2 = b;
    int war = 0;
    int decwar = 0;
    rep (i, n) {
        ld val = a[(n-1)-i];
        db(val<<" "<<i<<" "<<a[i]);
        int cand = -1;
        int mincand = -1;
        rep (j, n) {
            if (cand == -1 && b[j] > val && b[j] < INF) {
                cand = j;
            }
            if (mincand == -1 && b[j] < INF)
                mincand = j;
        }
        db(cand<<" "<<val<<" "<<b[cand])

        if (cand >= 0) {
            b[cand] = INF;            
        }
        else {
            b[mincand] = INF;
            war++;
        }
    }
    a = a2; b = b2;
    if (cond) {
        rep (i, n) printf("%Lf ", a[i]); printf("\n");
        rep (i, n) printf("%Lf ", b[i]); printf("\n");
    }
    rep (i, n) {
        if (a.back() > b.back()) {
            a.pop_back();
            b.pop_back();
            decwar++;
            continue;
        }

        if (a[0] < b.back()) {

        }
        else decwar++;
        a.erase(a.begin(), a.begin() + 1);
        b.pop_back();
    }
   
    printf("%d %d", decwar, war);

}

int main(int argc, char ** argv) {
    //  freopen("../1.in","r",stdin); 
    //  freopen("../2.in","r",stdin); 
    //  freopen("../3.in","r",stdin); 
    //  freopen("../D-small.in","r",stdin); freopen("../D-small.out","w",stdout);
     freopen("../D-small-attempt0.in","r",stdin);freopen("../D-small-attempt0.out","w",stdout);
    //  freopen("../D-small-attempt1.in","r",stdin);freopen("../D-small-attempt1.out","w",stdout);
    //  freopen("../D-small-attempt2.in","r",stdin);freopen("../D-small-attempt2.out","w",stdout);
    //  freopen("../D-large.in","r",stdin); freopen("../D-large.out","w",stdout)

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        if (cond)
            cerr << __LINE__ << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}

