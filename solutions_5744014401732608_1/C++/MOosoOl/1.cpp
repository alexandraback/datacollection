#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[55][55];

main(){
    freopen("1.in", "r", stdin);
   freopen("1.out", "w", stdout);
    int t; cin >> t;
    int T = 0;
    while(t --){
        memset(a, 0, sizeof a);
        T ++;
        cout << "Case #" << T <<": ";
        long long B, M;
        cin >> B >> M;
        for(int i = 1; i < B; ++i)
            for(int j = i + 1; j < B; ++j)
                a[i][j] = 1;
        bool im = false;

        a[0][B - 1] = 1;
        M --;
        int x = B - 2;

        while(M){
            if(x == 0 && M > 0){
                cout << "IMPOSSIBLE\n";
                im = true;
                break;
            }
            if(M & 1)
                a[0][x] = 1;
            M >>= 1;
            x --;

        }

        if(im) continue;
        cout << "POSSIBLE\n";
        for(int i = 0; i < B; ++i){
            for(int j = 0; j < B; ++j){
                cout << a[i][j];
            }
            cout << "\n";
        }

    }
    return 0;
}
