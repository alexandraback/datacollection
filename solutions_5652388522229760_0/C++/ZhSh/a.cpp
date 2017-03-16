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
using namespace std;

//cout.precision(12);
//cout.setf( std::ios::fixed, std:: ios::floatfield );

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
template<class T> void printImpl(const T & data) { cout << data << endl; }

#define DEBUGPRINT
#ifdef DEBUGPRINT
#define print(x) cout << #x" = "; printImpl(x);
#else
#define print(x) ;
#endif

void apply(long long x, vector<int> & checker)
{
    while (x > 0)
    {
        checker[x % 10] = 1;
        x /= 10;
    }
}

bool done(const vector<int> & checker)
{
    for (int i = 0; i < 10; ++i)
    {
        if (checker[i] == 0)
        {
            return false;
        }
    }
    return true;
}

long long solve(long long N)
{
    long long curr = N;
    vector<int> checker(10);
    while (1)
    {
        apply(curr, checker);
        if (done(checker))
        {
            return curr;
        }
        curr += N;
    }
    return 0;
}

int main()
{
    int caseCount;
    cin >> caseCount;
    
    for (int csIx = 1; csIx <= caseCount; ++csIx)
    {
        long long N;
        cin >> N;
        if (N == 0)
        {
            cout << "Case #" << csIx << ": INSOMNIA" << endl;
        }
        else
        {
            cout << "Case #" << csIx << ": " << solve(N) << endl;
        }
    }
    
    return 0;
}
