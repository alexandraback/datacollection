#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int R, C, W;
        cin >> R >> C >> W;
        printf("Case #%d: %d\n", t, (R - 1) * C / W + C / W - 1 + W + (C % W == 0 ? 0 : 1));
    }
    return 0;
}
