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

ifstream in( "d.in" );
ofstream out( "d.out" );

int main() {
    int ntest;
    in >> ntest;
    for (int test = 1; test <= ntest; ++test) {
        int k, n;
        in >> k >> n;
        multiset<int> start_keys;
        for (int i = 0; i < k; ++i) {
            int t; in >> t;
            start_keys.insert(t);
        }
        vi key(n);
        vector<multiset<int>> keys(n);
        for (int i = 0; i < n; ++i) {
            int nkeys;
            in >> key[i];            
            in >> nkeys;
            for (int j = 0; j < nkeys; ++j) {
                int t; in >> t;
                keys[i].insert(t);
            }
        }
        vi mark(1 << n);
        vi prev(1 << n);
        queue<int> q;
        q.push(0); mark[0] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            multiset<int> k = start_keys;
            for (int i = 0; i < n; ++i) if (cur & (1 << i))
                k.insert(all(keys[i]));
            for (int i = 0; i < n; ++i) if (cur & (1 << i))
                k.erase(k.find(key[i]));
            for (int i = 0; i < n; ++i) if (!(cur & (1 << i)) && k.find(key[i]) != k.end()) {
                int next = cur | (1 << i);
                if (!mark[next]) {
                    mark[next] = 1;
                    q.push(next);
                    prev[next] = i;
                }
            }
        }

        int last = (1 << n) - 1;
        out << "Case #" << test << ": ";
        if (mark[last]) {
            vi v;
            while (last) {
                v.push_back(prev[last] + 1);
                last = last & ~(1 << prev[last]);
            }
            copy(v.rbegin(), v.rend(), ostream_iterator<int>(out, " "));
        } else
            out << "IMPOSSIBLE";
        out << "\n";
    }
    return 0;
}