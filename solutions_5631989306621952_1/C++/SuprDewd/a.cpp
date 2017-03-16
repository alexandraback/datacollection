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

bool can(string pre, string s) {
    int at = 0;
    vector<char> end;
    for (int i = size(s) - 1; i >= 0 && at < size(pre); i--) {
        if (s[i] == pre[at]) {
            at++;
        } else {
            end.push_back(s[i]);
            // end = string("") + s[i] + end;
            // end += s[i];
        }
    }
    for (int j = size(end)-1; j >= 0 && at < size(pre); j--) {
        if (end[j] != pre[at]) {
            return false;
        }
        at++;
    }
    return true;
}

int main() {
    // cout << can("C", "CAB") << endl;
    // return 0;
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        string s;
        cin >> s;
        string res;
        while (size(res) < size(s)) {
            for (char c = 'Z'; c >= 'A'; c--) {
                // cout << res << " " << c << " " << can(res + c, s) << endl;
                if (can(res + c, s)) {
                    res += c;
                    break;
                }
            }
        }
        cout << "Case #" << (t+1) << ": " << res << endl;
    }

    return 0;
}

