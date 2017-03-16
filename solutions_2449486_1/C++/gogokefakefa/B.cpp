#include <iostream>
#include <cstring>

using namespace std;

string solve(){
    int N, M, a[128][128], row[128], col[128];
    memset ( row, 0, sizeof ( row ) );
    memset ( col, 0, sizeof ( col ) );


    cin >> N >> M;

    for ( int i = 0; i < N; ++i )
        for ( int j = 0; j < M; ++j ){
            cin >> a[i][j];
            row[i] = max ( row[i], a[i][j] );
            col[j] = max ( col[j], a[i][j] );
        }

    for ( int i = 0; i < N; ++i )
        for ( int j = 0; j < M; ++j )
            if ( a[i][j] < row[i] && a[i][j] < col[j] )
                return "NO";
    return "YES";
}
int main(){
    int N;
    cin >> N;

    for ( int i = 1; i <= N; ++i )
        cout << "Case #" << i << ": " << solve () << endl;
}
