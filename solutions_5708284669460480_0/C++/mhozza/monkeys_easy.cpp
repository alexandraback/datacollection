#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<LL,LL> PLL;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<pair<LL,LL> > VPLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-11
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)
#define FORR(i, a, b) for (int i = (int) (a); i <= (int) (b); ++i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SIZE(x) ((int) ((x).size()))

#define PB push_back
#define MP make_pair

void o(int i, double x) {
    printf("Case #%d: %.8f\n", i + 1, x);
}

double p(const string &s, map<char, int> &keys, int k) {
    double pr = 1.0;
    FORE(it, s) {
        pr *= keys[*it]/float(k);
    }
    return pr;
}

void compute_pk(int s, const string &w, map<char, int> &keys, int k, vector<double> &pk, string str = "") {
    if (s>0) {
        FORE(c, keys) {
           compute_pk(s-1, w, keys, k, pk, str+c->first);
        }
    }
    else {
        int cnt = 0;
        FOR(i, SIZE(str)-SIZE(w)+1) {
            if (w == str.substr(i, SIZE(w))) {
                cnt++;
            }
        }
        pk[cnt] += p(str, keys, k);
    }
}

int main(){
    int tc;
    scanf("%d", &tc);
    FOR(t, tc) {
        int k, l, s;
        scanf("%d%d%d", &k, &l, &s);
        string kb, w;
        cin >> kb;
        cin >> w;
        map<char, int> keys;
        for (int i = 0; i < k; ++i)
        {
            if (keys.count(kb[i])) {
                keys[kb[i]] += 1;
            } else {
                keys[kb[i]] = 1;
            }
        }

        bool done = false;
        FORE(it, w) {
            if (!keys.count(*it)) {
                o(t, 0.0);
                done = true;
                break;
            }
        }
        if (done) {
            continue;
        }

        int overlap = 0;
        FORR(i, 1, l-1) {
            if (w.substr(i) == w.substr(0, l - i)) {
                overlap = l - i;
                break;
            }
        }

        int maxc = 1 + (s - l) / (l - overlap);
        vector<double> pk;
        pk.resize(maxc+1, 0);
        compute_pk(s, w, keys, k, pk);
        double expect = 0.0;
        FOR(i, maxc+1) {
            // cerr << i << " " << pk[i] << endl;
            expect += i * pk[i];
        }
        // cerr << maxc << " " << expect << endl;
        o(t, maxc-expect);
    }

    return 0;
}

