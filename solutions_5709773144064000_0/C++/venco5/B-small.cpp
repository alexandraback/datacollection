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
#define forIter(I,C) for(auto I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long i64;
typedef unsigned long long u64;

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


int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    //NTR = 1000;
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) part_cases = atoi(argv[1]);
    forN ( nc, num_cases ) {
        // parse input
	double C, F, X;
        cin >> C >> F >> X >> skip_endl;

        // error check
        if ( !cin ) {
            cout << "Error parsing input" << endl;
            return 1;
        }
        // main code

	double ret = X/2;
	double t0 = 0;
	for ( unsigned k = 1; ; ++k ) {
	    t0 += C/(2+(k-1)*F);
	    double t = t0+X/(2+k*F);
	    if ( t > ret ) break;
	    ret = t;
	}

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << fixed << setprecision(7) << ret;
        cout << endl;
    }
}
