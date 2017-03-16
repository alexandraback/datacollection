#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fil[200];
int col[200];
int mat[200][200];

int main()
{
    freopen ( "b.in", "r", stdin );
    // freopen ( "BSmall.out", "w", stdout );
    freopen ( "BLarge.out", "w", stdout );

    int ntc, tc = 0;
    int n, m;

    cin >> ntc;

    while ( ntc -- )
    {
        tc ++;

        cin >> n >> m;

        memset ( fil, 0, sizeof(fil) );
        memset ( col, 0, sizeof(col) );

        for ( int i = 0; i < n; i ++ )
        {
            for ( int j = 0; j < m; j ++ )
            {
                cin >> mat[i][j];
                fil[i] = max(fil[i], mat[i][j]);
                col[j] = max(col[j], mat[i][j]);
            }
        }

        bool ok = true;

        for ( int i = 0; i < n; i ++ )
            for ( int j = 0; j < m; j ++ )
                if ( mat[i][j] != fil[i] && mat[i][j] != col[j] )
                    ok = false;

        cout << "Case #" << tc << ": ";
        if ( ok ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
