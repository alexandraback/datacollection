#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 55;

char a[MAXN][MAXN] , res[MAXN][MAXN];

void Fill( int N )
{
    for ( int i = 1 ; i <= N ; i++ )
    {
        for  ( int j = 1 ; j <= N ; j++ )
            a[i][j] = '*';
    }
}

bool Solve( int R , int C , int Free )
{

    if ( Free == 1 )
    {
        a[1][1] = '.';
        return true;
    }

    if ( R == 1 )
    {
        for ( int i = 1 ; i <= Free ; i++ ) a[1][i] = '.';
        return true ;
    }

    if ( Free == 2 || Free == 3 || Free == 5 || Free == 7 ) return false;

    if ( R == 2 )
    {
        if ( Free % 2 == 1 ) return false;
        for ( int i = 1 ; i <= Free/2 ; i++ )
            a[1][i] = a[2][i] = '.';
        return true;
    }

    if ( Free > 2 * C + 1 )
    {
        int row = 1;
        while( Free > C )
        {
            for ( int i = 1 ; i <= C ; i++ )
                a[row][i] = '.';
            Free -= C;
            row++;
        }

        if ( Free == 1 )
        {
            a[row-1][C] = '*';
            Free++;
        }

        for ( int i = 1 ; i <= Free ; i++ )
            a[row][i] = '.';

        return true;

    }
    else
    {
        if ( Free % 2 == 0 )
        {
            for ( int i = 1 ; i <= Free/2 ; i++ )
                a[1][i] = a[2][i] = '.';
            return true;
        }
        else
        {
            a[3][1] = a[3][2] = a[3][3] = '.';
            for ( int i = 1 ; i <= (Free-3)/2 ; i++ )
                a[1][i] = a[2][i] = '.';
            return true;
        }
    }

}

void Change( int& R , int& C , bool flag )
{

    if ( !flag )
    {
        for ( int i = 1 ; i <= R ; i++ )
        {
            for ( int j = 1 ; j <= C ; j++ )
                res[i][j] = a[i][j];
        }
    }
    else
    {
        for ( int i = 1 ; i <= R ; i++ )
        {
            for ( int j = 1 ; j <= C ; j++ )
                res[j][i] = a[i][j];
        }
        swap( R , C );
    }

    res[1][1] = 'c';
    return;

}

int main()
{
    freopen("input.in" , "r" , stdin );
    freopen("output.out" , "w" , stdout );

    int T;
    cin >> T;

    for ( int t = 1 ; t <= T ; t++ )
    {

        int R , C , Bombs , Free ;
        bool transpose;
        cin >> R >> C >> Bombs;
        Free = R * C - Bombs;

        if ( R > C )
        {
            swap( R , C );
            transpose = true;
        }
        else
            transpose = false;

        Fill( C );
        cout << "Case #" << t << ":" << endl;;
        if ( Solve( R , C , Free ) )
        {
            Change( R , C , transpose );

            for ( int i = 1 ; i <= R ; i++ )
            {
                for ( int j = 1 ; j <= C ; j++ )
                    cout << res[i][j];
                cout << endl;
            }
        }
        else
        {
            cout << "Impossible" << endl;
        }

    }

    return 0;
}
