#include <iostream>
using namespace std;

int main(){
    int Z,R,C,W;
    int ans = 0;
    cin >> Z;
    for(int ca=1;ca<=Z;ca++){
        cin >> R >> C >> W;
        ans = W-1 + C/W;
        if(C % W != 0){
            ans++;
        }
        ans += (R-1) * C/W;
        cout << "Case #" << ca << ": " << ans <<"\n";
    }
    return 0;
}
