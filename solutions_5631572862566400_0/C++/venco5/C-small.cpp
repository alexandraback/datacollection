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
#include <sstream>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <iomanip>
//#include <gmp.h>
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
#define forIter(I,C) for( auto I : (C) )
#define forNF(I,S,C) for( int I=(S); I<int(C); ++I )
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef long long i64; typedef unsigned long long u64; typedef unsigned u32;
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<string> VS;
typedef vector<u32> VU;

size_t line_number;
void input_error(const char* msg = 0) {
    cerr << "Input failed at line " << line_number;
    if ( msg ) cerr << ": " << msg;
    cerr << endl; exit(1);
}
void check_space(const string& s) {
    for ( auto c : s ) {
#ifdef HOME_RUN
        if ( !isspace(c&255) ) input_error("not a space");
        assert(isspace(c&255));
#endif
    }
}
string get_str(istream& in) {
    string ret; ++line_number; if ( !getline(in, ret) ) input_error(); return ret;
}
istream& skip_endl(istream& in) { check_space(get_str(in)); return in; }
istream& skip_eof(istream& in) { string s;
    while ( ++line_number, getline(in, s) ) check_space(s);
    if ( !in.eof() ) input_error(); return in;
}

map<string, int> str_index;
int get_index(const string& s) {
    return str_index.insert(make_pair(s, str_index.size())).first->second;
}
inline int get_str_index(istream& in) { return get_index(get_str(in)); }


typedef uint16_t u16;
VU primes;
static const u16 low_divisor_prime = 1;
std::vector<u16> low_divisor;

void make_primes(u32 max)
{
    ++max;
    primes.clear();
    size_t msize = 100+size_t(1.1*max/log(max+2));
    size_t mid = sqrt(max+1);
    primes.reserve(msize);
    low_divisor.assign(max, 0);
    auto ld = low_divisor.data();
    ld[0] = 1;
    ld[1] = 0;
    for ( u32 p = 2; p <= mid; ++p ) {
        if ( ld[p] ) continue;
        primes.push_back(p);
        ld[p] = low_divisor_prime;
        for ( u32 i = 2*p; i < max; i += p ) {
            auto& s = ld[i];
            if ( !s ) s = p;
        }
    }
    for ( u32 p = mid+1; p < max; ++p ) {
        if ( ld[p] ) continue;
        primes.push_back(p);
        ld[p] = low_divisor_prime;
    }
}

/////////////////////////////////////////////////////////////////////////////

const int INF = 999999999;
const int MAX_N = 1024;

size_t N;

int bb[MAX_N];
vector<int> rb[MAX_N];
int vv[MAX_N];

int get_rb(int i0)
{
    int ret = 0;
    for ( auto i : rb[i0] ) {
        assert(bb[i] == i0);
        if ( bb[i0] == i ) continue;
        ret = max(ret, 1+get_rb(i));
    }
    //TR(i0|ret);
    return ret;
}

int get_cycle2(int i0)
{
    if ( bb[i0] < i0 ) return 0;
    if ( bb[bb[i0]] != i0 ) return 0;
    return get_rb(i0) + get_rb(bb[i0]) + 2;
}

int get_cycle(int i0)
{
    forN ( k, N ) vv[k] = 0;
    int r = 0;
    int i = i0;
    while ( !vv[i] ) {
        vv[i] = 1;
        i = bb[i];
        ++r;
    }
    //TR(i0|i|r);
    if ( i != i0 ) return 0;
    return r;
}

int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    make_primes(1000000);
    forN ( nc, num_cases ) {
        // parse input
        cin >> N >> skip_endl;

        forN ( i, N ) rb[i].clear();
        forN ( i, N ) {
            int b;
            cin >> b;
            --b;
            bb[i] = b;
            rb[b].push_back(i);
        }
        cin >> skip_endl;
        
        // error check
        if ( !cin ) input_error();
        // main code

        //TR(N);
        int result = 0;

        int cc2 = 0;
        forN ( i, N ) {
            result = max(result, get_cycle(i));
            cc2 += get_cycle2(i);
        }
        result = max(result, cc2);
        
        // output
        cout << "Case #"<<nc+1<<": ";
        cout << result;
        cout << endl;
    }
    cin >> skip_eof;
}
