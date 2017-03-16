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
    freopen("D-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qw = 1; qw <= T; ++qw){
        ll k, c, s;
        cin >> k >> c >> s;
        cout << "Case #" << qw <<": ";
        for(int i = 1; i <= k; ++i){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
