#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define repd(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template
ll pow2(int p) {
    ll ret = 1;
    rep(i, p){
        ret *= 2;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int B;
        ll M;
        cin >> B >> M;
//        cout << "Case #" << q + 1 << ": " << B << ", " << M << endl;
        if(M > pow2(B - 2)){
            cout << "Case #" << q + 1 << ": ";
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<vector<int>> lat(B, vector<int>(B, 0));
        
        vector<ll> sub(B - 1);
        sub[0] = 1;
        repd(i, 1, B - 1){
            sub[i] = pow2(i - 1);
        }
        
        rep(i, B - 1){
            repd(j, i + 1, B - 1){
                lat[i][j] = 1;
            }
        }
        
        int p = B - 2;
        while(M > 0){
            if(M >= sub[p]){
                if(M == 1){
                    lat[0][B - 1] = 1;
                    break;
                }
                lat[p][B - 1] = 1;
                M -= sub[p];
            }
            p--;
        }
        
        
        cout << "Case #" << q + 1 << ": ";
        
        cout << "POSSIBLE" << endl;
        
        rep(i, B){
            rep(j, B){
                if(j) cout << " ";
                cout << lat[i][j];
            }
            cout << endl;
        }
        
        
    }
    
    return 0;
}