//
//  main.cpp
//  task2
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

map< pair< int, int >, string > m[ 501 ];

string s = "NSEW";
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


void solve_small( int id )
{
    printf("Case #%d: ", id);
    int x, y; cin >> x >> y;
    if ( y < 0 ) for ( int i = 0; i < -y; i++ ) cout << "NS"; 
    if ( y > 0 ) for ( int i = 0; i < y; i++ ) cout << "SN";
    if ( x < 0 ) for ( int i = 0; i < -x; i++ ) cout << "EW";
    if ( x > 0 ) for ( int i = 0; i < x; i++ ) cout << "WE";
    cout << endl;
}

int main (int argc, const char * argv[])
{
    freopen("B-small-attempt0.in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    for ( int it = 0; it < t; it++ ) solve_small( it + 1 );
    return 0;
}
