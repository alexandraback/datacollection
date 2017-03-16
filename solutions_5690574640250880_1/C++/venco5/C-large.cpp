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
#define forIter(I,C) for(auto I=(C).begin(); I!=(C).end(); ++I)
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

int R, C, M, E;
vector<string> ret;

void clear_rect(int R, int C)
{
    forN ( i, R ) forN ( j, C ) ret[i][j] = '.';
}

void try_solve(int R)
{
    if ( E >= 2*R+2 ) {
	int x = E%R;
	clear_rect(R, E/R);
	forN ( i, x ) ret[i][E/R] = '.';
	if ( x == 1 ) {
	    ret[1][E/R] = '.';
	    ret[R-1][E/R-1] = '*';
	}
	ret[0][0] = 'c';
    }
    else if ( E < 4 ) {
	return;
    }
    else if ( E%2 == 0 ) {
	clear_rect(E/2, 2);
	ret[0][0] = 'c';
    }
    else {
	// E is odd
	// 5 <= E <= 2*R+1
		
    }
}

int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    NTR = 1000;
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) part_cases = atoi(argv[1]);
    forN ( nc, num_cases ) {
        // parse input  
        cin >> R >> C >> M >> skip_endl;
        
        // error check
        if ( !cin ) { cout << "Error parsing input" << endl; return 1; }
        // main code

	bool ch = R > C;
	if ( ch ) swap(R, C);
	assert(R <= C);
	bool impossible = 0;
	ret.assign(R, string(C, '*'));
	E = R*C-M;
	if ( E == 1 ) {
	    ret[0][0] = 'c';
	}
	else if ( R == 1 ) {
	    clear_rect(1, E);
	    ret[0][0] = 'c';
	}
	else if ( R == 2 ) {
	    if ( E%2 == 0 && E > 2 ) {
		clear_rect(2, E/2);
		ret[0][0] = 'c';
	    }
	    else {
		impossible = 1;
	    }
	}
	else {
	    try_solve(R);
	    if ( ret[0][0] != 'c' ) {
		for ( int r = R-1; r >= 3; --r ) {
		    int c = (E+r-1)/r;
		    //TR(r|c);
		    if ( c > C ) break;
		    try_solve(r);
		    if ( ret[0][0] == 'c' ) break;
		}
	    }
	    if ( ret[0][0] != 'c' ) {
		impossible = 1;
	    }
	}

	if ( impossible ) {
	    ret.assign(1, "Impossible");
	    ch = 0;
	}

	if ( ch ) {
	    vector<string> r2(C, string(R, '.'));
	    forN ( i, R ) forN ( j, C ) r2[j][i] = ret[i][j];
	    swap(ret, r2);
	}

        // output
        cout << "Case #"<<nc+1<<":";
	forIter ( i, ret ) cout << '\n' << *i;
        cout << endl;
    }
}
