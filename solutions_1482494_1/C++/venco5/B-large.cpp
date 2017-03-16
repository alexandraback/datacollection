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
const int MAX_N = 1024;
int N;
int r1[MAX_N], r2[MAX_N];
int ss[MAX_N];

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
        cin >> N >> skip_endl;
        forN ( i, N ) cin >> r1[i] >> r2[i] >> skip_endl;

        // error check
        if ( !cin ) {
            cout << "Error parsing input" << endl;
            return 1;
        }
        // main code

        int ret = INF;
        forN ( i, N ) {
            ss[i] = 0;
        }
        int s = 0, moves = 0;
        while ( s != 2*N ) {
            bool changed = 0;
            int best_move = -1, best_r2 = 0;
            forN ( i, N ) {
                if ( ss[i] == 2 ) continue;
                if ( s >= r2[i] ) {
                    ++moves;
                    s += 2-ss[i];
                    ss[i] = 2;
                    changed = 1;
                    continue;
                }
                if ( ss[i] ) continue;
                if ( s >= r1[i] ) {
                    if ( r2[i] > best_r2 ) {
                        best_r2 = r2[i];
                        best_move = i;
                    }
                }
            }
            if ( changed ) continue;
            if ( best_move < 0 ) break;
            int i = best_move;
            ++moves;
            ss[i] = 1;
            s += 1;
        }
        if ( s == 2*N ) ret = moves;

        // output
        cout << "Case #"<<nc+1<<": ";
        if ( ret == INF )
            cout << "Too Bad";
        else
            cout << ret;
        cout << endl;
    }
}
