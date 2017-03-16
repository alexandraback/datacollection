//Author: Yuan25
//I THINK THEREFORE I AM

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int, int> P;

int T;
int D;
int arr[1005];

int main(void) {
    
    //优化IO速度
    std::ios::sync_with_stdio(false);
    
    cin >> T;
    int t = 1;
    
    while (T--) {
        int ans = 0, maxx = 0;
        cin >> D;
        for (int i = 0 ; i < D; i++) {
            cin >> arr[i];
            maxx = max(arr[i], maxx);
        }
        
        ans = maxx;
        for (int j = 1; j <= maxx ; j++) {
            int use = 0;
            for (int i = 0; i < D; i++) {
                use += ceil((double)arr[i] / (double)j) - 1;
            }
            ans = min(ans, use+j);
        }
        
        cout << "Case #" << t++ << ": " << ans << endl;
    }
    
    return 0;
}

