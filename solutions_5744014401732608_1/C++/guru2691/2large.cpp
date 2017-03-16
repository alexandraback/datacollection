#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define lli long long int

int path[60][60];
lli b,m;
lli findways() {
    lli dp[60];
    memset(dp,0,sizeof(dp));
    dp[b-1] = 1;
    for (int i = b - 2; i >= 0; i--) {
        for (int j = 0; j < b; j++) {
            if (path[i][j])
                dp[i] += dp[j];
        }
    }
    return dp[0];
}
int main() {
        
    ios::sync_with_stdio(false);

    int t; cin >> t;
    int ca = 0;
    while (t--) {
        ca++;
        cout << "Case #" << ca << ": ";
        int bi[60];
        memset(bi,0,sizeof(bi));
        cin >> b >> m;
        lli x = 1ll<<(b-2);
        memset(path,0,sizeof(path));
        if (m > x) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            m--;
            bi[b-1] = 1;
            for (lli i = 0; i < b; i++) {
                if (m&(1ll<<i)) {
                    bi[b-i-2] = 1;
                }
            }
            for (int i = 0; i < b; i++) {
                if (bi[i]){ 
                    cout << "1"; 
                    //path[0][i] = 1;
                }
                else cout << "0";
            }
            cout << '\n';
            for (lli i = 1; i < b; i++) {
                for (lli j = 0; j <= i; j++) {
                    cout << "0";
                }
                for (lli j = i+1; j < b; j++) {
                    cout << "1";
                    //path[i][j] = 1;
                }
                cout << '\n';
            }

                /*if (findways() != m+1)
                cout << endl << findways() << " " << b << " " << m+1 << endl;
                assert(findways() == m+1);*/
        }

    }
    
    return 0;
        
}