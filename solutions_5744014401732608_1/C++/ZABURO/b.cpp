#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        ll B, M;
        cin >> B >> M;
        if(B == 2){
            if(M == 1){
                cout << "Case #" << t+1 << ": POSSIBLE" << endl;
                cout << "01" << endl << "00" << endl;
            }else{
                cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
            }
            continue;
        }
        ll maxM = 1;
        for(int i=0;i<B-2;i++){
            maxM *= 2;
        }
        if(maxM < M){
            cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
            continue;
        }
        vector<vec> ans(B, vec(B, 0));
        ll p = 1;
        int idx = 1;
        while(p < M){
            ans[idx][B-1] = 1;
            for(int i=idx-1;i>=1;i--){
                ans[idx][i] = 1;
            }
            idx++;
            p *= 2;
        }
        ans[0][B-1] = 1;
        M -= 1;
        idx = 1;
        while(M > 0){
            if(M % 2 == 1){
                ans[0][idx] = 1;
            }
            M /= 2;
            idx++;
        }
        cout << "Case #" << t+1 << ": POSSIBLE" << endl;
        for(int i=0;i<B;i++){
            for(int j=0;j<B;j++){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}