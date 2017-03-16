#include <bits\stdc++.h>
using namespace std;
int a[1005];
int main(){
    freopen("A-large.in", "r", stdin); freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qr = 1; qr <= T; ++qr){
        string s;
        int n;
        cin >> n >> s;
        memset(a, 0, sizeof(a));
        int ans = 0;
        int pre = 0;
        for(int i = 1; i <= n; ++i){
            pre += s[i - 1] - '0';
            if(i - pre > 0 && (s[i] - '0' > 0)){
                ans = max(ans, i - pre);
            }
        }
        cout << "Case #" << qr << ": " << ans << "\n";
    }
    return 0;
}
