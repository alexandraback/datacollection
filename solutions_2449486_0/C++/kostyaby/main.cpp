//
//  main.cpp
//  Lawnmower_gcj13
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

int n, m, a[ 111 ][ 111 ], r[ 111 ], c[ 111 ];

void solve( int id )
{
    cout << "Case #" << id << ": ";
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) r[i] = 0;
    for ( int j = 1; j <= m; j++ ) c[j] = 0;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            cin >> a[i][j];
            r[i] = max( r[i], a[i][j] );
            c[j] = max( c[j], a[i][j] );
        }
    string ans = "YES\n";
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            int num = 0;
            if ( r[i] == a[i][j] ) num++;
            if ( c[j] == a[i][j] ) num++;
            if ( num == 0 ) ans = "NO\n";
        }
    cout << ans;
}

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    for ( int it = 1; it <= t; it++ ) solve( it );
    return 0;
}

