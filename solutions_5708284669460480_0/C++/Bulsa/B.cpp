#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define FORD(i,a,b) for(ll i=ll(b)-1; i>=(a); --i)
using namespace std;

using ll = long long;

static vector<ll> possible;
static string letters;
static string target;
static char buf[10];
static ll K, L, S; 
static void rek(ll pos) {
    if(pos == S) {
        possible.push_back(0);
        ll &x = possible[possible.size()-1];
        for(int from = 0; from < S;) {
            auto it = search(buf+from,buf+S,begin(target),end(target));
            from = it-buf;
            if(from != S) {
                ++from, ++x;
            }
        }
        return;
    }
    for(char c : letters) {
        buf[pos] = c;
        rek(pos+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    FOR(tc,1,T+1) {
        cin >> K >> L >> S;
        cin >> letters >> target;
        possible.clear();
        rek(0);
        buf[L] = 0;
        double res = 0;
        ll ma = *max_element(begin(possible),end(possible));
        for(ll x : possible) {
            res += (ma-x)/double(possible.size());
        }
        cout << "Case #" << tc << ": " << fixed << setprecision(10) << res << endl;
    }
}
