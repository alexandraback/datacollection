#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

typedef long long int lld;

typedef pair < int, int > pii;

const int MaxN = 1000 + 5;

int T, N, A[MaxN], B[MaxN];
bool Visited[MaxN];

int main ( void )
{
    freopen ( "B-small-attempt0.in", "r", stdin );
    freopen ( "B-small-attempt0.out", "w", stdout );

    //freopen ( "B-large.in", "r", stdin );
    //freopen ( "B-large.out", "w", stdout );

    cin >> T;

    for ( int TestCase = 0; TestCase < T; TestCase++ )
    {
        cin >> N;

        for ( int i = 0; i < N; i++ ) cin >> A[i] >> B[i];

        memset ( Visited, false, sizeof ( Visited ) );

        priority_queue < pair < pii, int > > PQA;
        priority_queue < pii > PQB;

        for ( int i = 0; i < N; i++ ) PQA.push ( make_pair ( make_pair ( -A[i], B[i] ), i ) );
        for ( int i = 0; i < N; i++ ) PQB.push ( make_pair ( -B[i], i ) );

        int Have = 0, Sol = 0;
        bool TooBad = false;

        while ( ! PQB.empty ( ) )
        {
            int CurrValue = -PQB.top ( ).first;
            int CurrPos = PQB.top ( ).second;

            PQB.pop ( );

            if ( CurrValue <= Have )
            {
                Sol++;

                if ( Visited[CurrPos] ) Have--;

                Have += 2;

                continue;
            }

            while ( ( ! PQA.empty ( ) ) && ( CurrValue > Have ) )
            {
                int CurrAValue = -PQA.top ( ).first.first;
                int CurrAPos = PQA.top ( ).second;

                if ( CurrAValue > Have ) break;

                PQA.pop ( );

                Sol++;

                Visited[CurrAPos] = true;

                Have++;
            }

            if ( CurrValue <= Have )
            {
                Sol++;

                if ( Visited[CurrPos] ) Have--;

                Have += 2;

                continue;
            }

            TooBad = true;

            break;
        }

        cout << "Case #" << TestCase + 1 << ": ";

        if ( TooBad ) cout << "Too Bad" << endl;
        else cout << Sol << endl;

    }

    return 0;
}
