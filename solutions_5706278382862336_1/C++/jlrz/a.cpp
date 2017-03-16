#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <memory>
#include <cassert>
#include <set>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;

#define MAPITR(a,b) map<a,b>::iterator
#define LISTITR(a)  list<a>::iterator

#define ITER(itr,a)   for( itr = (a).begin(); itr != (a).end(); ++itr )
#define ITERNI(itr,a) for( itr = (a).begin(); itr != (a).end();  )
#define FORI(i,a,b)   for( int i(a), _b(b); i < _b; ++i )
#define FORD(i,a,b)   for( int i(a), _b(b); i > _b; --i )
#define FORLE(i,a,b)  for( int i(a), _b(b); i <= _b; ++i )
#define FORGE(i,a,b)  for( int i(a), _b(b); i >= _b; --i )

#define DISCARD_LINE  { char buf[32]; cin.getline(buf, 32); }

#define READI(var) int var; cin >> var
#define READLL(var) long long var; cin >> var
#define READC(var) char var; cin >> var

using dword = unsigned int;
using qword = unsigned long long;

using lb = list<bool>;
using lc = list<char>;
using li = list<int>;
using ld = list<double>;
using ls = list<string>;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vll = vector<long long>;

using vdw = vector<dword>;
using vqw = vector<qword>;

template <class T>
inline auto XY(T& a, size_t x, size_t y, size_t width) -> decltype(a[y*width + x]) { return a[y*width + x]; };
//////////////////////////////////////////////////////////////////////////////////////////////////////

void process()
{
    READLL(P);
    READC(ch);
    READLL(Q);


    int sum = 0;
    while (Q > P)
    {
        if (Q & 1)
        {
            cout << "impossible";
            return;
        }

        sum++;
        Q >>= 1;
    }

    P -= Q;

    while (P)
    {
        while (Q > P)
        {
            if (Q & 1)
            {
                cout << "impossible";
                return;
            }

            Q >>= 1;
        }

        P -= Q;
    }

    cout << sum;
}

int main()
{
    int nCases;
    cin >> nCases;

    FORLE(i, 1, nCases)
    {
        cout << "Case #" << i << ": ";

        process();

        cout << endl;
    }

    return 0;
}