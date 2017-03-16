#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;
ll bin_pow(ll a, int n){
    ll res = 1;
    while(n){
        if(n & 1) res *= a;
        n >>= 1;
        a *= a;
    }
    return res;
}
int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qw = 1; qw <= T; ++qw){
        ll k, c, s;
        cin >> k >> c >> s;
        cout << "Case #" << qw <<": ";
        if(c + s < k + 1){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            ll pos = 0;
            int cnt = 0;
            for(int i = c; i >= 2; --i){
                if(i != c) pos += bin_pow(k, i - 1);
                cnt++;
                if(cnt >= k - 1) break;
            }
            for(int i = min(cnt + 1, (int)k); i <= k; ++i){
                cout << i + pos << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
