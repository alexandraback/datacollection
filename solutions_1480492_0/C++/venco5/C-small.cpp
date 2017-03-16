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

// binary gcd
template<typename T>
T gcd(T a, T b)
{
    if ( a < 0 ) a = -a;
    if ( b < 0 ) b = -b;
    int s = 0;
    while ( a&&b ) {
        if ( a&b&1 ) {
            if ( a > b )
                a -= b;
            else
                b -= a;
        }
        if ( !((a|b)&1) ) ++s;
        if ( !(a&1) ) a >>= 1;
        if ( !(b&1) ) b >>= 1;
    }
    return (a|b)<<s;
}

template<class T>
class ratio
{
public:
    ratio()
        : u(0), l(1)
    {
    }
    ratio(T n)
        : u(n), l(1)
    {
    }
    ratio(T uu, T ll)   
        : u(uu), l(ll)
    {
        normalize();
    }
    operator T() const {
        return u/l;
    }
private:
    void normalize()
    {
        if ( l < 0 ) {
            u = -u;
            l = -l;
        }
        T g = gcd(u, l);
        if ( g != 1 ) {
            u /= g;
            l /= g;
        }
    }
public:
    double getDouble() const
    {
        return double(u) / l;
    }
    T getInteger() const
    {
        return u / l;
    }
    bool isInteger() const
    {
        return l == 1;
    }
    T getU() const
    {
        return u;
    }
    T getL() const
    {
        return l;
    }
    ratio<T> getFraction() const
    {
        return ratio<T>(u % l, l);
    }
    bool operator==(ratio<T> r) const
    {
        return u == r.u && l == r.l;
    }
    bool operator!=(ratio<T> r) const
    {
        return u != r.u || l != r.l;
    }
    bool operator<(ratio<T> r) const
    {
        return u*r.l < r.u*l;
    }
    bool operator<=(ratio<T> r) const
    {
        return u*r.l <= r.u*l;
    }
    bool operator>(ratio<T> r) const
    {
        return u*r.l > r.u*l;
    }
    bool operator>=(ratio<T> r) const
    {
        return u*r.l >= r.u*l;
    }
    ratio<T> operator-() const
    {
        return ratio<T>(-u, l);
    }
    ratio<T>& operator+=(ratio<T> r)
    {
        u = u*r.l + r.u*l;
        l *= r.l;
        normalize();
        return *this;
    }
    ratio<T>& operator-=(ratio<T> r)
    {
        u = u*r.l - r.u*l;
        l *= r.l;
        normalize();
        return *this;
    }
    ratio<T>& operator*=(ratio<T> r)
    {
        u *= r.u;
        l *= r.l;
        normalize();
        return *this;
    }
    ratio<T>& operator/=(ratio<T> r)
    {
        u *= r.l;
        l *= r.u;
        normalize();
        return *this;
    }
private:
    T u;
    T l;
};

template<typename T>
inline
ratio<T> operator+(ratio<T> r1, ratio<T> r2)
{
    return r1 += r2;
}
template<typename T>
inline
ratio<T> operator+(T r1, ratio<T> r2)
{
    return r2 += r1;
}
template<typename T>
inline
ratio<T> operator+(ratio<T> r1, T r2)
{
    return r1 += r2;
}
template<typename T>
inline
ratio<T> operator-(ratio<T> r1, ratio<T> r2)
{
    return r1 -= r2;
}
template<typename T>
inline
ratio<T> operator-(T r1, ratio<T> r2)
{
    ratio<T> r(r1);
    return r -= r2;
}
template<typename T>
inline
ratio<T> operator-(ratio<T> r1, T r2)
{
    return r1 -= r2;
}
template<typename T>
inline
ratio<T> operator*(ratio<T> r1, ratio<T> r2)
{
    return r1 *= r2;
}
template<typename T>
inline
ratio<T> operator*(T r1, ratio<T> r2)
{
    return r2 *= r1;
}
template<typename T>
inline
ratio<T> operator*(ratio<T> r1, T r2)
{
    return r1 *= r2;
}
template<typename T>
inline
ratio<T> operator/(ratio<T> r1, ratio<T> r2)
{
    return r1 /= r2;
}

