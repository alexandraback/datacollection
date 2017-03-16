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
#define forIter(I,C) for(typeof((C).end()) I=(C).begin(); I!=(C).end(); ++I)
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

const int INF = 999999999;
const int MAX_N = 128;
int I, J;
int h[MAX_N][MAX_N];
int maxi[MAX_N], maxj[MAX_N];

int main(int argc, const char** argv)
{
    int num_cases = 1;
    cin >> num_cases >> skip_endl;
    int part_cases = 0;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    forN ( nc, num_cases ) {
        // parse input
        cin >> I >> J >> skip_endl;
        fill_n(maxi, I, 0);
        fill_n(maxj, J, 0);
        forN ( i, I ) {
            forN ( j, J ) {
                cin >> h[i][j];
                maxi[i] = max(maxi[i], h[i][j]);
                maxj[j] = max(maxj[j], h[i][j]);
            }
            cin >> skip_endl;
        }

        // error check
        if ( !cin ) {
            cout << "Error parsing input" << endl;
            return 1;
        }
        // main code

        bool ok = 1;
        forN ( i, I ) forN ( j, J ) {
            if ( h[i][j] != min(maxi[i], maxj[j]) ) {
                ok = 0;
                break;
            }
        }

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << (ok? "YES": "NO");
        cout << endl;
    }
}
