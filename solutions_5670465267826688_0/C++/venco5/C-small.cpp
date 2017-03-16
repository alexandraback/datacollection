#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iostream>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<string> VS;
typedef long long i64; typedef unsigned long long u64;

size_t line_number;
void check_space(const string& s) { for ( auto c : s ) assert(isspace(c&255)); }
void input_error() {
    cerr << "Input failed at line " << line_number << endl; exit(1);
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


/////////////////////////////////////////////////////////////////////////////

inline int mul(int a, int b)
{
    int s = 1, r;
    if ( a < 0 ) s = -s, a = -a;
    if ( b < 0 ) s = -s, b = -b;
    if ( a == '1' ) r = b;
    else if ( b == '1' ) r = a;
    else if ( a == b ) s = -s, r = '1';
    else {
        if ( (b-a+3)%3 == 2 ) s = -s;
        r = 'i'+'j'+'k'-(a+b);
    }
    return r*s;
}

int product(const string& s)
{
    int r = '1';
    for ( auto c : s ) r = mul(r, c);
    return r;
}

int power(int a, size_t e)
{
    if ( a == '1' ) {
        e %= 1;
    }
    else if ( a == -'1' ) {
        e %= 2;
    }
    else {
        e %= 4;
    }
    int r = '1';
    forN ( i, e ) r = mul(r, a);
    return r;
}


int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    NTR = 10000;
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }

    forN ( nc, num_cases ) {
        // parse input
        size_t L, X;
        cin >> L >> X >> skip_endl;
        string s;
        cin >> s >> skip_endl;
        assert(s.size() == L);
        
        // error check
        if ( !cin ) input_error();
        // main code

	bool good = false;
        int p = power(product(s), X);
        if ( p == -'1' ) {
            if ( X > 12 ) X = 12;
            string t;
            forN ( i, X ) t += s;
            size_t i = 0;
            int r = '1';
            for ( ; r != 'i' && i < t.size(); ++i ) {
                r = mul(r, t[i]);
            }
            r = '1';
            for ( ; r != 'j' && i < t.size(); ++i ) {
                r = mul(r, t[i]);
            }
            good = i < t.size();
        }

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << (good? "YES": "NO");
        cout << endl;
    }
    cin >> skip_eof;
}
