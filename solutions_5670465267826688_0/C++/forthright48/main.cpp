/*
Name      : Mohammad Samiul Islam
CodeName  : forthright48

"To improve is to change; to be perfect is to change often."

- Winston Churchill
*/
/***********Template Starts Here***********/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp printf("Execution Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

int ext_gcd ( int A, int B, int *X, int *Y ){
    int x, y, u, v, m, n, a, b, q, r;
    x = 0; y = 1;
    u = 1; v = 0;
    for (a = A, b = B; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n) {
        q = b / a;
        r = b % a;
        m = x - (u * q);
        n = y - (v * q);
    }
    *X = x; *Y = y;
    return b;
}

inline vlong modInv ( int a, int m ) {
    int x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/***********Template Ends Here***********/

//1, i, j, k
//1, 2, 3, 4

int arr[5][5];

char buf[100000];
vlong l, x;

map < int, int > mp;
void findChar ( int f, int &a, int &b ) {
    mp.clear();
    int cur = 1;

    a = 0;
    while ( 1 ) {
        if ( mp.find ( cur ) != mp.end() ) {
            a = -1;
            return;
        }
        mp[cur] = 1;
        FOR(i,0,l-1) {
            char c = buf[i];
            int d;
            if ( c == '1' ) d = 1;
            else if ( c == 'i' ) d = 2;
            else if ( c == 'j' ) d = 3;
            else d = 4;

            int tcur = ABS(cur);

            int tcur2 = arr[tcur][d];
            if ( cur < 0 ) cur = tcur2 * -1;
            else cur = tcur2;

            if ( cur == f ) {
                b = i;
                return;
            }
        }
        a++;
    }
}

int calc() {
    int cur = 1;

    FOR(i,0,l-1) {
        char c = buf[i];
        int d;
        if ( c == '1' ) d = 1;
        else if ( c == 'i' ) d = 2;
        else if ( c == 'j' ) d = 3;
        else d = 4;

        int tcur = ABS(cur);

        int tcur2 = arr[tcur][d];

        if ( cur < 0 ) cur = tcur2 * -1;
        else cur = tcur2;

        //debug ( tcur, d, cur );
    }

    return cur;
}

int newPower ( int val, vlong p ) {
    if ( p == 1 ) return val;

    if ( p & 1 ) {
        int x = newPower( val, p - 1 );
        int abx = ABS(x);
        int abv = ABS(val);
        int y = arr[abv][abx];
        if ( x * val < 0 ) y *= -1;
        return y;
    }
    else {
        int x = newPower( val, p / 2 );
        int absx = ABS(x);
        int y = arr[absx][absx];
        if ( x * x < 0 ) y *= -1;

        return y;
    }
}

int main () {
    #ifdef forthright48
    freopen ( "C-small-attempt1.in", "r", stdin );
    freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    arr[1][1] = 1; arr[1][2] = 2; arr[1][3] = 3; arr[1][4] = 4;
    arr[2][1] = 2; arr[2][2] = -1; arr[2][3] = 4; arr[2][4] = -3;
    arr[3][1] = 3; arr[3][2] = -4; arr[3][3] = -1; arr[3][4] = 2;
    arr[4][1] = 4; arr[4][2] = 3; arr[4][3] = -2; arr[4][4] = -1;

    int kase, cnt = 0;
    scanf ( "%d", &kase );

    while ( kase-- ) {

        scanf ( "%lld %lld", &l, &x );

        scanf ( "%s", buf );

        int val = calc();
        val = newPower ( val, x );

        printf ( "Case #%d: ", ++cnt);

        if ( val != -1 ) {
            printf ( "NO\n" );
            continue;
        }

        int a, b;
        findChar ( 2, a, b );

        vlong total = l * x;
        if ( a == -1 || a * l + b + 1 > total ) {
            printf ( "NO\n" );
            continue;
        }

        vlong p = a * l + b + 1;

        reverse ( buf, buf + l );
        if ( buf[0] == 'k' ) {
            a = 0;
            b = 0;
        }
        else findChar( -4, a, b );
        if ( a == -1 || a * l + b + 1 > total ) {
            printf ( "NO\n" );
            continue;
        }

        vlong q = a * l + b + 1;

        if ( p + q >= total ) {
            printf ( "NO\n" );
            continue;
        }

        printf ( "YES\n" );

    }

    return 0;
}
