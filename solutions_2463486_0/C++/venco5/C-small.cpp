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
#include <gmp.h>
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
typedef unsigned u32; typedef int i32;
typedef long long i64; typedef unsigned long long u64;
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<string> VS;
typedef pair<int, int> P; typedef vector<P> VP; typedef vector<VP> VVP;

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

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

set<u64> pp;

u64 rev(u64 n)
{
    char b[32];
    sprintf(b, "%llu", n);
    reverse(b, b+strlen(b));
    sscanf(b, "%llu", &n);
    return n;
}

bool is_p(u64 n)
{
    char b[32];
    sprintf(b, "%llu", n);
    int L = strlen(b);
    for ( int i = 0, j = L-1; i < j; ++i, --j )
        if ( b[i] != b[j] ) return 0;
    return 1;
}

void check_p(u32 n)
{
    assert(is_p(n));
    u64 n2 = u64(n)*n;
    if ( is_p(n2) )
        pp.insert(n2);
}


int main(int argc, const char** argv)
{
    NTR = 10000;
    int num_cases = 1;
    cin >> num_cases >> skip_endl;
    int part_cases = 0;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }

    forNF ( m, 1, 10 ) {
        check_p(m);
    }
    forNF ( i, 1, 10 ) {
        u32 r = rev(i);
        check_p(i*10+r);
        forN ( m, 10 )
            check_p(i*100+m*10+r);
    }
    forNF ( i, 10, 100 ) {
        u32 r = rev(i);
        check_p(i*100+r);
        forN ( m, 10 )
            check_p(i*1000+m*100+r);
    }
    forNF ( i, 100, 1000 ) {
        u32 r = rev(i);
        check_p(i*1000+r);
        forN ( m, 10 )
            check_p(i*10000+m*1000+r);
    }
    TR(pp);

    forN ( nc, num_cases ) {
        // parse input  
        u64 A, B;
        cin >> A >> B >> skip_endl;
        assert(A <= B);
        
        // error check
        if ( !cin ) { cout << "Error parsing input" << endl; return 1; }
        // main code

        u64 ret = 0;
        for ( set<u64>::iterator it = pp.lower_bound(A); it != pp.end() && *it <= B; ++it )
            ++ret;


        // output
        cout << "Case #"<<nc+1<<": ";
        cout << ret;
        cout << endl;
    }
}
