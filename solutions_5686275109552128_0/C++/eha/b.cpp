#include <bits/stdc++.h>
using namespace std;

int c[1010];

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        memset(c, 0, sizeof(c));
        vector<int> p;
        int d; cin >> d; while(d--){ int v; cin >> v; c[v]++; }
        int ans = 1145141919;
        for(int v = 1; v <= 1000; v++){
            int tmp = 0;
            for(int i = 0; i <= 1000; i++) tmp += c[i] * ((i-1)/v);
            ans = min(ans, tmp+v);
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
