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
const string INPUT_FILE = "input_A.txt";
const string OUTPUT_FILE = "output_A.txt";

const LD PI = acos(-1.0);
const LD EPS = 1e-7;

const int MAXN = 1000000 + 10;

// variables
int numberTests;

// main functions
int cons[MAXN], cons2[MAXN];
int f[MAXN][25];
int pw[60];

string sName;

int sLength;

int nV;

bool isConsonant(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

#define forr(i,x,y) for(int i=(int)(x); i<(int)(y); i++)

int rmq(int l, int r ) {
    if(l>r) swap(l,r);
    int len=(int)(log(r-l+1.0)/log(2.0));
    return max(f[l][len], f[r-pw[len]+1][len]);
}

int find_pos(int left, int right) {
    int ll = left;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (rmq(ll, middle) >= nV) {
            right = middle;
        } else {
            left = middle;
        }
    }

    if (rmq(ll, left) >= nV) {
        return left;
    } else if (rmq(ll, right) >= nV) {
        return right;
    } else {
        return -1;
    }

}

long long solve() {
    
    int n = sLength;
    forr(i,0,sLength) f[i][0] = cons[i];
    int lenSize=(int)(log(n+0.0)/log(2.0));
    pw[0]=1; 
    forr(i,1,lenSize+1) pw[i]=pw[i-1]*2;
    forr(len,1,lenSize+1) 
        forr(i,0,n-pw[len]+1) {
            f[i][len]=max(f[i][len-1],f[i+pw[len-1]][len-1]);
    }

    LL result = 0;

    for (int left = 0; left < sLength - nV + 1; ++ left) {
        int realLeft = left;
        if (cons[left] > 0) {
            if (cons2[left] - cons[left] + 1 >= nV) {
                result += (LL) (sLength - (left + nV - 1));
                continue;
            } else {
                realLeft += (cons2[left] - cons[left] + 1);
            }
        }

        int pos = find_pos(realLeft, sLength - 1);

        if (-1 == pos) {
            return result;
        }

        result += (LL) (sLength - pos);

    }

    return result;

}

int main() {

    freopen(INPUT_FILE.c_str(), "r", stdin);
    freopen(OUTPUT_FILE.c_str(), "w", stdout);

    // Main soultion :: begin
    scanf("%d\n", &numberTests);

    for (int test = 1; test <= numberTests; ++ test) {
        
	    getline(cin, sName);

        unsigned pos = sName.find(' ');
        nV = toInt(sName.substr(pos + 1));
        sName = sName.substr(0, pos);

        sLength = sName.length();

        int i = 0;
        while (i < sLength) {
            
            if (isConsonant(sName[i])) {
                cons[i] = 0;
                cons2[i] = 0;
                ++ i;
                continue;
            }

            int j = i;
            while (j < sLength && !isConsonant(sName[j])) {
                ++ j;
            }

            for (int q = i; q < j; ++ q) {
                cons[q] = q - i + 1;
                cons2[q] = j - i;
            }

            i = j;

        }

        cout << "Case #" << test << ": " << solve() << endl;

    }
    // Main solution :: end

    return 0;

}