ostream& operator<<(ostream& out, const ratio<int>& r)
{
    return out << r.getU() << '/' << r.getL();
}

typedef ratio<int> R;
/////////////////////////////////////////////////////////////////////////////

const int MAX_N = 64;
int N;
char cc0[MAX_N];
char cc[MAX_N];
char ncc[MAX_N];
int ss[MAX_N], pp0[MAX_N];
R ct;
R cp[MAX_N];

bool set_lane(int i, char c)
{
    cc[i] = c;
    forN ( j, N ) {
        if ( j == i ) continue;
        if ( cc[j] != cc[i] ) continue;
        if ( cp[i] < cp[j]+5 && cp[i] > cp[j]-5 ) return 0;
    }
    return 1;
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
        cin >> N >> skip_endl;
        forN ( i, N ) cin >> cc0[i] >> ss[i] >> pp0[i] >> skip_endl;
        
        // error check
        if ( !cin ) { cout << "Error parsing input" << endl; return 1; }
        // main code

        double ret = -1;

        ct = 0;
        forN ( i, N ) cp[i] = pp0[i];
        map<R, vector< pair<int, int> > > tt, tt0;
        int C = 0;
        forN ( j, N ) forN ( i, N ) {
            if ( j == i ) continue;
            if ( ss[i] <= ss[j] ) continue;
            if ( pp0[i] > pp0[j]-5 ) continue;
            R t(pp0[j]-5-pp0[i], ss[i]-ss[j]);
            tt[t].push_back(make_pair(i, j));
            ++C;
        }
        tt0 = tt;
        //TR(tt|C);
        forN ( bb, 1<<C ) {
            forN ( i, N ) cc[i] = cc0[i];
            int cbb = bb;
            bool crash = 0;
            forIter ( k, tt0 ) {
                ct = k->first;
                forN ( i, N ) cp[i] = pp0[i]+ct*ss[i];
                //TR(ct);
                //TR(A(cp,N));
                
                forIter ( c, k->second ) {
                    int i = c->first;
                    int j = c->second;
                    ncc[i] = ncc[j] = 0;
                }

                forIter ( c, k->second ) {
                    int i = c->first;
                    int j = c->second;
                    int d = cbb&1; cbb >>= 1;
                    char nci = "RL"[d];
                    char ncj = "LR"[d];
                    //TR(i|nci);
                    //TR(j|ncj);
                    if ( ncc[i] && ncc[i] != nci ) {
                        crash = 1;
                        break;
                    }
                    ncc[i] = nci;
                    if ( ncc[j] && ncc[j] != ncj ) {
                        crash = 1;
                        break;
                    }
                    ncc[j] = ncj;
                }
                if ( crash ) break;
                forIter ( c, k->second ) {
                    int i = c->first;
                    int j = c->second;
                    if ( ncc[i] != cc[i] ) {
                        if ( !set_lane(i, ncc[i]) ) {
                            crash = 1;
                            break;
                        }
                    }
                    if ( ncc[j] != cc[j] ) {
                        if ( !set_lane(j, ncc[j]) ) {
                            crash = 1;
                            break;
                        }
                    }
                }
                if ( crash ) break;
            }
            if ( !crash ) {
                //TR(bb|A(cc,N));
                ret = -1;
                break;
            }
            double t = ct.getDouble();
            //TR(bb|t);
            ret = max(ret, t);
        }

        // output
        cout << "Case #"<<nc+1<<": ";
        if ( ret < 0 )
            cout << "Possible";
        else
            cout << fixed << setprecision(5) << ret;
        cout << endl;
    }
}
