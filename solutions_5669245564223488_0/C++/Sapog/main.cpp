#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int64, int64>;
using pdd = pair<double, double>;
using vi = vector<int64>;
using vpii = vector<pii>;
using vd = vector<double>;
using vvi = vector<vi>;

constexpr double eps = 1e-11;
const double pi = acos(-1.0);
constexpr int64 p = 1000000007;
constexpr int64 countbit(int64 n) { return n == 0 ? 0 : countbit(n / 2) + n % 2; }
constexpr int64 lowbit(int64 n) { return (n ^ (n-1) ) & n; }
constexpr int64 gcd(int64 a, int64 b) { return b == 0? a : gcd(b, a % b); }
constexpr int64 lcm(int64 a, int64 b) { return a * b / gcd(a, b); }
template<typename T> constexpr auto sqr(const T& n) -> decltype(n * n) { return n * n; }

#define all(a) (a).begin(), (a).end()
#define pb push_back

void solve() {
    int N;
    cin >> N;
    vector<string> ss(N);
    for (auto& s: ss) cin >> s;
    vi p(N);
    iota(all(p), 0);

    int result = 0;
    do {
        vector<char> seen(255);
        char last = '\0';
        bool valid = true;
        for (auto pos: p) {
            for (auto c: ss[pos]) {
                if (last != c && seen[c]) {
                    valid = false;
                    break;
                }
                seen[c] = true;
                last = c;
            }
            if (!valid) break;
        }
        if (valid) result++;
    } while (next_permutation(all(p)));
    cout << result << endl;
}

int main() {
    int nTests;
    cin >> nTests;

    for(unsigned int testNumber = 0; testNumber < nTests; ++testNumber) {
        printf("Case #%d: ", testNumber + 1);
        solve();
    }
    return 0;
}
