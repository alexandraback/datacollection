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
        int N, a, b, asw = 0, acc = 0, cnt = 0, ok = 0, ind, MAX;
        
        cin >> N;
        vector< pair< int, int > > v(N);
        
        fori(i,N)
        {
            cin >> a >> b;
            v[i] = make_pair(a,b);
        }
        
        while( cnt < N && !ok )
        {
            ok = 1;
            
            fori(i,N)
            {
                if ( v[i].first != INF && acc >= v[i].second ) 
                {
                    v[i].second = INF;
                    ++asw;
                    ++cnt;
                    acc += 2;
                    ok = 0;
                    break;
                }
            }
            
            if ( !ok ) continue;
            
            fori(i,N)
            {
                if ( v[i].first == INF && acc >= v[i].second ) 
                {
                    v[i].second = INF;
                    ++asw;
                    ++cnt;
                    ++acc;
                    ok = 0;
                    break;
                }
            }
            
            if ( !ok ) continue;
            
            MAX = -1;
            ind = -1;
            fori(i,N)
            {
                if ( acc >= v[i].first && v[i].second != INF ) 
                {
                    if ( v[i].second > MAX )
                    {
                        MAX = v[i].second;
                        ind = i;
                    }
                }
            }
            if ( ind != -1 )
            {
                v[ind].first = INF;
                ++asw;
                ++acc;
                ok = 0;
            }
        }
        
        cout << "Case #" << t << ": ";
        if ( cnt == N ) cout << asw << endl;
        else cout << "Too Bad" << endl;
    }
    return 0;
}

