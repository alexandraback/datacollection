#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define EP 1e-10

using namespace std;

typedef long long ll;
typedef vector<double> vd;

ll count(string &cur, string &target) {
    ll total = 0;
    ll maxsize = (ll)(cur.size())-(ll)(target.size());
    for (ll i = 0; i <= maxsize; ++i) {
        bool success = true;
        for (ll j = 0; j < target.size(); ++j) {
            if (cur[i+j] != target[j]) {
                success = false;
                break;
            }
        }

        if (success) {
            ++total;
        }
    }

    return total;
}

void backtrack(string &cur, ll idx, string &keyboard, string &target, ll &maxB, ll &total) {
    if (idx == cur.size()) {
        ll result = count(cur, target);
        maxB = max(maxB, result);
        total += result;
    }
    else {
        for (ll i = 0; i < keyboard.size(); ++i) {
            cur[idx] = keyboard[i];
            backtrack(cur, idx+1, keyboard, target, maxB, total);
        }
    }
}

int main() {
   /* string a = "AA";
    string b = "AAA";
    cerr << count(a, b) << endl;*/
    ll T;
    cin >> T;
    for (ll cs = 1; cs <= T; ++cs) {
        ll K, L, S;
        cin >> K >> L >> S;

        string keyboard;
        cin >> keyboard;
        string target;
        cin >> target;

        string cur(S, ' ');
        ll total = 0;
        ll maxB = 0;
        backtrack(cur, 0, keyboard, target, maxB, total);

        double nStrings = pow(keyboard.size(), S);
        double eBanana = total/nStrings;
        printf("Case #%lld: %.8lf\n", cs, maxB-eBanana);
    }
    return 0;
}
