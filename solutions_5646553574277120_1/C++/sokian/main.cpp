#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define itn int
#define x first
#define y second

using namespace std;

template <typename T, typename U>
ostream & operator << (ostream &os, const pair<T, U> &r) {
    os << "(" << r.x << "," << r.y << ")";
    return os;
}
inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

typedef long long ll;


int V;
void solve(int test) {
    int c = nxt();
    int d = nxt();
    V = nxt();
    int a[d];
    for (int i = 0; i < d; ++i) {
        int x = nxt();
        a[i] = x;
    }
    int pos = 0;
    long long w = 0;
    int ans = 0;
    while (w < V) {
        if (pos == d) {
            ++ans;
            long long val = w + 1;
            val *= c;
            w = w + val;
        } else {
            if (a[pos] <= w + 1) {
                w += a[pos] * 1ll * c;
                pos++;
            } else {
                ++ans;
                long long val = w + 1;
                val *= c;
                w = w + val;
            }
        }
    }
    cout << "Case #" << test << ": ";
    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = nxt();
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
