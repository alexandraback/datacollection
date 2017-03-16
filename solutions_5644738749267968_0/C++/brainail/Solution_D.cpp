// INCLUDES
#include <functional>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cmath>
#include <ctime>

#include <numeric>
#include <iomanip>
#include <complex>
#include <float.h>
#include <cfloat>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdio>

#include <cstring>
#include <string>

#include <iterator>
#include <vector>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
using namespace std;

// TYPEDEFS
typedef long long LL;
typedef long double LD;         
typedef unsigned long UL;
typedef vector < int > VI;
typedef vector < string > VS;
typedef vector < long long > VLL;
typedef vector < long double > VLD;

// DEFINES
#define FORN(i, st, en) for(int i = (int) (st); i <= (int) (en); ++ i)
#define FORDN(i, en, st) for(int i = (int) (en); i >= (int) (st); -- i)
#define FORN_(i, st, en) for(int i = (int) (st); i <= (int) (en); i += 2)
#define FORDN_(i, en, st) for(int i = (int) (en); i >= (int) (st); i -= 2)
#define _FORN(i, st, en) for(int i = (int) (st); i < (int) (en); ++ i)
#define _FORDN(i, en, st) for(int i = (int) (en); i > (int) (st); -- i)
#define _FORN_(i, st, en) for(int i = (int) (st); i < (int) (en); i += 2)
#define _FORDN_(i, en, st) for(int i = (int) (en); i > (int) (st); i -= 2)
#define FILL(a, w) memset(a, w, sizeof(a))
#define ALL(A) A.begin(), A.end()
#define SIZE(X) ((int) (X.size()))
#define LENGTH(X) ((int) (X.length()))
#define MP(X, Y) make_pair(X, Y)
#define TWOP(X) (1<<(X))
#define TWOLP(X) (((LL)(1))<<(X))
#define CONTAINB(MASK, X) (((MASK) & TWOP(X)) != 0)
#define CONTAINLB(MASK, X) (((MASK) & TWOLP(X)) != 0)
#define MSG(X) cout << #X << " = " << X << endl;

// CONSTS
const LD PI = acos(-1.0);
const LD EPS = 1e-7;
const int INF = 1000000000;
const LL INFL = (LL) 1000000000 * (LL) 1000000000;
const string INPUT_FILE = "inputD.txt";
const string OUTPUT_FILE = "outputD.txt";

// MY
int N;
vector<double> naomi, ken;

int warGame() {
    vector<bool> used(N, false);
    int result = 0;

    _FORN(i, 0, N) 
        _FORN(j, 0, N)
            if (!used [j] && ken [j] > naomi [i]) {
                ++ result;
                used [j] = true;
                break;
            }

    return N - result;
}

int deceitfulWarGame() {
    vector<bool> used(N, false);
    int result = 0;

    _FORN(i, 0, N) {
        int targetIndex = -1;

        _FORN(j, 0, N)
            if (!used [j] && ken [j] < naomi [i]) {
                targetIndex = j;
                break;
            }

        if (targetIndex >= 0) {
            used [targetIndex] = true;
        } else {
            ++ result;

            FORDN(j, N - 1, 0)
                if (!used [j]) {
                    used [j] = true;
                    break;
                }
        }
    }

    return N - result;    
}

// MAIN
int main() {
    freopen(INPUT_FILE.c_str(), "r", stdin);
    freopen(OUTPUT_FILE.c_str(), "w", stdout);   

    int T;
    scanf("%d", &T);

    FORN(testIndex, 1, T) {
        scanf("%d", &N);
        naomi.resize(N), ken.resize(N);
        _FORN(i, 0, N) cin >> naomi [i];
        _FORN(i, 0, N) cin >> ken [i];
        sort(ALL(naomi)), sort(ALL(ken));
        printf("Case #%d: %d %d\n", testIndex, deceitfulWarGame(), warGame());
    }

    return 0;
}