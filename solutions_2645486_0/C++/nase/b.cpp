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


template< typename type > type readOne()
{
    type res;
    char inp[5000];
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    ss >> res;
    return res;
}

template< typename type > vector<type> readMulti()
{
    vector<type> res;
    char inp[5000];
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    for ( type t; ss >> t; )
        res.push_back( t );
    return res;
}

//
//
// LET'S START
//
//

ll dp[2][10005];

ll doCase()
{
    ll E, R, N;
    vector<ll> tmp = readMulti<ll>();
    E = tmp[0];
    R = tmp[1];
    N = tmp[2];
    vector<ll> V = readMulti<ll>();

    memset(dp, 0, sizeof(dp));

    for (ll i = N - 1; i >= 0; i--) {
        int x = i & 1;
        // 最低限必要な状態でよい
        for (ll e = 0; e <= E; e++) {
            dp[x][e] = 0;
            for (ll s = 0; s <= e; s++) {
                ll nexte = min(e - s + R, E);
                dp[x][e] = max(dp[x][e], s * V[i] + dp[1-x][nexte]);
            }
        }
    }

    return dp[0][E];
}

int main()
{
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

