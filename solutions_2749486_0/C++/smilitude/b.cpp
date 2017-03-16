/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-05-12 Sun 05:48 PM    
*/

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<cassert>
#include<climits>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--) 
#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()

#define sz size()
#define pb push_back

short d[500][500][505];
char pre[500][500][505];

// NSEW
int dr[] = { 0, 0, 1, -1};
int dc[] = { 1, -1, 0, 0};
char dir[] = "NSEW";

bool valid( int r, int c, int d ) {
    return d <= 500 && r < 500 && c < 500 && r >= 0 && c >= 0;
}

void print( int r, int c, int d ) {
    if( d == 1 ) return;
    
    int i = pre[r][c][d];
    int R = r - dr[i] * (d-1);
    int C = c - dc[i] * (d-1);

    print( R, C, d-1 );
    printf("%c", dir[i] );
}

int main() {
     
    int m = 250;
    
    SET( d, -1 );

    // pre processing
    queue< int > q;
    q.push( m );
    q.push( m );
    q.push( 1 );

    d[m][m][1] = 0;

    while( !q.empty() ) {
        int r = q.front(); q.pop();
        int c = q.front(); q.pop();
        int x = q.front(); q.pop();

        REP(i,4) {
            int R = r + dr[i] * x;
            int C = c + dc[i] * x;
            int X = x+1;
        
            if( valid( R, C, X ) ) {
                if( d[R][C][X] == -1 || d[R][C][X] > d[r][c][x] + 1 ) {
                    d[R][C][X] = d[r][c][x] + 1;
                    pre[R][C][X] = i;
                    
                    q.push( R );
                    q.push( C );
                    q.push( X );
                }
            }
        }
    }


    int t, ncase = 0;
    scanf("%d",&t);
    while( t-- ) {
        int r, c;
        cin >> r >> c;
        r += m, c += m;
        printf("Case #%d: ", ++ncase);
        FOR(i,1,500) if( d[r][c][i] != -1 ) {
            print( r, c, i );
            cout << endl;
            break;
        }
    }

    return 0;
}

