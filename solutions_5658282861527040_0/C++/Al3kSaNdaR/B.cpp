/*
    Aleksandar "Al3kSaNdaR" Ivanović

    Problem B. New Lottery Game
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <functional>

#define pb push_back
#define mp make_pair
#define sz size
#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

using namespace std;

typedef long long int lld;
typedef pair < int, int > pii;

const int INF = 1 << 30;
const double EPS = 1e-9;
const lld MOD = 1000000007LL;

int t, A, B, K;
int main ( void )
{
    freopen ( "B-small-attempt0.in", "r", stdin );
    freopen ( "B-small-attempt0.out", "w", stdout );

    cin.sync_with_stdio ( 0 );
    cout.sync_with_stdio ( 0 );

    cin >> t;
    for ( int __t = 1; __t <= t; __t++ )
    {
        cin >> A >> B >> K;
        int Sol = 0;
        for ( int i = 0; i < A; i++ )
            for ( int j = 0; j < B; j++ ) if ( ( i & j ) < K ) Sol++;
        cout << "Case #" << __t << ": " << Sol << endl;
    }

    return 0;
}
