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
#define FILEIN "C.in"
#define FILEOUT "C.out"



int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
    	
        int C;
        int D;
        int V;
        cin >> C >> D >> V;
        int A[D];
        for (int i = 0; i < D; ++i) {
            cin >> A[i];
            // cout << A[i] << endl;
        }

        bool used[35];
        for (int i =0; i < 35; ++i) {
            used[i] = false;
        }
        for (int i =0; i < (1<<D); ++i) {
            int cur = i;
            // cout << cur << endl;
            int mask[D];
            for (int j =0; j < D; ++j) {
                mask[j] = cur % 2;
                cur /=2;
            }
            int sum = 0;
            for (int j = 0; j < D; ++j) {
                sum += mask[j]*A[j];
                // cout << sum << " " << mask[j] << " " << A[j] << endl;
            }
            // cout << sum  << " skskd" << endl;
            if (sum <= V) {
                // cout << sum << " " << used << endl;
               used[sum] = true;
            }
        }
        int ans = 0;
        // cout << "ok" << endl;
        for (int i =1; i <= V; ++i) {
            if (!used[i]) {
                
                 // cout << i << endl; 
                ans++;
                for (int j = V; j >= 0; --j) {
                    if (j < i) {
                        break;
                    } 
                    if (!used[j]) {
                        if (used[j-i]) {
                            used[j] = true;
                        }
                    }
                }
                used[i] = true;
            }
        }

        cout << "Case #" << _ << ": ";
        //Output answer 
        
        cout << ans;
        cout << "\n";
    }
    return 0;
}