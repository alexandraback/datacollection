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
#include <iterator>
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

#ifdef LOCAL
ifstream in( "c.in" );
#else
istream & in = cin;
#endif
//ostream & out = cout;
ofstream out( "c.out" );

int n, m;
vs zip;
vvi flights;
map<pair<int, int>, string> cache;

string solve(int mask, int v)
{
    if (mask == (1 << v))
        return zip[v];
    auto key = make_pair(mask, v);
    auto it = cache.find(key);
    if (it != cache.end())
        return it->second;
    string & res = cache[key];
    int submask = mask & ~(1 << v);
    for (int subset = submask; subset > 0; subset = (subset - 1) & submask) {
        for (int w = 0; w < n; ++w) if ((subset & (1 << w)) && flights[v][w]) {
            string s = solve(subset, w);
            if (s.empty())
                continue;
            string t = solve(mask & ~subset, v);
            if (t.empty())
                continue;
            string cur = t + s;
            if (res.empty() || res > cur)
                res = cur;
        }
    }
    return res;
}

int main() {
   int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        cache.clear();
        in >> n >> m;
        zip = vs(n);       
        for (int i = 0; i < n; ++i)
            in >> zip[i];
        flights = vvi(n, vi(n));        
        for (int i = 0; i < m; ++i) {
            int from, to;
            in >> from >> to;
            --from; --to;
            flights[from][to] = flights[to][from] = 1;
        }
        string res = solve((1 << n) - 1, min_element(all(zip)) - zip.begin());
        out << "Case #" << test << ": " << res;
        out << "\n";
    }
    return 0;
}