#include<iostream>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
    freopen("A-small-attempt0 (2).in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    int te = 1;
    cin >> t;
    while(t--) {
        long long p,q;
        char ch;
        cin >> p >> ch >> q;
        cout << "Case #" << te << ": ";
        long long gc = __gcd(p,q);
        p /= gc;
        q /= gc;
        int ans = 0;
        if(q&(q-1)) {
            ans = -1;
        } else {
            while(p != q) {
                ans ++;
                p *= 2;
                long long gc = __gcd(p,q);
                p /= gc;
                q /= gc;
                long long x = log2(p);
                p = 1<<x;
            }
        }
        if(ans == -1) cout << "impossible";
        else cout << ans;
        cout << endl;
        te++;
    }
}
