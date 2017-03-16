#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <set>

#define MAXN 10

#define pb push_back

using namespace std;

string postal[ MAXN + 1 ];
bool adj[ MAXN + 1 ][ MAXN + 1 ];

int main() {
    int T;
    freopen("test.in","rt",stdin);
    freopen("test.out","wt",stdout);
    scanf("%d", &T );
    for( int z = 1; z <= T; z++ ) {
        string ans;
        memset( adj, 0, sizeof( adj ) );
        vector< int > tour;
        int N, M, u, v;
        scanf("%d%d", &N, &M );
        for( int i = 0; i < 100*MAXN; i++ ) {
            ans += '9';
        }
        for( int i = 1; i <= N; i++ ) {
            cin >> postal[ i ];
            tour.pb( i );
        }
        for( int i = 1; i <= M; i++ ) {
            scanf("%d%d", &u, &v );
            adj[ u ][ v ] = true;
            adj[ v ][ u ] = true;
        }
        do {
            stack< int > cities;
            bool used[ MAXN + 1 ][ MAXN + 1 ] = { 0 }, usedr[ MAXN + 1 ][ MAXN + 1 ] = { 0 }, status = true;;
            string P;
            cities.push( tour[ 0 ] );
            P = postal[ tour[ 0 ] ];
            for( int i = 1; i < N; i++ ) {
                int v = tour[ i ];
                //printf("v -> %d\n", v );
                while( !cities.empty() ) {
                    int u = cities.top();
                    if( !used[ u ][ v ] && adj[ u ][ v ] ) break;
                    else if( !usedr[ u ][ v ] && adj[ v ][ u ] && used[ u ][ v ] ) break;
                    cities.pop();
                }
                if( !cities.empty() ) {
                    //printf("i am going to %d via -> %d\n", v, cities.top() );
                    int u = cities.top();
                    if( !used[ u ][ v ] ) used[ u ][ v ] = true;
                    else if( used[ u ][ v ] ) usedr[ u ][ v ] = true;
                    cities.push( v );
                    P.append( postal[ v ] );
                } else {
                    status = false;
                    break;
                }
            }
            if( status ) ans = min( ans, P );

        } while( next_permutation( tour.begin(), tour.end() ) );
        cout << "Case #" << z << ": " << ans << endl;
    }
    return 0;
}
