#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool palid(ll n) {
    ostringstream os;
    os << n;
    string s = os.str();
    string t = s;
    reverse(t.begin(), t.end());
    //cout << s << " : " << t << endl;
    return s == t;
}

vector<ll> P;
void init() {
    for (ll i = 1; i <= 10000000; i++) {
        if (palid(i) && palid(i * i)) {
            P.push_back(i*i);
        }
    }
}

ll solve(ll a, ll b) {
    return upper_bound(P.begin(), P.end(), b) - lower_bound(P.begin(), P.end(), a);
}

ll T;
int main() {
    init();
    cin >> T;
    for (ll tc = 1; tc <= T; tc++) {
        ll A, B;
        cin >> A >> B;
        cout << "Case #" << tc << ": " << solve(A, B) << endl;
    }
    return 0;
}
