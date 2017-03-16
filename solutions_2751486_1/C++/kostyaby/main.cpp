//
//  main.cpp
//  task1
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

int n, l;
char st[ 1000100 ];
int f[ 1000100 ];

int fun( char c )
{
    if ( c == 'a' ) return 0;
    if ( c == 'e' ) return 0;
    if ( c == 'i' ) return 0;
    if ( c == 'o' ) return 0;
    if ( c == 'u' ) return 0;
    return 1;
}

void solve( int id )
{
    printf("Case #%d: ", id);
    scanf("%s%d", st, &n);
    l = strlen( st );
    for ( int i = 0; i < l; i++ ) st[i] = '0' + fun( st[i] );
    long long ans = 0;
    int cur = 0;
    for ( int i = l - 1; i >= 0; i-- )
    {
        if ( st[i] == '0' ) cur = 0; else cur++;
        f[i] = cur;
    }
    int lst = -1;
    for ( int i = l - 1; i >= 0; i-- )
    {
        if ( f[i] >= n ) lst = i;
        if ( lst == -1 ) continue;
        int ll = i, rr = lst + n - 1;
        ans += l - rr;
    }
    printf("%lld\n", ans);
}

int main (int argc, const char * argv[])
{
    freopen("A-large.in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d\n", &t);
    for ( int it = 0; it < t; it++ ) solve( it + 1 );
    return 0;
}