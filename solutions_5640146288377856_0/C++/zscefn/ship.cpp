#include <iostream>
using namespace std;
int dp[1<<20];
int main() {
    int tt;
    cin>>tt;
    for(int xx = 1; xx <= tt; ++xx) {
        int r, c ,w;
        cin>>r>>c>>w;
        int ans = c/w;
        ans *= (r-1);
        if(w == 1) {
            ans += c;
        }
        else {
            while(c > 2*w) {
                c -= w;
                ++ans;
            }
            if(c > w) {
                ans += w+1;
            }
            else {
                ans += w;
            }
        }
        cout<<"Case #"<<xx<<": "<<ans<<'\n';

    }
}
