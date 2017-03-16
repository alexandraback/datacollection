//tonynater

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1000;

int N, A[MAXN];

int main() {
    freopen("/Users/tonynater/Downloads/B-small-attempt2.in", "r", stdin);
    freopen("/Users/tonynater/Tony/Computer/Xcode_repos/Miscellaneous/GCJ_2015/QB/QB_small.out", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        int low = 1, high = 1000;
        while(low < high) {
            int mid = (low+high)/2;
            
            bool v = false;
            for(int i = 0; i < mid; i++) {
                int cur = 0;
                for(int j = 0; j < N; j++) {
                    cur += (A[j]+mid-i-1)/(mid-i)-1;
                }
                if(cur <= i) {
                    v = true;
                    break;
                }
            }
            
            if(v) {
                high = mid;
            }else {
                low = mid+1;
            }
        }
        
        cout << "Case #" << t+1 << ": " << low << '\n';
    }
    
    return 0;
}