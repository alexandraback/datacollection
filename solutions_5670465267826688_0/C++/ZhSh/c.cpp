#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <assert.h>
using namespace std;

//cout.precision(6);
//cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed

const long long MOD = 1000000007LL;

#define REP(i,N) for (int i = 0; i < (N); ++i)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned int ui;
typedef long long ll;
typedef vector<ll> vll;

template<class T> void printImpl(const vector<T> & coll) { copy(coll.begin(), coll.end(), ostream_iterator<T>(cout, " ")); cout << endl; }
template<class T, int N> void printImpl(T (&coll)[N]) { copy(coll, coll + N, ostream_iterator<T>(cout, " ")); cout << endl; }
template<class Key, class Value> void printImpl(const map<Key, Value> & data) { typename map<Key, Value>::const_iterator it; for (it = data.begin(); it != data.end(); ++it) { cout << it->first << ":" << it->second << endl; } }
template <class T> void printImpl(const T & data) { cout << data << endl; }

#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

int char2n(char c)
{
    if (c == 'i') return 1;
    if (c == 'j') return 2;
    if (c == 'k') return 3;

    assert(false);
    return 0;
}

int mult_ijk(int a, int b)
{
    const static int m[8][8] =
    {
        {0,1,2,3,4,5,6,7},
        {1,4,3,6,5,0,7,2},
        {2,7,4,1,6,3,0,5},
        {3,2,5,4,7,6,1,0},
        {4,5,6,7,0,1,2,3},
        {5,0,7,2,1,4,3,6},
        {6,3,0,5,2,7,4,1},
        {7,6,1,0,3,2,5,4}
    };

    assert(0 <= a && a <= 7);
    assert(0 <= b && b <= 7);
    return m[a][b];
}

int div_ijk(int a, int b)
{
    const static int m[8][8] =
            {
                    {0,1,2,3,4,5,6,7},
                    {5,0,7,2,1,4,3,6},
                    {6,3,0,5,2,7,4,1},
                    {7,6,1,0,3,2,5,4},
                    {4,5,6,7,0,1,2,3},
                    {1,4,3,6,5,0,7,2},
                    {2,7,4,1,6,3,0,5},
                    {3,2,5,4,7,6,1,0}
            };

    assert(0 <= a && a <= 7);
    assert(0 <= b && b <= 7);
    return m[a][b];
}

bool possible(const string & s)
{
    int N = s.length();

    vi res(N);
    res[0] = char2n(s[0]);

    for (int i = 1; i < N; ++i)
    {
        res[i] = mult_ijk(res[i-1], char2n(s[i]));
    }

    for (int i = 0; i < N; ++i)
    {
        if (res[i] != 1)
        {
            continue;
        }

        for (int j = i + 1; j < N; ++j)
        {
            int r2 = div_ijk(res[i], res[j]);
            int r3 = div_ijk(res[j], res[N-1]);

            if (r2 == 2 && r3 == 3)
            {
                return true;
            }
        }

    }

    return false;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        int L, X;
        cin >> L >> X;
        string ss;
        cin >> ss;

        string s;
        for (int i = 0; i < X; ++i)
        {
            s += ss;
        }

        bool res = possible(s);

        if (res)
        {
            cout << "Case #" << csIx << ": YES" << endl;
        }
        else
        {
            cout << "Case #" << csIx << ": NO" << endl;
        }
    }
    
    return 0;
}
