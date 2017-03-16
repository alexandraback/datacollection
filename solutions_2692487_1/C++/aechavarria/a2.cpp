using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

const int MAXN = 105;
const int MAXS = 1000006;
const int INF = 1 << 25;
int a[MAXN];
int dp[MAXN];

int main(){
    int cases;
    cin >> cases;
    for (int run = 1; run <= cases; ++run){
        int size, n;
        cin >> size >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a+1, a+n+1);
        
        dp[0] = 0;
        int best = n;
        long long j = size;
        for (int i = 1; i <= n; ++i){
            //D(a[i]);
            dp[i] = dp[i-1];
            while (a[i] >= j){
                if (j == 1){
                    dp[i] = INF;
                    break;
                }
                j += j-1;
                dp[i]++;
            }
            assert(a[i] < j or j == 1);
            if (j != 1) j += a[i];
            best = min(best, n-i + dp[i]);
        }
        
        printf("Case #%d: %d\n", run, best);
    }
    return 0;
}
