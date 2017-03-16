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
const int MAXN = 1e5 + 7;
//const int INF = 1e9 + 7;
//const llong LINF = 1e18;
//const llong MOD = 1e9 + 7;
//const long double EPS = 1e-18;
using namespace std;
int tests;
string F[1010], S[1010];
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
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> F[i] >> S[i];
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            set <string> FF, SS;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    FF.insert(F[i]);
                    SS.insert(S[i]);
                }
            }
            bool good = true;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (!FF.count(F[i]) || !SS.count(S[i])) {
                        good = false;
                    }
                }
            }
            if (good) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
        cout << "Case #" << test << ": " << ans << '\n';
        
    }
    
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}