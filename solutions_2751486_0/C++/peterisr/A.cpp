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

bool isVowel(char c) {
    return (
        c == 'a'
        || c == 'e'
        || c == 'i'
        || c == 'o'
        || c == 'u'
    );
}

UI getNValue(string S, UI n) {
    UI ss = S.size(), r = 0;

    bool isCons[ss];
    FOR(i,0,ss) {
        isCons[i] = (!isVowel(S[i]));
    }

    FOR(i,0,ss) {
        UI c = 0;
        FOR(j,i,ss) {
            if (isCons[j]) {
                c++;
            } else {
                c = 0;
            }
            if (c >= n) {
                r += (ss - j);
                break;
            }
        }
    }

    return r;
}

void solve(char *in, char *out) {
    if (in != NULL) {
        freopen(in, "r", stdin);
        freopen(out, "w", stdout);
    }

    UI T;
    cin >> T;
    FOR(i,1,T+1) {
        string S;
        UI n;
        cin >> S >> n;
        cout << "Case #" << i << ": " << getNValue(S, n) << endl;
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
    char *in = NULL, *out = NULL;
    if (argc == 3) {
        in = argv[1];
        out = argv[2];
    }

    tests();
    solve(in, out);
    return 0;
}
