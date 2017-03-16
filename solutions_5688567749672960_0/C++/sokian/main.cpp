#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
#define in(n) int (n) = nxt()

using namespace std;

typedef long long ll;

inline int nxt() {
    int a;
    scanf("%d", &a);
    return a;
}

inline int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef pair<int, int> PII;

PII operator + (const PII &l, const PII &r) {
    return mp(l.x + r.x, l.y + r.y);
}
PII operator - (const PII &l, const PII &r) {
    return mp(l.x - r.x, l.y - r.y);
}

PII operator * (const PII &l, const int &r) {
    return mp(l.x * r, l.y * r);
}


int reverse(int a) {
    int d[10];
    int sz;
    for (sz = 0; a > 0;) {
        d[sz++] = a % 10;
        a /= 10;
    }
    int ret = 0;
    for (int i = 0; i < sz; ++i) {
        ret = ret * 10 + d[i];
    }
    return ret;
}

long long moves(long long a) {
    if (a <= 20) {
        return a;
    }
    if (a <= 30) {
        return a - 8;
    }
    if (a <= 40) {
        return a - 17;
    }
    if (a <= 50) {
        return a - 26;
    }
}

const int N = 5000001;
char u[N];
int d[N];

inline void solve() {
    memset(u, 0, sizeof(u));
    u[1] = 1;
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v + 1 < N && !u[v + 1]) {
            u[v + 1] = 1;
            d[v + 1] = d[v] + 1;
            q.push(v + 1);
        }
        int to = reverse(v);
        if (to < N && !u[to]) {
            u[to] = 1;
            d[to] = d[v] + 1;
            q.push(to);
        }
    }
    int t = nxt();
    for (int i = 1; i <= t; ++i) {
        int x = nxt();
        cout << "Case #" << i << ": " << d[x] << "\n";
    }
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    srand(56435);
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    solve();


    return 0;
}
