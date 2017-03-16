#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
template <class T> int size(const T &x) { return x.size(); }
const int INF = 2147483647;
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

ll down(int k, ll cur, ll idx) {
    return k * cur + idx;
}

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        int k, c, s;
        cin >> k >> c >> s;
        bool done = false;
        ll at = 0;
        vector<ll> res;
        rep(i,0,s) {
            ll here = 0;
            rep(j,0,c) {
                here = down(k, here, at);
                at++;
                if (at == k) {
                    at = k-1;
                    done = true;
                }
            }
            res.push_back(here);
            if (done) break;
        }
        cout << "Case #" << (t+1) << ":";
        if (done) {
            iter(it,res) {
                cout << " " << *it + 1;
            }
            cout << endl;
        } else {
            cout << " IMPOSSIBLE" << endl;
        }
    }
    return 0;
}

