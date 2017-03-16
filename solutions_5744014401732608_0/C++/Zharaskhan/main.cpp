#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <bitset>

#include <complex>

//#include <unordered_map>
//#include <unordered_set>

#define llong long long int
#define pb push_back
#define mp make_pair
#define pr pair <int, int>
#define X first
#define Y second
#define endl "\n"
using namespace std;
const int MAXN = 5e5 + 7;
//const int INF = 1e9 + 7;
//const llong LINF = 1e18;
const llong MOD = 1e9 + 7;
//const long double EPS = 1e-18;
using namespace std;
int tests;

llong dp[50];
bool a[50][50];
int main() {
#ifdef DEBUG
    
    double beg = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#else
    //freopen("centroid.in", "r", stdin);
    //freopen("centroid.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);cin.tie();
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int b;
        llong m;
        scanf("%d%lld", &b, &m);
        vector<pr> v;
        for (int i = 1; i <= b; i++) {
            for (int j = i + 1; j <= b; j++) {
                v.pb(mp(i, j));
            }
        }
        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= b; j++) {
                a[i][j] = 0;
            }
        }
        bool found = false;
        for (int mask = 0; mask < (1 << (int)v.size()); mask++) {
            for (int j = 0; j < v.size(); j++) {
                if (mask & (1 << j)) {
                    a[v[j].first][v[j].second] = 1;
                } else {
                     a[v[j].first][v[j].second] = 0;
                }
            }
            dp[b] = 1;
            
            for (int i = b - 1; i >= 1; i--) {
                dp[i] = 0;
                for (int j = i + 1; j <= b; j++) {
    
                    if (a[i][j]) {
                        
                        dp[i] += dp[j];
                    }
                }
            }
            if (dp[1] == m) {
                cout << "Case #" << test << ": POSSIBLE\n";
                for (int i = 1;  i <= b; i++) {
                    for (int j = 1;  j <= b; j++) {
                        cout << a[i][j] ;
                    }
                    cout << '\n';
                }
                found = true;
                break;
            }
            
        }
        if (!found) {
            
            cout << "Case #" << test << ": IMPOSSIBLE\n";
        }
        
        
        
    }
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}