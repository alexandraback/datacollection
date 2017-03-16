#include <bits\stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("B-small-attempt3.in", "r", stdin); freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qr = 1; qr <= T; ++qr){
        int ans = 0;
        int n;
        cin >> n;
        int sm = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            sm += a[i];
            ans = max(ans, a[i]);
        }
        for(int res = 1; res <= 1000; ++res){
            int days = 0;
            for(int i = 0; i < n; ++i){
                days += (a[i] + res - 1) / res - 1;
            }
            ans = min(ans, days + res);
        }
        cout << "Case #" << qr << ": " << ans << "\n";
    }
    return 0;
}
