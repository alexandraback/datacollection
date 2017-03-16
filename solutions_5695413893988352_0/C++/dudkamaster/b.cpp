#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

string c, j;

int ansc, ansj;

void read(){
    cin >> c >> j;
}

void calc(int pos, int curc, int curj) {
    if (pos == sz(c)) {
        if (abs(curc - curj) < abs(ansc - ansj)) {
            ansc = curc;
            ansj = curj;
        }
        if (abs(curc - curj) == abs(ansc - ansj)) {
            if (curc < ansc) {
                ansc = curc;
                ansj = curj;
            }
            if (curc == ansc) {
                if (curj < ansj) {
                    ansj = curj;
                    ansc = curc;
                }
            }
        }
        return;
    }
    forn(vc,10) {
        forn(vj,10) {
            int nc, nj;
            if (c[pos] == '?')
                nc = curc * 10 + vc;
            else
                nc = curc * 10 + c[pos] - '0';
            if (j[pos] == '?')
                nj = curj * 10 + vj;
            else
                nj = curj * 10 + j[pos] - '0';
            calc(pos + 1, nc, nj);
        }
    }
}

string getval(int len, int val) {
    stringstream ss;
    ss << val;
    string res;
    ss >> res;
    while (sz(res) < len) {
        res = "0" + res;
    }
    return res;
}
void solve(){
    ansc = 0;
    ansj = INF;
    calc(0, 0, 0);
    cout << getval(sz(c), ansc) << ' ' << getval(sz(c), ansj) << endl;
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int t;
    scanf("%d", &t);
    forn(i,t) {
        printf("Case #%d: ", i+1);
        read();
        solve();
    }
    return 0;
}
