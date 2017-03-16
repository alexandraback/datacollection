//
//  main.cpp
//  google_cjam
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

string s[ 4 ];

bool case1()
{
    for ( int i = 0; i < 4; i++ )
    {
        bool fl = true;
        for ( int j = 0; j < 4; j++ ) if ( s[i][j] == 'O' || s[i][j] == '.' ) fl = false;
        if ( fl ) return true;
    }
    for ( int j = 0; j < 4; j++ )
    {
        bool fl = true;
        for ( int i = 0; i < 4; i++ ) if ( s[i][j] == 'O' || s[i][j] == '.' ) fl = false;
        if ( fl ) return true;
    }
    bool fl = true;
    for ( int i = 0; i < 4; i++ ) if ( s[i][i] == 'O' || s[i][i] == '.' ) fl = false;
    if ( fl ) return true;
    fl = true;
    for ( int i = 0; i < 4; i++ ) if ( s[i][3 - i] == 'O' || s[i][3 - i] == '.' ) fl = false;
    return fl;
}

bool case2()
{
    for ( int i = 0; i < 4; i++ )
    {
        bool fl = true;
        for ( int j = 0; j < 4; j++ ) if ( s[i][j] == 'X' || s[i][j] == '.' ) fl = false;
        if ( fl ) return true;
    }
    for ( int j = 0; j < 4; j++ )
    {
        bool fl = true;
        for ( int i = 0; i < 4; i++ ) if ( s[i][j] == 'X' || s[i][j] == '.' ) fl = false;
        if ( fl ) return true;
    }
    bool fl = true;
    for ( int i = 0; i < 4; i++ ) if ( s[i][i] == 'X' || s[i][i] == '.' ) fl = false;
    if ( fl ) return true;
    fl = true;
    for ( int i = 0; i < 4; i++ ) if ( s[i][3 - i] == 'X' || s[i][3 - i] == '.' ) fl = false;
    return fl;
}

bool case3()
{
    for ( int i = 0; i < 4; i++ )
        for ( int j = 0; j < 4; j++ )
            if ( s[i][j] == '.' ) return false;
    return true;
}

void solve( int id )
{
    cout << "Case #" << id << ": ";
    for ( int i = 0; i < 4; i++ ) cin >> s[i];
    if ( case1() ) 
    {
        cout << "X won" << endl;
        return;
    }
    if ( case2() ) 
    {
        cout << "O won" << endl;
        return;
    }
    if ( case3() ) 
    {
        cout << "Draw" << endl;
        return;
    }
    cout << "Game has not completed" << endl;
}

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >> t;
    for ( int it = 1; it <= t; it++ ) solve( it );
    return 0;
}

