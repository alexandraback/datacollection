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

ifstream in( "c.in" );
ofstream out( "c.out" );

int r, n, m, k;
vi v, nums, cnt, bestdigits;

int const nexperiments = 40000;
int best;

void search(int i) {
    if (i == n) {
        cnt.assign(v.size() + 1, 0);
        for (int j = 0; j < nexperiments; ++j) {
            int mul = 1;
            for (int k = 0; k < n; ++k) {
                if (rand() & 1)
                    mul *= nums[k];
            }
            int idx = find(all(v), mul) - v.begin();
            cnt[idx]++;
        }
        if (find(all(cnt), 0) == cnt.end()) {
            int sum = nexperiments - cnt[cnt.size()-1];
            if (sum > best)  {
                best = sum;
                bestdigits = nums;
            }
        }
        return;
    }
    for (nums[i] = i ? nums[i-1] : 2; nums[i] <= m; ++nums[i])
        search(i+1);
}

void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ":\n";
        in >> r >> n >> m >> k;
        nums = vi(n);
        for (; r > 0; --r) {
            best = 0;
            v = vi(k);
            for (int i = 0; i < k; ++i) {
                in >> v[i];
            }
            sort(all(v));
            v.erase(unique(all(v)), v.end());
            search(0);
            for (int i = 0; i < n; ++i)
                out << bestdigits[i];
            out << "\n";
        }
    }
}