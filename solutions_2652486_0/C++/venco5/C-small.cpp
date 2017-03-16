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
#include <cstring>
#include <sstream>
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

template<int S>
struct Set {
    unsigned char vv[S];
    bool operator<(const Set& s) const {
        forN ( i, S ) if ( vv[i] != s.vv[i] ) return vv[i] < s.vv[i];
        return 0;
    }
};
template<int S>
ostream& operator<<(ostream& out, const Set<S>& s)
{
    forN ( i, S ) out << char(s.vv[i]+'0');
    return out;
}

int main(int argc, const char** argv)
{
    NTR = 10000;
    int num_cases = 1;
    cin >> num_cases >> skip_endl;
    int part_cases = 0;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }

    forN ( nc, num_cases ) {
        // parse input  
        u32 R, N, M, K;
        cin >> R >> N >> M >> K >> skip_endl;

        if ( N == 3 ) {
            typedef Set<3> S;
            int sc = 0;
            map<S, int> ss;
            map<u64, map<S, int> > ps;
            forNF ( v1, 2, M+1 ) {
                forNF ( v2, 2, M+1 ) {
                    forNF ( v3, 2, M+1 ) {
                        Set<3> s;
                        s.vv[0] = v1;
                        s.vv[1] = v2;
                        s.vv[2] = v3;
                        sort(s.vv, s.vv+N);
                        ss[s] += 1;
                        sc += 1;
                        forN ( bb, 8 ) {
                            u64 p = 1;
                            forN ( i, 3 ) {
                                if ( bb&(1<<i) ) p *= s.vv[i];
                            }
                            ps[p][s] += 1;
                        }
                    }
                }
            }

            cout << "Case #"<<nc+1<<":"<<endl;
            forN ( test, R ) {
                u64 pp[16];
                forN ( i, K ) cin >> pp[i];
                cin >> skip_endl;
                
                // error check
                if ( !cin ) { cout << "Error parsing input" << endl; return 1; }
                
                // main code
                map<S, double> sp, np;
                forIter ( i, ss ) {
                    sp[i->first] = double(i->second)/sc;
                }
                TR(sp);
                forN ( i, K ) {
                    u64 p = pp[i];
                    map<S, int>& ap = ps[p];
                    np.clear();
                    double sum = 0;
                    forIter ( j, ap ) {
                        if ( sp.count(j->first) )
                            sum += np[j->first] = j->second*sp[j->first];
                    }
                    forIter ( j, np )
                        j->second /= sum;
                    swap(sp, np);
                    TR(sp);
                }
                vector<pair<double, S> > rp;
                forIter ( i, sp ) {
                    rp.push_back(make_pair(-i->second, i->first));
                }
                sort(ALL(rp));
                TR(rp);
                cout << rp[0].second << endl;
            }
            return 0;
        }

        int ret = 0;

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << ret;
        cout << endl;
    }
}
