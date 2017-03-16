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
//const int MAXN = 1e5 + 7;
//const int INF = 1e9 + 7;
//const llong LINF = 1e18;
//const llong MOD = 1e9 + 7;
//const long double EPS = 1e-18;
using namespace std;
vector<int> a[110];
vector<int> perm;

int main() {
#ifdef DEBUG
    
    double beg = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#else
    //freopen("centroid.in", "r", stdin);
    //freopen("centroid.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie();
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        
        
        for (int i = 0; i < 2 * n - 1; i++) {
            a[i].clear();
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                a[i].pb(x);
            }
        }
        bool found = false;
        for (int mask = 0; mask < (1 << (2 * n - 1)) && !found; mask++) {
            if (__builtin_popcount(mask) == n) {
                vector< vector<int>  > T;
                multiset<vector<int> > S;
                for (int i = 0; i < 2 * n - 1; i++) {
                    if (mask & (1 << i)) {
                        T.pb(a[i]);
                    }
                }
                sort (T.begin(), T.end());
                for (int j = 0; j < n; j++) {
                    vector<int> tmp;
                    for (int i = 0; i < n; i++) {
                        tmp.pb(T[i][j]);
                    }
                    S.insert(tmp);
                }
                bool bad = false;
                for (int i = 0; i < 2 * n - 1; i++) {
                    if (mask & (1 << i)) {
                    
                    } else {
                        if (S.count(a[i])) {
                            S.erase(S.find(a[i]));
                        } else {
                            bad = true;
                            break;
                        }
                    }
                }
                if (!bad && S.size() == 1) {
                    cout << "Case #" << test << ": ";
                    for (auto ss: S) {
                        for (auto sss: ss) {
                            cout << sss << ' ';
                        }
                        cout << endl;
                        found = true;
                    }
                }
            }
        }
       
    }
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}