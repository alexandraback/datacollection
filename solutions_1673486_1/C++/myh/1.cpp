#include <iostream>
using namespace std;


int main() {
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int tt, a, b;
    double x[100010], ans, now, q, r;
    cin >> tt;
    for (int ttt = 0; ttt < tt; ++ttt) {
        cin >> a >> b;    
        for (int i = 0; i < a; ++i) cin >> x[i];
        
        //Enter
        ans = b+2;
        
        
        //Backspace i times
        for (int i = 0; i <= a; ++i) {
            q = 1;
            for (int j = 0; j < a-i; ++j) q *= x[j];
            now = q*(b-(a-i)+1+i) + (1-q)*(b-(a-i)+1+i+b+1);
            if (now < ans) ans = now;
        }
        
        printf("Case #%d: %.6lf\n", ttt+1, ans);
    }
    
    return 0;
}
