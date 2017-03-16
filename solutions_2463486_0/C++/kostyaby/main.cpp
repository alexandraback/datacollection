//
//  main.cpp
//  Fair and Square
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

long long a[ 100 ];

void solve( int id )
{
    cout << "Case #" << id << ": ";
    long long ans = 0;
    long long l, r; cin >> l >> r;
    for ( int i = 0; i < 39; i++ ) if ( l <= a[i] && a[i] <= r ) ++ans;
    cout << ans << endl;
}

int main (int argc, const char * argv[])
{
    ifstream fin( "seq.txt" );
    for ( int i = 0; i < 39; i++ ) fin >> a[i];
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    for ( int it = 1; it <= t; it++ ) solve( it );
    return 0;
}
