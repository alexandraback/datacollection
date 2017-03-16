#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
typedef unsigned long long LL;

template<typename T> inline int sz(const T& x) { return (int)x.size(); }

LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int tc; cin >> tc;

    for(int t = 1; t <= tc; ++t) {
        LL P, Q;
        char ch;
        cin >> P;
        cin >> ch;
        cin >> Q;

        LL g = gcd(P, Q);
        P /= g; Q /= g;
        LL A = 1LL << 40LL;

        if (A % Q) {
            cout << "Case #" << t << ": impossible" << endl;
        } else {
            LL k = (A / Q) * P;
            int ans = 0;
            while (k != 1LL) {
                ++ans;
                k /= 2;
            }
            cout << "Case #" << t << ": " << (40-ans) << endl;
        }
    }

    return 0;
}
