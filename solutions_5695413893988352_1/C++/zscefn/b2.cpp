#include <vector>
#include <sstream>
#include <iostream>
#define F first
#define S second
typedef unsigned long long ll;
using namespace std; 
ll abss(ll a, ll b) {
    if(a > b) return a-b;
    if(b > a) return b-a;
    return 0;
}

int main() {
    ll tt;
    cin>>tt;
    for(ll xx = 1; xx <= tt; ++xx) {
        cout<<"Case #"<<xx<<": ";
        string cod, jam;
        cin>>cod>>jam;
        pair<ll, ll> ans = {0, 1.1e19};
        ll n = cod.size();
        for(int i = 0; i < n; ++i) {
            if(cod[i] != '?' && jam[i] != '?' && cod[i] != jam[i]) goto ohi2;

        }
        for(int i = 0; i < n; ++i) {
            if(cod[i] == jam[i] && cod[i] == '?') {
                cod[i] = jam[i] = '0';
            }
            if(cod[i] == '?') cod[i] = jam[i];
            if(jam[i] == '?') jam[i] = cod[i];
        }
        cout<<cod<<' '<<jam<<'\n';
        continue;
        ohi2:;
        //eka jossa erit
        for(ll i = 0; i < n; ++i) {
            //cout<<"LOL "<<i<<'\n';
            for(int j = 0; j < 10; ++j) {
                if(cod[i] != '?' && cod[i] != '0'+j) continue;
                for(int k = 0; k < 10; ++k) {
                    if(jam[i] != '?' && jam[i] != '0'+k) continue;
                    if(j == k) continue;
                    string cod2 = cod;
                    string jam2 = jam;
                    cod2[i] = j+'0';
                    jam2[i] = k+'0';
                    //cout<<cod2<<' '<<jam2<<' ';
                    for(int l = i+1; l < n; ++l) {
                        if(cod2[l] == '?') {
                            if(j >k) {
                                cod2[l] = '0';
                            }
                            else {
                                cod2[l] = '9';
                            }
                        }
                        if(jam2[l] == '?') {
                            if(j >k) {
                                jam2[l] = '9';
                            }
                            else {
                                jam2[l] = '0';
                            }
                        }
                    }
                    //cout<<cod2<<' '<<jam2<<'\n';
                    stringstream ss(cod2);
                    stringstream ss2(jam2);
                    ll a,b;
                    ss>>a;
                    ss2>>b;
                    ll zz = (abss(a,b)==abss(ans.F,ans.S));
                    if(abss(a, b) < abss(ans.F, ans.S)) {
                        ans.F = a;
                        ans.S = b;
                    }
                    else if(zz == 1 && a < ans.F) {
                        ans.F = a;
                        ans.S = b;
                    }
                    else if(zz == 1 && a == ans.F & b < ans.S) {
                        ans.F = a;
                        ans.S = b;
                    }
                }
            }
            if(cod[i] != '?' && jam[i] != '?' && cod[i] != jam[i]) break;
            if(cod[i] == '?' && jam[i] == '?') cod[i] = jam[i] = '0';
            else if(cod[i] == '?') cod[i] = jam[i];
            else if(jam[i] == '?') jam[i] = cod[i];
        }
        vector<int> v1(n);
        vector<int> v2(n);
        for(int i = n-1; i >= 0; --i) {
            v1[i] = ans.F %10;
            v2[i] = ans.S %10;
            ans.F /= 10;
            ans.S /= 10;
        }
        for(auto x: v1) cout<<x;
        cout<<' ';
        for(auto x: v2) cout<<x;
        cout<<'\n';
        continue;
    }
}
