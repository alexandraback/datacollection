#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#pragma warning( disable : 4244 4267 4018 4996 4800 )
//#pragma comment( linker, "/stack:10000000" )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "b.in" );
ofstream out( "b.out" );

template <class T>
void make_max(T& x, T val) {
    if (x < val)
        x = val;
}

void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        int e, r, n;
        in >> e >> r >> n;
        vi v(n);
        ll total = 0;
        vector<pii> w;
        for (int i = 0; i < n; ++i) {
            in >> v[i];
            w.push_back(make_pair(v[i], n-i));
        }
        sort(all(w));
        reverse(all(w));
        set<int> taken;
        for (int i = 0; i < w.size(); ++i) {
            int idx = n - w[i].second;
            auto it = taken.lower_bound(idx);
            int nextidx = -1, previdx = -1;
            if (it != taken.end()) {
                nextidx = *it;                
            }
            if (it != taken.begin()) {
                --it;
                previdx = *it;                
            }
            int take = e;
            if (nextidx != -1 && previdx != -1)
                take = max(0LL, min<ll>(take, ll(r) * (nextidx-previdx) - e));
            if (nextidx != -1)
                take = min<ll>(take, ll(r) * (nextidx - idx));
            if (previdx != -1)
                take = min<ll>(take, ll(r) * (idx-previdx));
            total += ll(v[idx]) * take;
            taken.insert(idx);
        }
        out << total << "\n";
    }
}