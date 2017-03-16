#include <iostream>
using namespace std;

int T, R, C, W;

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> R >> C >> W;
        
        int ans = R * (C / W) + W - 1;
        if(C % W) ans++;

        cout << "Case #" << t << ": " << ans << endl;
    }
}
