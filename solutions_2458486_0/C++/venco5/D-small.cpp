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
#define forIter(I,C) for(typeof((C).end()) I=(C).begin(); I!=(C).end(); ++I)
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

const int MAX_N = 210;
int K, N;
struct Chest {
    int enter;
    VI leave;
};
Chest cc[MAX_N];
int kk[MAX_N];

int BAD = 999999999;
int dp[1<<20], dpend;
int go(int bb)
{
    if ( dp[bb] >= 0 ) return dp[bb];
    forN ( i, N ) {
        if ( bb & (1<<i) ) continue;
        int k = cc[i].enter;
        if ( !kk[k] ) continue;
        --kk[k];
        forIter ( j, cc[i].leave ) ++kk[*j];
        int next = go(bb|(1<<i));
        ++kk[k];
        forIter ( j, cc[i].leave ) --kk[*j];
        if ( next != BAD ) {
            return dp[bb] = i;
        }
    }
    return dp[bb] = BAD;
}

int main(int argc, const char** argv)
{
    NTR = 100;
    int num_cases = 1;
    cin >> num_cases >> skip_endl;
    int part_cases = 0;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    
    forN ( nc, num_cases ) {
        // parse input
        fill_n(kk, MAX_N, 0);
        cin >> K >> N >> skip_endl;
        forN ( i, K ) {
            int k;
            cin >> k;
            kk[k] += 1;
        }
        cin >> skip_endl;
        forN ( i, N ) {
            int n;
            cin >> cc[i].enter >> n;
            cc[i].leave.resize(n);
            forN ( j, n ) cin >> cc[i].leave[j];
        }
        cin >> skip_endl;

        fill_n(dp, 1<<N, -1);
        dp[(1<<N)-1] = 0;
        ostringstream ret;
        if ( go(0) == BAD ) {
            ret << "IMPOSSIBLE";
        }
        else {
            int bb = 0;
            forN ( i, N ) {
                int next = dp[bb];
                if ( i ) ret << ' ';
                ret << (next+1);
                bb |= 1<<next;
            }
        }
        
        // output
        cout << "Case #"<<nc+1<<": ";
        cout << ret.str();
        cout << endl;
    }
}
