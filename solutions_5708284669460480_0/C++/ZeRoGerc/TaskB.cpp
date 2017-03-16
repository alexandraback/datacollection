#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int T, s;
long double k, l, prob[300];
string kw, need;

long double count(int l, int p) {
    string temp = need;
    
    long double ans = 0;
    for (int i = 0; i < l; i++) {
        if ((temp.size() - i <= p) && (temp.substr(i, (int)temp.size() - i) == need.substr(0, (int)temp.size() - i))) {
            temp += need.substr(temp.size() - i, need.size() - (temp.size() - i));
        }
    }
    
    temp = temp.substr(0, l);
    for (int i = 0; i < l - p + 1; i++) {
        if (temp.substr(i, p) == need) {
            ans += 1.;
        }
    }
    
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> T;
    long double pr, ans;
    for (int I = 0; I < T; I++) {
        for (int i = 0; i < 300; i++) prob[i] = 0;
        cin >> k >> l >> s;
        
        cin >> kw;
        for (int i = 0; i < kw.size(); i++) {
            prob[(int)kw[i]] += 1. / k;
        }
        
        pr = 1;
        cin >> need;
        for (int i = 0; i < need.size(); i++) {
            pr *= prob[(int)need[i]];
        }
        
        cout.precision(6);
        
        if (pr == 0. || s < need.size()) {
            cout << fixed << "Case #" << I + 1 << ": " << 0. << '\n';
        } else {
            pr *= ((long double)(s) - l + 1.);
            ans = (count(s, (int)need.size())) - pr;
            cout << fixed << "Case #" << I + 1 << ": " << ans << '\n';
        }
    }

}