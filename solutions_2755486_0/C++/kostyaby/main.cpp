//
//  main.cpp
//  task3
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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

struct attack
{
    int l, r, s;
    attack() : l( 0 ), r( 0 ), s( 0 ) {};
    attack( int l, int r, int s ) : l( l ), r( r ), s( s ) {};
};

map< int, int > m;
int n;
vector< attack > a[ 676061 ]; 

int get_val( int x )
{
    if ( m.find( x ) == m.end() ) return 0;
    return m[x];
}

int fun( attack a )
{
    for ( int x = a.l; x <= a.r; x++ ) if ( get_val( x ) < a.s ) return 1;
    return 0;
}

void modify( attack a )
{
    for ( int x = a.l; x <= a.r; x++ ) m[x] = max( m[x], a.s );
}

void solve_small( int id )
{
    m.clear();
    printf("Case #%d: ", id);
    for ( int i = 0; i <= 676060; i++ ) a[i].clear();
    cin >> n;
    for ( int i = 0; i < n; i++ )
    {
        int d, n, w, e, s, delta_d, delta_p, delta_s;
        cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
        w++;
        for ( int j = 0; j < n; j++ )
        {
            attack cur( w, e, s );
            a[ d ].pb( cur );
            w += delta_p;
            e += delta_p;
            d += delta_d;
            s += delta_s;
        }
    }
    int ans = 0;
    for ( int i = 0; i <= 676060; i++ )
    {
        for ( int j = 0; j < a[i].size(); j++ ) ans += fun( a[i][j] );
        for ( int j = 0; j < a[i].size(); j++ ) modify( a[i][j] );
    }
    cout << ans << endl;
}

int main (int argc, const char * argv[])
{
    freopen("C-small-attempt0.in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    for ( int it = 0; it < t; it++ ) solve_small( it + 1 );
    return 0;
}

