#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <string>
#include <utility>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include <stdio.h>
#include <cstring>

#include <stdlib.h>
#include <time.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef unsigned char UC;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<UI> VUI;

#define DEBUG 1
#define F(i,n) for(int i=0;i<n;i++)
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define FORE(i,s,n) for(int i=s;i<=n;i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-1*(a)) : (a))
#define INSET(s, e) ((s).find(e) != (s).end())
#define INMAP(s, e) ((s).find(e) != (s).end())
#define TRACE(v) (cout << "TRACE(" << #v << "): " << v << endl)
#define TRACE1D(v,s) { cout << "TRACE1D(" << #v << ", " << (s) << "): "; F(i,s) cout << (v)[i] << " "; cout << endl; }
#define TRACE2D(v,s1,s2) { cout << "TRACE2D(" << #v << ", " << (s1) << ", " << (s2) << "): "; F(i,s1) { cout << endl << "\t"; F(j,s2) cout << v[i][j] << " "; } cout << endl; }
#define TRACE2DS(v) { cout << "TRACE2DS(" << #v << "): "; F(i,v.size()) { cout << endl << "\t"; F(j,v[i].size()) cout << v[i][j] << " "; } cout << endl; }
#define FOREACH(it, s) for (auto it = s.begin(); it != s.end(); it++)

ULL getRes(UI r, UI n, UI m, UI k, ULL M[20]) {
    UI res[n], rc = 0;
    UI count[100];
    memset(count, 0, sizeof count);

    for (UI i = m; i >= 2; i--) {
        F(j,k) {
            UI ic = 0;
            while (M[j] % i == 0) {
                M[j] /= i;
                ic++;
            }
            if (count[i] < ic) {
                for (int k = 0; k < ic - count[i]; k++) {
                    res[rc++] = i;
                }
                count[i] = ic;
            }
        }
    }

    ULL ret = 0;
    F(i,rc) {
        ret *= 10;
        ret += res[i];
    }
    while (rc < n) {
        ret *= 10;
        ret += m;
        rc++;
    }
    return ret;
}

void solve(char *in, char *out) {
    if (in != NULL) {
        freopen(in, "r", stdin);
    }

    if (out != NULL) {
        freopen(out, "w", stdout);
    }

    UI dummy, r, n, m, k;
    cin >> dummy >> r >> n >> m >> k;
    cout << "Case #1:" << endl;
    F(i,r) {
        ULL M[20];
        F(j,k) {
            cin >> M[j];
        }
        cout << getRes(r, n, m, k, M) << endl;
    }
}

void assert(bool b, const char *msg = NULL) {
    static int test = 0;
    test++;

    if (!b) {
        if (msg == NULL) {
            cout << "Error :: " << test << endl;
        } else {
            cout << "Error :: " << test << " :: " << msg << endl;
        }
    }
}

void tests() {

}

int main(int argc, char **argv) {
    //srand(time(NULL));
    tests();

    char *in, *out;
    if (argc == 3) {
        in = argv[1];
        out = argv[2];
    } else {
        in = NULL;
        out = NULL;
    }

    solve(in, out);
    return 0;
}
