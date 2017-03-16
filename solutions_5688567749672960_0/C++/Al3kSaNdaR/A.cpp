#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz size
#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

using namespace std;

typedef long long int lld;
typedef pair < int, int > pii;

const int MAX = 1000000;

int Dist[1 << 20];
vector < int > E[MAX];

int Reverse ( int Number )
{
    int Return = 0;
    while ( Number )
    {
        Return = Return * 10 + ( Number % 10 );
        Number /= 10;
    }
    return Return;
}

void BFS ( int idx )
{
    Dist[idx] = 0;
    queue < int > Q;
    Q.push ( idx );
    while ( ! Q.empty ( ) )
    {
        int Current = Q.front ( );
        Q.pop ( );
        for ( auto Next: E[Current] )
        {
            if ( Dist[Next] != -1 ) continue;
            Dist[Next] = Dist[Current] + 1;
            Q.push ( Next );
        }
    }
}

int main ( void )
{
    freopen ( "A-small-attempt0.in", "r", stdin );
    freopen ( "A-small-attempt0.out", "w", stdout );

    for ( int i = 0; i <= MAX; i++ )
    {
        E[i].push_back ( i + 1 );
        E[i].push_back ( Reverse ( i ) );
        assert ( Reverse ( i ) <= ( 1 << 20 ) );
        Dist[i] = -1;
    }
    BFS ( 0 );

    //for ( int i = 1; i <= 30; i++ ) cout << i << " " << Dist[i] << endl;

    int T;
    cin >> T;
    for ( int i = 1; i <= T; i++ )
    {
        int N;
        cin >> N;
        cout << "Case #" << i << ": " << Dist[N] << endl;
    }

    return 0;
}
