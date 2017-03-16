#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <cstring>


using namespace std;
typedef long long LL;
#define x1 gjigu
#define y1 djigd
template<typename T>
inline T Abs(const T& value) { return value < 0 ? -value : value; }
template<typename T>
inline T Sqr(const T& value) { return value * value; }


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        int n, s, p;
        cin >> n >> s >> p;
        vector<int> a(n);
        vector< vector<int> > ans(n, vector<int>(s+1));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int sur = 0;
            int nsur = 0;
            for (int f1 = a[i]/3-2; f1 <= a[i]/3 + 2; ++f1)
                for (int f2 = a[i]/3-2; f2 <= a[i]/3 + 2; ++f2)
                    for (int f3 = a[i]/3-2; f3 <= a[i]/3 + 2; ++f3) {
                        if (f1+f2+f3 == a[i] && f1 >= 0 && f2 >= 0 && f3 >= 0) {
                            if (max(f1, max(f2, f3)) - min(f1, min(f2, f3)) <= 2) {
                                sur = max(sur, max(f1, max(f2, f3)));
                            } 
                            if (max(f1, max(f2, f3)) - min(f1, min(f2, f3)) <= 1) {
                                nsur = max(nsur, max(f1, max(f2, f3)));
                            }
                        }
                    }
                        
//            cerr << sur << "\t" << nsur << endl;

            for (int j = 0; j <= min(s, i+1); ++j) {
                if (i > 0)
                    ans[i][j] = ans[i-1][j] + int(nsur >= p);
                else
                    ans[i][j] = int(nsur >= p);
                if (j > 0) {
                    if (i > 0)    
                        ans[i][j] = max(ans[i][j], ans[i-1][j-1] + int(sur >= p));
                    else
                        ans[i][j] = max(ans[i][j], int(sur >= p));
                }
            }
        }
        cout << "Case #" << tt+1 << ": " << ans[n-1][s] << endl;
    }
    

    return 0;
}
