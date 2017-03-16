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
#define forIter(I,C) for(auto I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef long long i64; typedef unsigned long long u64;
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<string> VS;

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

int play_bad(const vector<double>& v1, const vector<double>& v2)
{
    int ret = 0;
    int b2 = 0, e2 = v2.size();
    forIter ( i, v1 ) {
	if ( *i < v2[b2] ) --e2;
	else ++b2, ++ret;
    }
    return ret;
}

int play_good(const vector<double>& v1, const vector<double>& v2)
{
    int ret = 0;
    int b2 = 0, e2 = v2.size();
    for ( size_t i = v1.size(); i--; ) {
	if ( v1[i] < v2[e2-1] ) --e2;
	else ++b2, ++ret;
    }
    return ret;
}

int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    NTR = 100;
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) part_cases = atoi(argv[1]);
    forN ( nc, num_cases ) {
        // parse input
	int N;
        cin >> N >> skip_endl;
	vector<double> v1(N);
        forN ( i, N ) {
            cin >> v1[i];
        }
        cin >> skip_endl;
	vector<double> v2(N);
        forN ( i, N ) {
            cin >> v2[i];
        }
        cin >> skip_endl;
        
        // error check
        if ( !cin ) { cout << "Error parsing input" << endl; return 1; }
        // main code

	sort(ALL(v1));
	sort(ALL(v2));
	int r1 = play_bad(v1, v2);
	int r2 = play_good(v1, v2);

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << r1 << ' ' << r2;
        cout << endl;
    }
}
