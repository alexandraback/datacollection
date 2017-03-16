#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <bitset>
#include <cmath>
#include <numeric>
#include <complex>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
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


int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    NTR = 100;
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    forN ( nc, num_cases ) {
        // parse input
        int X, R, C;
        cin >> X >> R >> C >> skip_endl;

        // error check
        if ( !cin ) input_error();
        // main code

        if ( R > C ) swap(R, C);
        assert(R <= C);
        bool good = true;
        if ( good ) {
            // uneven
            if ( R*C%X ) {
                //TR(R|C|X|"uneven");
                good = false;
            }
        }
        if ( good ) {
            // wide on both sides
            if ( X >= 2*R+1 ) {
                TR(R|C|X|"wide");
                good = false;
            }
        }
        if ( good ) {
            // split even
            if ( X > 2 && X == 2*R ) {
                TR(R|C|X|"even split");
                good = false;
            }
        }
        if ( good ) {
            // split odd
            if ( X == 2*R-1 ) {
                for ( int a = 0, b = (R-1)*(R-1); a <= b; ++a, --b ) {
                    int ka = (X-a%X)*2%X;
                    int kb = (X-b%X)*2%X;
                    int c = ka+kb+R;
                    if ( c > C ) {
                        TR(R|C|X|a|b|ka|kb|c);
                        good = false;
                        break;
                    }
                }
            }
        }
        if ( good ) {
            // hole
            if ( X >= 7 ) {
                TR(X|"hole");
                good = false;
            }
        }
        
        // output
        cout << "Case #"<<nc+1<<": ";
        cout << (good? "GABRIEL": "RICHARD");
        cout << endl;
    }
    cin >> skip_eof;
}
