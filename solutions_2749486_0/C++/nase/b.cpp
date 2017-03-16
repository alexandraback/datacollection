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
#include <cassert>

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

char inp[1000000];

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

//
//
// LET'S START
//
//

string doCase()
{
    // 1-2 => -1
    // 1-2+3 => 2
    // 1-2+3-4 => -2
    // 1-2+3-4+5 => 3
    // 1-2+3-4+5-6 => -3
    // ..
    // k-(k+1) => -1
    // k-(k+1)+(k+2) => k+1
    //

    // X => ((k+1)-k) + (k+3-(k+2)) + .. => {WE} * X
    int X, Y;
    scanf("%d%d", &X, &Y);
    cerr << X << "," << Y << endl;

    string res;

    FOR(i, 0, abs(X)) {
        res += X < 0 ? "EW" : "WE";
    }
    FOR(i, 0, abs(Y)) {
        res += Y < 0 ? "NS" : "SN";
    }

    cerr << "res = " << res << endl;

    // check
    int x = 0, y = 0;
    FOR(i, 0, res.size()) {
        if (res[i] == 'E') x+=(i+1);
        if (res[i] == 'W') x-=(i+1);
        if (res[i] == 'N') y+=(i+1);
        if (res[i] == 'S') y-=(i+1);
    }
    cerr << "x = " << x << " y = " << y << endl;
    assert(x == X && y == Y);
    // check end
    
    return res;
}

int main()
{
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

