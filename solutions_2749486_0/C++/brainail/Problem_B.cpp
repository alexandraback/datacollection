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

// typedefs
typedef long long LL;
typedef long double LD;
typedef vector < int > VI;
typedef vector < string > VS;
typedef vector < long long > VLL;
typedef vector < long double > VLD;
typedef vector < vector < int > > VVI;
typedef vector < vector < string > > VVS;
typedef vector < vector < long long > > VVLL;
typedef vector < vector < long double > > VVLD;

// defines
#define FOREACH(it, v, type) for( type::iterator it = v.begin(); it != v.end() ; ++ it )
#define FORN(i, st, en) for( int i = (int)(st); i <= (int)(en); ++ i )
#define FORDN(i, en, st) for( int i = (int)(en); i >= (int)(st); -- i )
#define ZERO(a, w) memset(a, w, sizeof(a))
#define ALL(A) A.begin(), A.end()
#define SIZE(X) ((int) (X.size()))
#define LENGTH(X) ((int) (X.length()))
#define MP(X, Y) make_pair(X, Y)
#define TWOP(X) (1<<(X))
#define TWOLP(X) (((LL)(1))<<(X))
#define CONTAINB(MASK, X) (((MASK) & TWOP(X)) != 0)
#define CONTAINLB(MASK, X) (((MASK) & TWOLP(X)) != 0)
#define MSG(X) cout << #X << " = " << X << endl;

// templates
template<class T> inline void checkMin(T A, T & B) { if(A < B) B = A; }
template<class T> inline void checkMax(T A, T & B) { if(B > A) B = A; }
template<class T> inline T sqr(T X) { return X * X; }

template<class T> inline T GCD(T A,T B)	{
    if(A < 0) return GCD(-A, B); 
    if(B < 0) return GCD(A, -B);
    return (B == 0) ? A : GCD(B, A % B);
}

template<class T> inline T LCM(T A, T B) {
    if(A < 0) return LCM(-A, B);
    if(B < 0) return LCM(A, -B);
    return A * (B / GCD(A, B));
}

template<class T> inline T euclideExt(T A, T B, T & X, T & Y) {
    if(A < 0) {
        T D = euclideExt(-A, B, X, Y);
        X = -X; 
        return D;
    }
    if(B < 0) {
        T D = euclideExt(A, -B, X, Y);
        Y = -Y;
        return D;
    }
    if(B == 0) {
        X = 1, Y = 0;
        return A;
    } else {
        T D = euclideExt(B, A % B, X, Y);
        T Z = X; 
        X = Y, Y = Z - (A / B) * Y;
        return D;
    }
}

template<class T> string toString(T N) {
    ostringstream oSS;
    oSS << N; 
    oSS.flush();
    return oSS.str();
}

// pre functions
bool isUpperCase(char C) { return C >= 'A' && C <= 'Z'; }
bool isLowerCase(char C) { return C >= 'a' && C <= 'z'; }
bool isLetter(char C) { return (C >= 'A' && C <= 'Z') || (C >= 'a' && C <= 'z'); }
bool isDigit(char C) { return C >= '0' && C <= '9'; }
char toLowerCase(char C) { return (isUpperCase(C)) ? (C + 32) : C; }
char toUpperCase(char C) { return (isLowerCase(C)) ? (C - 32) : C; }
double toDouble(string S) { double N = 0; istringstream iSS(S); iSS >> N; return N; }
long long toLongLong(string S) { LL N = 0; istringstream iSS(S); iSS >> N; return N; }
long double toLongDouble(string S) { LD N = 0; istringstream iSS(S); iSS >> N; return N; }
int toInt(string S) { int N = 0; istringstream iSS(S); iSS >> N; return N; }

// consts
const string INPUT_FILE = "input_B.txt";
const string OUTPUT_FILE = "output_B.txt";

const LD PI = acos(-1.0);
const LD EPS = 1e-7;

const int SHIFT_X = 600;
const int SHIFT_Y = 600;

const int MAX_Q = 1000000 + 10;
const int MAX_N = 1400 + 10;

int que_X[MAX_Q], que_Y[MAX_Q], que_P[MAX_Q];
char que_D[MAX_Q];
int moves[MAX_N][MAX_N];

// variables
int numberTests;

int f_X, f_Y;

const int v_X [4] = {+0, +0, +1, -1};
const int v_Y [4] = {+1, -1, +0, +0};
const char v_D [4] = {'N', 'S', 'E', 'W'};

// main functions

int main() {

    freopen(INPUT_FILE.c_str(), "r", stdin);
    freopen(OUTPUT_FILE.c_str(), "w", stdout);

    // Main soultion :: begin
    cin >> numberTests;

    for (int test = 1; test <= numberTests; ++ test) {
        
	    cin >> f_X >> f_Y;

        int s_X = 0, s_Y = 0;

        f_X += SHIFT_X, f_Y += SHIFT_Y;
        s_X += SHIFT_X, s_Y += SHIFT_Y;
        
        int cQ = 0, nQ = 1;
        que_X[nQ] = s_X, que_Y[nQ] = s_Y;
        que_P[nQ] = -1, que_D[nQ] = '#';

        memset(moves, 0, sizeof(moves));

        moves[s_X][s_Y] = 1;

        int qIndex = -1;

        while (cQ < nQ) {
            ++ cQ;
            int c_X = que_X[cQ], c_Y = que_Y[cQ];
            for (int i = 0; i < 4; ++ i) {
                int n_X = c_X + v_X[i] * moves[c_X][c_Y], n_Y = c_Y + v_Y[i] * moves[c_X][c_Y];
                if (n_X < 0 || n_Y < 0 || n_X >= MAX_N || n_Y >= MAX_N || moves[n_X][n_Y] > 0) {
                    continue;
                }
                ++ nQ;
                que_X[nQ] = n_X, que_Y[nQ] = n_Y;
                que_P[nQ] = cQ, que_D[nQ] = v_D[i];
                moves[n_X][n_Y] = moves[c_X][c_Y] + 1;

                if (moves[f_X][f_Y] > 0) {
                    qIndex = nQ;
                    break;
                }

            }

            if (-1 != qIndex) {
                break;
            }

        }

        cout << "Case #" << test << ": ";

        string s_path = "";

        while (qIndex != 1) {
            s_path = que_D[qIndex] + s_path;
            qIndex = que_P[qIndex];
        }

        cout << s_path << endl;

    }
    // Main solution :: end

    return 0;

}

