// Google Code Jam Template by rabbit125 @2014/05/04
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
#include <bits/stdc++.h>
using namespace std ;
/* Define Useful Vars. */
#define ULL  unsigned long long
#define LLI           long long
#define BIT            17
#define INF    1000000000 // 1e9
#define MOD    1000000007 // prime 1e9+7
#define STRMAX      12000
#define MAX           120
int n ;
struct Tra
{
    char A , B ;
};
vector<Tra> Tv , Mkv ;
int N[ MAX ] ;
int L[ MAX ] ;
map<string,int> Mp ;
int main( )
{
    freopen( "B-small-attempt1E0.in" , "r" , stdin ) ;
    freopen( "B-sE0.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        Tv.clear( ) ;
        char w[ 500 ] ;
        Tra Now ;
        scanf( "%d" , &n ) ;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf( "%s" , &w ) ;
            Now.A = w[0] ;
            Now.B = w[strlen(w)-1] ;
            Tv.push_back( Now ) ;
            N[ i ] = i ;
        }
        LLI ans = 0 ;
        do
        {
            int LK = 0 ;
            bool OK1 = 0 ;
            for( int i = 0 ; i < n ; i++ )
                L[i] = 0 ;
            for( int i = 0 ; i < n ; i++ )
                if( i+1<n && Tv[N[i]].B == Tv[N[i+1]].A )
                    L[i] = 1 , OK1 = 1 ;
            Mkv.clear( ) ;
            for( int i = 0 ; i < n ; i++ )
            {
                Now.A = Tv[ N[i] ].A ;
                while( i < n && L[i] == 1 )
                    i++ ;
                Now.B = Tv[ N[i] ].B ;
                Mkv.push_back( Now ) ;
            }
            bool ok = 1 ;
            int Nkv = Mkv.size() ;
            for( int i = 0 ; i < Nkv ; i++ )
                for( int j = 0 ; j < Nkv ; j++ )
                    if( i != j )
                        if( Mkv[i].B == Mkv[j].A )
                            ok = 0 ;
            if( ok && OK1 )
            {
                ans++ ;
                //for( int i = 0 ; i < m ; i++ )
                    //printf( "%c%c %c" , Mkv[i].A , Mkv[i].B , " \n"[i+1==Nkv] ) ;
            }

        }while( next_permutation( N , N + n ) ) ;
        printf( "Case #%d: %lld\n" , T++ , ans ) ;
    }
    return 0 ;
}
/*
3
3
ab bbbc cd
4
aa aa bc c
2
abc bcd

*/
/*
Case #1: 1
Case #2: 4
Case #3: 0
*/
