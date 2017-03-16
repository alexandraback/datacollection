#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<set>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;

int n, m;
vector<int> row[111], col[111];

int main() {
    int runs; s(runs);
    for (int t=1; t <= runs; ++t) {
        s(n); s(m);
        vector< pair< int, pair< int, int > > > a;
        
        for (int x=0; x < n; x++)
        for (int y=0; y < m; y++) {
            int v; s(v);
            a.pb(make_pair(v, make_pair(x, y) ));
            row[x].pb(v);
            col[y].pb(v);
        }
        for (int x=0; x < n; x++)
            sort(all(row[x]));
        for (int y=0; y < m; y++)
            sort(all(col[y]));
        
        bool ok = true;
        sort(all(a));
        for (int i=0; i < (int)a.size(); i++) {
            int x = a[i].second.first,
                y = a[i].second.second,
                v = a[i].first;
            
            while (row[x].size() > 0 && *row[x].begin() == v) {
                row[x].erase(row[x].begin());
            }
            
            while (col[y].size() > 0 && *col[y].begin() == v) {
                col[y].erase(col[y].begin());
            }
            
            if (!(col[y].size() == 0 || row[x].size() == 0)) {
                ok = false;
                break;
            }
        }
        
        for (int x=0; x < n; x++) row[x].clear();
        for (int y=0; y < m; y++) col[y].clear();
        
        printf("Case #%d: %s\n", t, ok ? "YES" : "NO");
    }
}
