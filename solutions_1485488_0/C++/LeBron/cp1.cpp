// http://acm.tju.edu.cn/toj/showp3506.html
// Tag : sieve, prime factor, co-prime, bigmod

// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

bool mark [N];
vector <int> primeList;
vector <int> primeFactors;

void sieve ()
{
    memset (mark, true, sizeof (mark));

    mark [0] = mark [1] = false;

    for ( int i = 4; i < N; i += 2 ) mark [i] = false;

    for ( int i = 3; i * i <= N; i += 2 ) {
        if ( mark [i] ) {
            for ( int j = i * i; j < N; j += 2 * i ) mark [j] = false;
        }
    }

    primeList.clear ();
    primeList.push_back (2);

    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] ) primeList.push_back (i);
    }

    //printf ("%d\n", primeList.size ());
}

void findPrimeFactors (int n)
{
    int index = 0;
    int tmp = n;
    primeFactors.clear ();

    while ( primeList [index] * primeList [index] <= n ) {
        while ( tmp % primeList [index] == 0 ) {
            tmp /= primeList [index];
            primeFactors.push_back (primeList [index]);
        }
        index++;
    }

    if ( tmp > 1 )
        primeFactors.push_back (tmp);
}

LL p2 (LL p)
{
    return p * p;
}

LL bigMod (LL b, LL p, LL m)
{
    if ( p == 0 ) return 1;
    if ( p % 2 == 0 ) return p2 (bigMod(b, p / 2, m)) % m;
    return ( (b % m) * (bigMod(b, p - 1, m) % m) ) % m;
}

int main ()
{
    sieve ();

    int n, m;

    while ( scanf ("%d %d", &n, &m) ) {
        if ( n == 0 && m == 0 ) break;

        findPrimeFactors (n);

        vector <int>::iterator it;
        it = unique ( primeFactors.begin (), primeFactors.end () );
        primeFactors.resize (it - primeFactors.begin () );

        int tmp = n;

        for ( size_t i = 0; i < primeFactors.size (); i++ )
            tmp /= primeFactors [i];

        LL res = bigMod (n, m - 1, 201004);

        res *= tmp;

        for ( size_t i = 0; i < primeFactors.size (); i++ ) {
            res *= (primeFactors [i] - 1);
            res %= 201004;
        }

        cout << res << endl;
    }

	return 0;
}

// @END_OF_SOURCE_CODE
