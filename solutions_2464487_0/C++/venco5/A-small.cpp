#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <gmpxx.h>
#ifdef HOME_RUN
# include <debug.hpp>
# include <dump.hpp>
# include <cassert>
#else
# define TR(x) do{}while(0)
# ifdef assert
#  indef assert
# endif
# define assert(x) do{}while(0)
#endif
using namespace std;

#define ALL(C) (C).begin(), (C).end()
#define forIter(I,C) for(typeof((C).end()) I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;

inline istream& skip_endl(istream& in)
{
    string s;
    getline(in, s);
    forIter( i, s ) assert(isspace(*i));
    return in;
}

inline string get_str()
{
    string ret;
    getline(cin, ret);
    return ret;
}

map<string, int> str_index;
int get_index(const string& s)
{
    return str_index.insert(make_pair(s, str_index.size())).first->second;
}
int get_str_index()
{
    return get_index(get_str());
}

inline void assign(mpz_class& r, u64 v)
{
    r = u32(v>>32);
    r <<= 32;
    r += u32(v);
}

bool fit(u64 k0, u64 r0, u64 t0)
{
    mpz_class k, r, t;
    assign(k, k0);
    assign(r, r0);
    assign(t, t0);
    return k*(2*r+2*k-1) <= t;
}

int main(int argc, const char** argv)
{
    int num_cases = 1;
    cin >> num_cases >> skip_endl;
    int part_cases = 0;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    forN ( nc, num_cases ) {
        u64 r, t;
        cin >> r >> t >> skip_endl;
        assert(cin);
        u64 a = 1, b = t+1;
        while ( a < b-1 ) {
            u64 m = a+(b-a)/2;
            if ( fit(m, r, t) )
                a = m;
            else
                b = m;
        }
        u64 result = a;

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << result;
        cout << endl;
    }
}
