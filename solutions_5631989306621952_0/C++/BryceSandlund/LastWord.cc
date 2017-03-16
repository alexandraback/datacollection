#include <iostream>
#include <list>

using namespace std;

typedef long long ll;
typedef list<char> lc;

int main() {
    ll T;
    cin >> T;
    for (ll cs = 1; cs <= T; ++cs) {
        string S;
        cin >> S;

        lc ans;
        ans.push_front(S[0]);

        for (ll i = 1; i < S.size(); ++i) {
            if (S[i] >= ans.front()) {
                ans.push_front(S[i]);
            }
            else {
                ans.push_back(S[i]);
            }
        }

        printf("Case #%lld: ", cs);
        for (lc::iterator it = ans.begin(); it != ans.end(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
}
