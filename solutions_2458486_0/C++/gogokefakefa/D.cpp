#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[1 << 21];
vector < int > v[22];
vector < int > path[1 << 21];
int type[22];
int N, K;
int a[400];
int code[256];

void scan(){
    cin >> K >> N;

    for ( int i = 0; i < K; ++i )
        cin >> a[i];

    for ( int i = 0; i < N; ++i ){
        int sz;

        cin >> type[i] >> sz;
        code[type[i]] = 1;

        while ( sz -- ){
            int x;
            cin >> x;
            v[i].push_back ( x );
        }
    }
}


int go ( int mask ){
    int cnt[23];
    if ( dp[mask] != -1 )
        return dp[mask];
    if ( mask == ( 1 << N ) - 1 )
        return dp[mask] = 1;
    dp[mask] = 1;


    memset ( cnt, 0, sizeof ( cnt ) );

    for ( int i = 0; i < K; ++i )
        cnt[ code[a[i]] ] ++;

    for ( int i = 0; i < N; ++i )
        if ( ( 1 << i ) & mask ){
            --cnt[ code[ type[ i ] ] ];
            for ( int j = 0; j < v[i].size(); ++j )
                ++cnt[ code[ v[i][j] ] ];
        }

    for ( int i = 0; i < N; ++i )
        if ( ( ( 1 << i ) & mask ) == 0 )
            if ( cnt[ code[ type[i] ] ] ){

                if ( go ( mask ^ ( 1 << i ) ) ){
                    path[mask].push_back ( i );
                    return dp[mask] = 1;
                }
            }

    return dp[mask] = 0;

}

void solve(int test){
    int brr = 1;
    memset ( dp, -1, sizeof ( dp ) );

    for ( int i = 0; i <= 200; ++i )
        if ( code[i] ) code[i] = brr++;
    go ( 0 );

    cout << "Case #" << test << ": ";
    if ( dp[ ( 1 << N ) - 1 ] == -1 )
        cout << "IMPOSSIBLE\n";
    else{
        vector < int > res;
        int mask = 0;

        while ( mask != ( 1 << N ) - 1 ){
            int nmask = mask;
            for ( int i = 0; i < path[mask].size(); ++i ){
                nmask ^= ( 1 << path[mask][i] );
                res.push_back ( path[mask][i] );
            }
            mask = nmask;

        }
        for ( int i = 0; i < res.size(); ++i )
            cout << res[i] + 1 << " ";
        cout << endl;

    }
}

void clean(){
    memset ( v, 0, sizeof ( v ) );
    memset ( path, 0, sizeof ( path ) );
    memset ( code, 0, sizeof ( code ) );
}

int main(){
    int T;

    cin >> T;

    for ( int i = 1; i <= T; ++i ){
        clean();
        scan();
        solve(i);
    }
}
