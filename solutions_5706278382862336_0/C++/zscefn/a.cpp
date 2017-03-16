#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if(a % b == 0) return b;
    return gcd(b, a%b);
}
ll f(ll p, ll cute) {
    if(p == (1ll<<cute)) return cute;
    if(p >= (1ll<<(cute-1))) {
        return cute-1;
    }
    return f(p, cute-1);
}
int main() {
    int t;
    cin>>t;
    for(int i = 0; i < t; ++i) {
        cout<<"Case #"<<i+1<<": ";
        ll p = 0;
        ll q = 0;
        string lol;
        cin>>lol;
        int haha = 0;
        for(int i = 0; i < lol.size(); ++i) {
            if(lol[i] == '/') {
                haha = 1;
                continue;
            }
            if(!haha) {
                p *= 10;
                p += lol[i]-'0';
            }
            else {
                q *= 10;
                q += lol[i] - '0';
            }
        }
        ll w = gcd(p, q);
        p /= w;
        q /= w;
        ll cute = 0;
        for(ll i = 0; i < 60; ++i) {
            ll a = (1ll<<i);
            if(q == a) {
                cute = i;
            }
        }
        //cout<<cute<<'\n';
        if(1ll<<cute != q) {
            cout<<"impossible\n"; 
            continue;
        }
        cout<<cute-f(p, cute)<<'\n';;

    }
}
