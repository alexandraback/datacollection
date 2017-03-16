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
const string INPUT_FILE = "inputC.txt";
const string OUTPUT_FILE = "outputC.txt";

template<class T> inline T gcd(T A, T B)	{
    if (A < 0) return gcd(-A, B); 
    if (B < 0) return gcd(A, -B);
    return (B == 0) ? A : gcd(B, A % B);
}

template<class T> inline T lcm(T A, T B) {
    if (A < 0) return lcm(-A, B);
    if (B < 0) return lcm(A, -B);
    return A * (B / gcd(A, B));
}

// MY
const int MAXN = 50 + 5;
char board [MAXN][MAXN];
int R, C, M;

void checkBoard() {
    int kMines = 0;
    _FORN(i, 0, R)
        _FORN(j, 0, C)
            kMines += board [i][j] == '*';
    assert(kMines == M);
    assert(board [R - 1][C - 1] == 'c');
}

void printBoard(bool isPossible) {
    if (!isPossible) {
        printf("Impossible\n");
        return;
    }

    _FORN(i, 0, R) {
        _FORN(j, 0, C) printf("%c", board [i][j]);
        printf("\n");
    }

    checkBoard();
}

// MAIN
int main() {
    freopen(INPUT_FILE.c_str(), "r", stdin);
    freopen(OUTPUT_FILE.c_str(), "w", stdout);   

    int T;
    scanf("%d", &T);

    FORN(testIndex, 1, T) {
        printf("Case #%d:\n", testIndex);
 
        scanf("%d %d %d", &R, &C, &M);

        int nR = R, nC = C, nM = M;
        bool changed = true;

        FILL(board, '.');
        board [R - 1][C - 1] = 'c';

        // Case -*01
        if (M == C * R - 1) {
            FILL(board, '*');
            board [R - 1][C - 1] = 'c';
            printBoard(true);
            continue;
        }

        while (changed) {
            changed = false;
            
            if (nM >= nC && nR > 3) { 
                _FORN(j, 0, C) board [R - nR][j] = '*'; 
                nM -= nC, -- nR, changed = true; 
            }

            if (nM >= nR && nC > 3) { 
                _FORN(i, 0, R) board [i][C - nC] = '*'; 
                nM -= nR, -- nC, changed = true; 
            } 
        }

        // Case *00
        if (1 == nC) {
            _FORN(i, R - nR, R - nR + nM) board [i][C - nC] = '*';
            printBoard(true);
            continue;
        }

        // Case *01
        if (1 == nR) {
            _FORN(j, C - nC, C - nC + nM) board [R - nR][j] = '*';
            printBoard(true);
            continue;
        }

        // Case *02
        if ((2 == nC || 2 == nR) && ((nM % 2) || (2 == nC * nR - nM))) {
            printBoard(false);
            continue;
        }

        // Case *03
        if (2 == nC) {
            _FORN(i, R - nR, (R - nR) + (nM / 2))
                _FORN(j, 0, C) board [i][j] = '*'; 
            printBoard(true);
            continue;
        }

        // Case *04
        if (2 == nR) {
            _FORN(j, C - nC, (C - nC) + (nM / 2))
                _FORN(i, 0, R) board [i][j] = '*'; 
            printBoard(true);
            continue;
        }

        // Case *0?
        if (nC > 3 && nR > 3) {
            assert(nM < min(nC, nR));
            _FORN(i, R - nR, R - nR + min(nM, nR - 2)) board [i][C - nC] = '*';
            if (nM > nR - 2) board [R - nR][C - nC + 1] = '*';
            printBoard(true);
            continue;
        }

        // Case *05
        if (nR > 3) {
            assert(nM < 3);
            _FORN(i, R - nR, R - nR + nM) board [i][C - nC] = '*';
            printBoard(true);
            continue;
        }

        // Case *06
        if (nC > 3) {
            assert(nM < 3);
            _FORN(j, C - nC, C - nC + nM) board [R - nR][j] = '*';
            printBoard(true);
            continue;
        }

        assert(3 == nC && 3 == nR);

        // Case *07
        if (nM > 5 || 2 == nM || 4 == nM) {
            printBoard(false);
            continue;
        }

        // Case *08
        if (0 == nM) {
            printBoard(true);
            continue;
        }

        // Case *09
        if (1 == nM) {
            board [R - nR][C - nC] = '*';
            printBoard(true);
            continue;
        }

        // Case *10
        if (3 == nM) {
            FILL(board [R - nR], '*');
            printBoard(true);
            continue;
        }

        // Case *11
        if (5 == nM) {
            FILL(board [R - nR], '*');
            board [R - nR + 1][C - nC] = '*';
            board [R - nR + 2][C - nC] = '*';
            printBoard(true);
            continue;
        }

        assert(0 != 0);
    }

    return 0;
}