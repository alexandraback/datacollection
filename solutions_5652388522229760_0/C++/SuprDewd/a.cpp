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

int digs(int n) {
    int res = 0;
    while (n) {
        res |= 1 << (n%10);
        n /= 10;
    }
    return res;
}

int main() {
    int ts;
    cin >> ts;
    rep(t,0,ts) {
        int n;
        cin >> n;
        cout << "Case #" << (t+1) << ": ";
        if (n == 0) {
            cout << "INSOMNIA" << endl;
        } else {
            int res = 0, i = 1;
            for ( ; res != (1<<10)-1; i++) {
                res |= digs(i * n);
            }
            cout << (n*i-n) << endl;
        }
    }
    return 0;
}

