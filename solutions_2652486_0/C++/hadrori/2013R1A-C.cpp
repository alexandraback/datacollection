#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

int R, N, M, K;

int main(){
    int t;
    cin >> t;
    cin >> R >> N >> M >> K;
    cout << "Case #1:" << endl;
    rep(z,1,R+1){
        vector<int> prd(K);
        rep(i,0,K){
            cin >> prd[i];
        }
        int ans = -1;
        rep(i,2,6){
            rep(j,i,6){
                rep(k,j,6){
                    bool flag = true;
                    rep(a, 0, K){
                        int tmp = prd[a];
                        if(tmp%k==0) tmp/= k;
                        if(tmp%j==0) tmp/= j;
                        if(tmp%i==0) tmp/= i;
                        if(tmp != 1) {
                            flag = false;
                        }
                    }
                    if(flag) {
                        ans = i*100+j*10+k*1;
                        break;
                    }
                }
                if(ans != -1) break;
            }
            if(ans != -1) break;
        }
        cout << ans << endl;
        
        
    }
    
    return 0;
}