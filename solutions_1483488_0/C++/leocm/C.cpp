#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;
using namespace tr1;

#define fori(i, n) for ( int i = 0; i < (n); ++i )
#define forr(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford(i, a, b) for ( int i = (a); i >= (b); --i )
#define tr(it, a, b) for ( typeof(a) it = (a); it != (b); ++it )
#define all(x) (x).begin(),(x).end()
#define sz size()
#define pb push_back

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")

template<class T> string a2s(T x) { ostringstream o; o << x; return o.str(); }
template<class T> T s2a(string s) { istringstream i(s); T x; i >> x; return x; }

const double EPS = 1e-9;
const int INF = 0x3F3F3F3F;

int cmpD( double x, double y = 0, double tol = EPS )
{
    return ( x <= y + tol ) ? ( x + tol < y ) ? -1 : 0 : 1;
}

int main()
{
	ios::sync_with_stdio(false);
    long long T, A, B, m;
    string sn, sm;
    cin >> T;
    forr(t,1,T)
    {
        set< pair< long, long > > S;
        cin >> A >> B;
        forr(n,A,B-1)
        {
            sn = a2s(n);
            forr(i,1,sn.sz-1)
            {
                sm = sn.substr(i) + sn.substr(0, i);
                m = s2a<long long>(sm);
                if ( m > n && m <= B ) S.insert( make_pair(n, m) );
            }
        }
        cout << "Case #" << t << ": " << S.sz << endl;
    }
    return 0;
}

