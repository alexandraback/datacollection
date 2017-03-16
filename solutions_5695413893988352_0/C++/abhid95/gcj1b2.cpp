#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll i, df, t, _t, p, ans1, ans2, k, l, j, mn, f;
string s1, s2, st1, st2;
string go(ll n, ll len) {
    string tmp, s;
    ll d, ii;
    s = "";
    while(n > 0) {
        tmp.push_back(n%10+'0');
        n/=10;
    }
    reverse(tmp.begin(), tmp.end());
    d = tmp.length();
    if(d < len) {
        for(ii = 0; ii < len-d; ii++) {
            s.push_back('0');
        }
    }
    s = s+tmp;
    return s;
 }
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        cin>>s1>>s2;
        l = s1.length();
        mn = 1e18;
        p = pow(10, l);
        for(i = 0; i < p; i++) {
            for(j = 0; j < p; j++) {
                f = 1;
                st1 = go(i, l);
                st2 = go(j, l);

                for(k = 0; k < l; k++) {
                    if(s1[k] == '?') continue;
                    if(s1[k] != st1[k]) {
                        f = 0;
                        break;
                    }
                }
                for(k = 0; k < l; k++) {
                    if(s2[k] == '?') continue;
                    if(s2[k] != st2[k]) {
                        f = 0;
                        break;
                    }
                }

                if(f) {
                    df = abs(i-j);
                    if(df < mn) {
                        ans1 = i;
                        ans2 = j;
                        mn = df;
                    }
                }
            }
        }
        printf("Case #%lld: ", _t);
        cout<<go(ans1, l)<<" "<<go(ans2, l)<<endl;
    }

    return 0;
}

