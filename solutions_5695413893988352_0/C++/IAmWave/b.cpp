// * These disses! They're almost TOO sick!!
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

void solve() {
    ll pows[20];
    pows[0] = 1;
    rep(i, 1, 20) pows[i] = 10 * pows[i - 1];
    string s, t;
    cin >> s >> t;
    ll d0 = 0;
    int n = s.size();
    rep(i, 0, n) {
        d0 *= 10;
        if(s[i] != '?') d0 += s[i] - '0';
        if(t[i] != '?') d0 -= t[i] - '0';
    }
    ll bs = 2e18, bt = 2e18;
    string bss, btt;
    ll bd = 2e18;
    rep(mask, 0, (1 << n)) {
        string cs = s, ct = t;
        ll d = d0;
        rep(i, 0, n) {
            bool neg = mask & (1 << i);
            if(d < 0) {
                if(s[i] == '?') {
                    ll cur = 0;
                    while(d < 0 && cur < 9) {
                        //cout << i << ": " << pows[n-1-i] << endl;
                        if(neg) {
                            if(d + pows[n - 1 - i] < 0) {
                                d += pows[n - 1 - i];
                            } else break;
                        } else {
                            d += pows[n - 1 - i];
                        }
                        cur++;
                    }
                    cs[i] = cur + '0';
                }
                if(t[i] == '?') ct[i] = '0';
            } else {
                if(t[i] == '?') {
                    ll cur = 0;

                    while(d > 0 && cur < 9) {
                        if(neg) {
                            if(d - pows[n - 1 - i] > 0) {
                                d -= pows[n - 1 - i];
                            } else break;
                        } else {
                            d -= pows[n - 1 - i];
                        }
                        cur++;
                    }
                    ct[i] = cur + '0';
                }
                if(s[i] == '?') cs[i] = '0';
            }
        }
        //cout<<cs<< " " <<ct<<" "<<d <<endl;
        if(llabs(d) <= llabs(bd)) {
            ll sv = stoi(cs);
            ll tv = stoi(ct);
            if(llabs(d) < llabs(bd) || sv < bs || (sv == bs && tv < bt)) {
                bs = sv;
                bt = tv;
                bd = d;
                bss = cs;
                btt = ct;
            }
        }
        //cout << d << endl;
    }
    cout << bss << " " << btt;
}

int main() {
    freopen("b2.in", "r", stdin);
    freopen("b2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(i, 0, q) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
