#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

using namespace std;

#define ll          long long
#define VI          vector<int>
#define ALL(a)      (a).begin(), (a).end()
#define SORT(a)     sort( ALL(a) )
#define PB          push_back
#define FOR(i,a,b)  for( int i = (a); i < (int)(b); i++ )
#define dump_(x)     cerr << #x << " = " << (x) << " ";
#define dump(x)     cerr << #x << " = " << (x) << endl
#define dump_vec(x) FOR(zZz,0,x.size()) cout << x[zZz] << " "; cout << endl

char inp[500000];

template< typename type > type readOne()
{
    type res;
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    ss >> res;
    return res;
}

template< typename type > vector<type> readMulti()
{
    vector<type> res;
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    for ( type t; ss >> t; )
        res.push_back( t );
    return res;
}

#define CSIZE 100
ll choose[ CSIZE+1 ][ CSIZE+1 ];
void choose_init()
{
    memset( choose, 0, sizeof( choose ) );
    for ( int i = 0; i <= CSIZE; i++ ) {
        choose[i][0] = 1;
        for ( int j = 1; j <= i; j++ )
            choose[i][j] = ( choose[i-1][j-1] + choose[i-1][j] );
    }
}

//
//
// LET'S START
//
//

double dp[1000009];

double doCase()
{
    int N, X, Y;
    vector<int> tmp = readMulti<int>();
    N = tmp[0];
    X = tmp[1];
    Y = tmp[2];

    int dis = abs(X) + abs(Y);
    int prevK = 0;
    int K = 0;
    for (int i = 0; i <= dis; i += 2) {
        prevK = K;
        K += 4 * i + 1;
    }

//    cerr << N << " => K = " << K << endl;
    
    if (N >= K) return 1;
    if (N <= prevK) return 0;
//    if (X == 0 && N < K) return 0;

    int pile = Y + 1;
    
    // pile以上 / (N - prevK) がこっちにくる確率

    // t = (K - prevK) / 2までしか一方に連続して入らない
    // => N - prevK - t >= pile ならばreturn 1

    int t = (K - prevK) / 2;
    if (N - prevK - t >= pile) return 1;

    cerr << pile << '/' << N - prevK << endl;
    
    ll res = 0;
    for (int i = pile; i <= N - prevK; i++) {
        res += choose[N - prevK][i];
    }
    return res / pow(2.0, N - prevK);
}

int main()
{
    choose_init();
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

