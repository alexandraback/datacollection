#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "A.in"
#define FILEOUT "A.out"


int dp[55][55];
int dpedge[55]; //len, how

int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
        int R, C;
        cin >> R >> C;
        int W;
        cin >> W;

        int need = C/W;
        int ans = (R-1)*need;

        for (int i = 0; i <= 25; ++i) {
            dpedge[i] = INF;
        }

        dpedge[0] = 0;
        dpedge[1] = 2;
        for (int i = 2; i < 25; ++i) {
            for (int k = 1; k <= i; ++k) {
                int tmp = max(k + dpedge[i-k], i-k+1 + 1 + dpedge[k - 1]);
                dpedge[i] = min(tmp, dpedge[i]);
            }
        }
        // for (int i = 0; i < 25; ++i) {
            // cout << dpedge[i] << endl;
        // }
        
        for (int i = 0; i <= 25; ++i) {
            for (int j =0; j <= 25; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= C; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (i == j) {
                    dp[i][j] = j;
                } else {
                    dp[i][j] = INF; 
                    for (int k = 1; k <= i; ++k) {
                        int tmp = 0;
                        if (k >= j +1 || i - k >= j)
                            tmp = 1 + max((k-1)/j + dp[i-k][j], (i-k)/j + dp[k-1][j]); 
                        // cout << i << " " << j << " " << dp[i][j] << endl;
                        if (k >= j && i - k >= j - 1) {
                            tmp = max(tmp, 1 + dpedge[j-1]);
                        } 
                        else if (k >= j && i -k < j - 1) {
                            tmp = max(tmp, dpedge[i -k] + j - (i-k));
                        } else if (k < j && i - k >= j - 1) {
                            tmp = max(tmp, dpedge[k - 1] + j - (k - 1));
                        } else 
                        {
                            tmp = max(tmp, dpedge[i - j] + (2*j - i));
                        }
                        dp[i][j] = min(dp[i][j], tmp);
                    }
                }
            }
        }
        cout << "Case #" << _ << ": ";
        //Output answer 
        cout <<  ans + dp[C][W];
        
        cout << "\n";
    }
    return 0;
}