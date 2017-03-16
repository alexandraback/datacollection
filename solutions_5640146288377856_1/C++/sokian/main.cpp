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


int solve(int m, int w) {
    return m / w;
}

void solve(int test) {
    int n = nxt();
    int m = nxt();
    int w = nxt();
    cout << "Case #" << test << ": ";
    cout << n * solve(m, w) + w - 1 + (m % w > 0) << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t = nxt();
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
