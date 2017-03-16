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
set<int> ll[MAX_N*2];
char twopass[MAX_N];

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
        forN ( bb, 1<<N ) {
            int t = 0;
            forN ( i, N ) {
                twopass[i] = (bb>>i)&1;
                t += 1+twopass[i];
            }
            if ( t >= ret ) continue;
            forN ( i, N*2+1 ) ll[i].clear();
            forN ( i, N ) {
                int need = twopass[i]? r1[i]: r2[i];
                ll[need].insert(i);
            }
            int s = 0, more = N;
            forN ( c, s+1 ) {
                forIter ( k, ll[c] ) {
                    --more;
                    int i = *k;
                    if ( twopass[i] == 2 ) {
                        s += 1;
                    }
                    else if ( !twopass[i] ) {
                        s += 2;
                    }
                    else {
                        s += 1;
                        int need = r2[i];
                        if ( need > s ) {
                            ++more;
                            ll[need].insert(i);
                            twopass[i] = 2;
                        }
                        else {
                            s += 1;
                        }
                    }
                }
            }
            if ( more ) continue;
            ret = t;
        }

        // output
        cout << "Case #"<<nc+1<<": ";
        if ( ret == INF )
            cout << "Too Bad";
        else
            cout << ret;
        cout << endl;
    }
}
