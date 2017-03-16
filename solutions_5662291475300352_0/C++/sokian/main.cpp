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

vector<vector<int> > cost;
vector<vector<int> > used;


struct cmp {
    bool operator () (const PII &l, const PII &r) {
        if (cost[l.x][l.y] != cost[r.x][r.y]) {
            return cost[l.x][l.y] > cost[r.x][r.y];
        }
        return l < r;
    }
};

PII dd[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const ll P = 360;

int calc(ll p1, ll t1, ll p2, ll t2) {
    if (t1 == t2) return 0;
    if (p1 > p2) {
        swap(p1, p2);
        swap(t1, t2);
    }
    if (t1 < t2) {
        if ((P - p2) * t2 >= (P + P - p1) * t1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if ((P - p1) * t1 >= (P + P - p2) * t2) {
            return 1;
        } else {
            return 0;
        }
    }
}

void solve(int test) {
    int n = nxt();
    vector<PII> a;
    for (int i = 0; i < n; ++i) {
        int d = nxt();
        int h = nxt();
        int m = nxt();
        for (int j = 0; j < h; ++j) {
            a.push_back(mp(d, m + j));
        }
    }
    cout << "Case #" << test << ": ";
    if (a.size() == 1) {
        cout << "0\n";
        return;
    }
    if (a.size() == 2) {
        cout << calc(a[0].x, a[0].y, a[1].x, a[1].y) << "\n";
        return;
    }
    cout << "\n";
    //assert(false);
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    srand(56435);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = nxt();
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }


    return 0;
}
