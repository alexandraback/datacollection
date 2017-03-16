#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>
//#include <time.h>
using namespace std;
//#define MAX 1005
#define pii pair<int , int>
#define mp make_pair
#define MAX 27
int a[ MAX ];
#define SZ 5
string d[ SZ ] = {"ONE", "THREE", "FIVE", "SEVEN", "NINE"};
int val[SZ] = {1,3,5,7,9};
int idx[ SZ ] = {0,1,2,3,4};//,6,7,8,9};
string d2[10 ] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
//int idx[10] = {0,1,2,3,4,5,6,7,8,9};
//string d[10 ] = {"THREE", "SEVEN", "EIGHT", "ZERO","FOUR", "FIVE", "NINE", "ONE", "TWO", "SIX" };

//int dval[10] = {3,7,8,0,4,5,9,1,2,6};
/*bool cmp( string s1, string s2 ){
    return s1.size() > s2.size();
}*/

vector<int> cnt[ MAX ];

int removeDigit(int digit)
{
    int mini = 1<<30;
    for( int j = 0 ; j < MAX ; ++j )
    {
        if( cnt[digit][j] > 0)
        {
            mini = min( a[j] , mini );
        }
    }

    for( int j = 0 ; j < MAX ; ++j )
        if( cnt[digit][j] > 0 )
            a[j] -= mini;
    return mini;
}

int removeDigit2(int digit)
{
    int c = 0;
    while( true )
    {
        bool b = true;
        for( int j = 0 ; j < MAX ; ++j )
        {
            if( cnt[digit][j] > 0 && a[j] < cnt[digit][j])
            {
                b = false;
                break;
            }
        }
        if( !b ) break;
        for( int j = 0 ; j < MAX ; ++j )
        {
            if( cnt[digit][j] > 0 )
            {
                a[j] -= cnt[digit][j];
            }
        }
        c++;
    }
    return c;
}

int main()
{
    int t, sz;
    scanf("%d", &t) ;
    string s;
    vector<int> ans;

    for( int i = 0 ; i < MAX ; ++i ) cnt[i] = vector<int>(MAX, 0);

    for( int i = 0 ; i < 10 ; ++i  )
    {
        for( int j = 0 ; j < d2[i].size() ; ++j )
        {
            cnt[i][ d2[i][j] - 'A']++;
        }
    }

    for( int q = 1 ; q <= t && cin>>s ; ++q )
    {
        memset( a, 0 , sizeof(a) );
        ans.clear();
        sz = s.size();

        for( int i = 0 ; i < sz ; ++i )
            a[ s[i] - 'A' ]++;

        vector<pii> v;

        if( a['Z' - 'A'] > 0 )
        {
            //remove zeros
            int mini = removeDigit2(0);
            v.push_back( mp(0, mini) );
        }
        if( a['W' - 'A'] > 0 )
        {
            int mini = removeDigit2(2);
            v.push_back( mp(2, mini) );
        }
        if( a['X' - 'A'] > 0)
        {
            int mini = removeDigit2(6);
            v.push_back( mp(6, mini) );
        }
        if( a['G' - 'A'] > 0)
        {
            int mini = removeDigit2(8);
            v.push_back( mp(8, mini) );
        }

        if( a['U' - 'A'] > 0 )
        {
            int mini = removeDigit2(4);
            v.push_back( mp(4, mini) );
        }

        if( a['H' - 'A'] > 0 )
        {
            int mini = removeDigit2(3);
            v.push_back( mp(3, mini) );
        }
        if( a['F' - 'A'] > 0 )
        {
            int mini = removeDigit2(5);
            v.push_back( mp(5, mini) );
        }
        if( a['S' - 'A'] > 0 )
        {
            int mini = removeDigit2(7);
            v.push_back( mp(7, mini) );
        }
        if( a['O' - 'A'] > 0 )
        {
            int mini = removeDigit2(1);
            v.push_back( mp(1, mini) );
        }

        if( a['N' - 'A'] > 0 )
        {
            int mini = removeDigit2(9);
            v.push_back( mp(9, mini) );
        }

        printf("Case #%d: ", q  );

        bool b = true;
        for( int i = 0 ; i < MAX ; ++i ){
            if( a[i]!= 0){
                b = false;
                break;
            }
        }
        if( !b ){
            cout<<endl;continue;
        }

        sort( v.begin(), v.end() );
        for( int i = 0 ; i < v.size() ; ++i )
        {
            for( int j = 0 ; j < v[i].second ; ++j )
            {
                printf("%d" , v[i].first);
            }
        }
        printf("\n");
    }
    return 0 ;
}


/*
for( int j = 0 ; j < d[i].size() ; ++j ){
    if( a[ d[i][j] - 'A'] <= 0 ){
        b = false;
        break;
    }
}*/
