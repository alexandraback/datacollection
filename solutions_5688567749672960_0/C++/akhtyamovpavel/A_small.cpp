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


int dp[10000005];


int rev(int val) {
    int ans = 0;
    while(val > 0) {
        int cur_val = val % 10;
        ans = 10 * ans + cur_val;
        val /= 10;
    }
    return ans;
}
int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
    	int N;
        cin >> N;
        for (int i = 0; i <= 10000005; ++i) {
            dp[i] = 1000000000;
        }
        dp[0] = 0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i-1] + 1;
            if (i % 10 > 0)
            dp[i] = min(dp[i], dp[rev(i)] + 1);

        }
        

        cout << "Case #" << _ << ": ";
        //Output answer 
        cout << dp[N];
        
        cout << "\n";
    }
    return 0;
}