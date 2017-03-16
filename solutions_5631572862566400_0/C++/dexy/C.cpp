#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

typedef long long int64 ;
typedef unsigned long long uint64 ;
typedef pair<int, int> pint ;
typedef pair<int64, int64> pint64 ;
typedef vector<int> vint ;

#define px first
#define py second

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define REPD(i, n) for (int i = (n) ; i >= 0 ; i --)
#define FOR(i, a, b) for (int i = (a) ; i < (b) ; i ++)
#define FORD(i, a, b) for (int i = (a) ; i >= (b) ; i --)

#define MUL64(x, y) (((int64) (x)) * ((int64) (y)))
#define MULMOD(x, y, modul) (MUL64(x, y) % modul)
#define MUL(x, y) MULMOD(x, y, modul)
#define ADD(reg, val) { reg += val ; if (reg >= modul) reg -= modul ; }

#define SET(v, val) memset(v, val, sizeof(v)) ;
#define SIZE(v) ((int) (v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) { sort(ALL(v)) ; }
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }

#define BIG
string PROBLEM = "C" ;

#ifdef BIG
//ifstream in((PROBLEM + "-large.in").c_str()) ; ofstream out((PROBLEM + "-large.out").c_str()) ;
#endif

#ifndef BIG
ifstream in((PROBLEM + "-small.in").c_str()) ; ofstream out((PROBLEM + "-small.out").c_str()) ;
#endif


int n, p[1888], f[1888];

int main() {
  int numTests ;
  cin >> numTests ;
  FOR(test, 1, numTests + 1) {
    cin >> n;
    REP(u, n) {
        cin >> f[u];
        f[u]--;
        p[u]=u;
    }
    int ret = 0;
    do {
        int len = 0;

        for (int i = 2; i <= n ; i ++) {
                bool can = true;
                //cout << "start i:"<<i<<endl;
                //for (int j = 0; j < i; j++) cout << p[j] << " ";
                //cout << "   " << (((f[p[0]] == p[1] || f[p[0]] == p[i - 1]) && (f[p[i-1]]==p[0]||f[p[i-1]]==p[i-2]))) << "," << f[p[0]] << ","<<f[p[i-1]]<<endl;
            if ((f[p[0]] == p[1] || f[p[0]] == p[i - 1]) && (f[p[i-1]]==p[0]||f[p[i-1]]==p[i-2])){
                for (int j = 1; j < i-1 && can; j++) {
                    if (f[p[j]] == p[j-1] || f[p[j]] == p[j+1]) {
                        can = true;
                    } else {
                        //cout << "stopped " << j << ", " << p[j] << "," << p[j-1] << "," << p[j+1]<<endl;
                    can = false;}
                }
                //cout << "i:"<<i<<endl;
                //for (int j = 0; j < i; j++) cout << p[j] << " ";
                //cout << "    " << can <<endl;
                if (can) {
                    ret = MAX(ret, i);
                }
            }
        }

    } while (next_permutation(p, p + n));

    cout << "Case #" << test << ": " << ret << endl;
  }

  return 0;
}
