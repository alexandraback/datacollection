#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

int n;

map < int , int > used;

vector<int> vec[2];

int a[1000];

void solve () {

    static int testN = 0;
      
    scanf ( "%d", &n );
    
    int R = 0;
    used.clear();
    vec[0].clear();
    vec[1].clear();
    
    int tempSum, ans = -1;
    
    for ( int i = 0; i < n; ++i ) scanf ( "%d" , &a[i] );
    
    for ( int i = 1; i < (1<<n); ++i ) {
    
        tempSum = 0;
        for ( int j = 0; j < n; ++j )
            if ( i & (1<<j) ) {
            
                tempSum += a[j];
                
            }
            
            used[tempSum] ++;
            if ( used[tempSum] > 1 ) { ans = tempSum; break; }
    }
    
    printf ( "Case #%d:\n", ++testN );
    if ( ans == -1 ) { printf ("Impossible\n"); return; }
    
    for ( int i = 1; i < (1<<n); ++i ) {
    
        tempSum = 0;
        for ( int j = 0; j < n; ++j )
            if ( i & (1<<j) ) {
            
                tempSum += a[j];
                
            }
            
            if ( tempSum == ans ) {
            
                for ( int j = 0; j < n; ++j )
                    if ( i & (1<<j) ) {
                    
                        vec[R].push_back ( a[j] );
                    }
                R++;
                
                if ( R == 2 ) break;
            }
    }
    
    for ( int j = 0; j < (int)vec[0].size(); ++j )
        if ( j != (int)vec[0].size() - 1 ) printf ( "%d ", vec[0][j] );
        else printf ("%d\n", vec[0][j]);
        
    for ( int j = 0; j < (int)vec[1].size(); ++j )
        if ( j != (int)vec[1].size() - 1 ) printf ( "%d ", vec[1][j] );
        else printf ("%d\n", vec[1][j]);    
}
int main () {

    int t;
    scanf ( "%d", &t );
    
    for ( int i = 0; i < t; ++i ) solve ();
    return 0;
}
