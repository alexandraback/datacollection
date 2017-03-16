//
//  main.cpp
//  Treasure
//
//  Created by Sokol Kostya's MacBook on 14.04.11.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int num[ 100 ], n, k, z[ 22 ], t[ 22 ], mx;
vector< int > v[ 22 ];
bool f[ 2000000 ];
vector< int > graf[ 2000000 ]; 
queue< int > q;
vector< int > ans;

void solve( int id )
{
    ans.clear();
    mx = 0;
    cout << "Case #" << id << ": ";
    cin >> k >> n;
    v[0].clear();
    for ( int i = 0; i < k; i++ )
    {
        int a; cin >> a; v[0].pb( a );
        mx = max( mx, a ); 
    }
    for ( int i = 1; i <= n; i++ )
    {
        v[i].clear();
        int kk;
        cin >> t[i] >> kk;
        for ( int j = 0; j < kk; j++ )
        {
            int a; cin >> a; v[i].pb( a );
            mx = max( mx, a );
        }
    }
    int lim = 1 << n;
    for ( int i = 0; i < lim; i++ ) f[i] = false, graf[i].clear();
    for ( int msk = 0; msk < lim; msk++ )
    {
        for ( int i = 0; i <= mx; i++ ) num[i] = 0;
        for ( int i = 1; i <= n; i++ )
        {
            int pt = 1 << ( i - 1 );
            if ( ( msk & pt ) == 0 ) continue;
            num[ t[i] ]--;
            for ( int j = 0; j < v[i].size(); j++ ) num[ v[i][j] ]++;
        }
        for ( int i = 0; i < v[0].size(); i++ ) num[ v[0][i] ]++;
        for ( int i = 0; i <= mx; i++ ) if ( num[i] < 0 ) continue;
        for ( int i = 1; i <= n; i++ )
        {
            int pt = 1 << ( i - 1 );
            if ( ( msk & pt ) != 0 ) continue;
            if ( num[ t[i] ] <= 0 ) continue;
            graf[ msk ].pb( msk ^ pt );
        }
    }
    for ( int i = 0; i < lim; i++ )
        for ( int j = 0; j < graf[i].size(); j++ )
        {
            int next = graf[i][j];
            graf[ next ].pb( i );
        }
    f[ lim - 1 ] = true; q.push( lim - 1 );
    while ( q.size() > 0 )
    {
        int v = q.front(); q.pop();
        for ( int i = 0; i < graf[v].size(); i++ )
        {
            int next = graf[v][i];
            if ( next > v ) continue;
            if ( f[next] ) continue;
            f[next] = true;
            q.push( next );
        }
    }
    int cur = 0;
    while ( true )
    {
        if ( cur == lim - 1 ) break;
        int nxt = 222;
        for ( int i = 0; i < graf[ cur ].size(); i++ )
        {
            int next = graf[ cur ][ i ];
            if ( next < cur ) continue;
            if ( !f[next] ) continue;
            int pt = next ^ cur;
            int ii = 1;
            while ( pt != 1 ) pt /= 2, ii++;
            nxt = min( nxt, ii );
        }
        if ( nxt == 222 )
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        ans.pb( nxt );
        cur ^= 1 << ( nxt - 1 );
    }
    for ( int i = 0; i < ans.size(); i++ ) cout << ans[i] << " "; cout << endl;
    return;
}

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    for ( int it = 1; it <= t; it++ ) solve( it );
    return 0;
}