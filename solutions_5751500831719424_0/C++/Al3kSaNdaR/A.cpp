/*
    Aleksandar "Al3kSaNdaR" Ivanović

    Problem A. The Repeater
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

const int MaxN = 1 << 8;

int t, N, L[MaxN], Cnt[MaxN];
string S[MaxN], SS[MaxN];

int main ( void )
{
    freopen ( "A-small-attempt1.in", "r", stdin );
    freopen ( "A-small-attempt1.out", "w", stdout );

    cin.sync_with_stdio ( 0 );
    cout.sync_with_stdio ( 0 );

    cin >> t;
    for ( int __t = 1; __t <= t; __t++ )
    {
        cin >> N;
        for ( int i = 0; i < N; i++ )
        {
            cin >> S[i];
            L[i] = S[i].length ( );
            SS[i] = "";
            for ( int j = 0; j < L[i]; j++ ) if ( ( ! j ) || ( S[i][j] != S[i][j - 1] ) ) SS[i] += S[i][j];
        }
        cout << "Case #" << __t << ": ";

        bool Can = true;
        for ( int i = 1; i < N; i++ ) if ( SS[i] != SS[i - 1] ) Can = false;
        if ( ! Can )
        {
            cout << "Fegla Won" << endl;
            continue;
        }

        int SZ = SS[0].length ( ), Sol = 0;
        while ( SZ-- )
        {
            for ( int i = 0; i < N; i++ ) Cnt[i] = 0;
            for ( int i = 0; i < N; i++ )
            {
                int idx = 0;
                while ( idx < L[i] && S[i][idx] == S[i][0] ) idx++;
                S[i] = S[i].substr ( idx );
                Cnt[i] = idx + 1;
            }
            int MIN = 1 << 30;
            for ( int k = 1; k <= 1000; k++ )
            {
                int Curr = 0;
                for ( int i = 0; i < N; i++ ) Curr += abs ( Cnt[i] - k );
                if ( Curr < MIN ) MIN = Curr;
            }
            Sol += MIN;
        }
        cout << Sol << endl;
    }

    return 0;
}
