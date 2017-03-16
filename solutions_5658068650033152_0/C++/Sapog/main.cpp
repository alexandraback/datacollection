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
    int N, M, K;
    cin >> N >> M >> K;
    for (int result = K / 2 + 1; result < K; ++result) {
        int bad = K - result;
        for (int h = 1; h <= N - 2 && h <= bad; ++h) {
            int w = (bad - 1) / h + 1;
            if (w > M - 2) continue;
            int p = 2*(h + w);
            if (h * w != bad) {
                p -= h * w - bad;
            }
            if (p <= result) {
                cout << result << endl;
                return;
            }
        }
    }
    cout << K << endl;
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
