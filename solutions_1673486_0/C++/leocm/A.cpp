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
    int T;
    cin >> T;
    forr(t,1,T)
    {
        int A, B;
        double aux, asw;
        cin >> A >> B;
        vector< double > v(A), acc_prob(A);
        fori(i,A) 
        {
            cin >> v[i];
            if ( i == 0 ) acc_prob[i] = v[i];
            else acc_prob[i] = acc_prob[i-1] * v[i];
        }
        asw = acc_prob[A-1] * (B-A+1) + (1-acc_prob[A-1]) * (2*B-A+2);
        if ( cmpD(B+2.0, asw) < 0 ) asw = B+2.0;
        forr(i,1,A-1)
        {
            aux = acc_prob[A-i-1] * (2*i+B-A+1) + (1-acc_prob[A-i-1]) * (2*i+2*B-A+2);
            if ( cmpD(aux, asw) < 0 ) asw = aux;
        }
        if ( cmpD(A+B+1.0, asw) < 0 ) asw = A+B+1.0;
        printf("Case #%d: %.6lf\n", t, asw);
    }
    return 0;
}

