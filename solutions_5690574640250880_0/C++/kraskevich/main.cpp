#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int dx[] = { 1, 1, 1,  -1, -1, -1,   0, 0};
const int dy[] = {-1, 0, 1,  -1,  0,  1,  -1, 1};

int n, m;
int tot = 0;

int getId(int i, int j) {
    return i * m + j;
}

bool valid(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

struct Dsu
{
    vector<int> p;

    Dsu(int n) {
        p.assign(n, 0);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int v) {
        return p[v] == v ? v : p[v] = get(p[v]);
    }

    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b)
            p[a] = b;
    }
};

void solve(int test)
{
    cout << "Case #" << test << ":\n";
    int cnt;
    cin >> n >> m >> cnt;
    int sz = n * m;
    for (int mask = 0; mask < (1 << sz); mask++) {
        int b = __builtin_popcount(mask);
        if (b != sz - cnt)
            continue;
        vector<int> deg(sz, 0);
        Dsu tree(sz);
        for (int bit = 0; bit < sz; bit++) {
            if (!(mask & (1 << bit)))
                continue;
            int x = bit / m;
            int y = bit % m;
            for (int rep = 0; rep < 8; rep++) {
                int nx = x + dx[rep];
                int ny = y + dy[rep];
                if (valid(nx, ny) && (!(mask & (1 << getId(nx, ny)))))
                    deg[bit]++;
            }
        }
        int v = -1;
        vector<bool> good(sz, false);
        for (int bit = 0; bit < sz; bit++) {
            if (!(mask & (1 << bit)))
                continue;
            int x = bit / m;
            int y = bit % m;
            if (v == -1 || deg[bit] < deg[v])
                v = bit;
            if (deg[bit] == 0)
                good[bit] = true;
            for (int rep = 0; rep < 8; rep++) {
                int nx = x + dx[rep];
                int ny = y + dy[rep];
                if (valid(nx, ny) && (mask & (1 << getId(nx, ny)))) {
                    if (deg[bit] == 0)
                        good[getId(nx, ny)] = true;
                    if (deg[bit] == 0 && deg[getId(nx, ny)] == 0)
                        tree.unite(getId(nx, ny), bit);
                }
            }
        }
        assert(v >= 0);
        bool ok = true;
        for (int bit = 0; bit < sz; bit++)
            if ((mask & (1 << bit))) {
                if (deg[bit] == 0 && tree.get(bit) != tree.get(v))
                    ok = false;
                if (!good[bit])
                    ok = false;
            }
        if (!ok && b > 1)
            continue;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int id = getId(i, j);
                if (mask & (1 << id))
                    s[i] += '.';
                else
                    s[i] += '*';
                if (id == v)
                    s[i].back() = 'c';
            }
        for (string cur : s)
            cout << cur << "\n";
        return;
    }
    tot++;
    //cerr << n << " " << m << " " << cnt << endl;
    cout << "Impossible\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout.setf(ios::fixed);
    cout.precision(7);

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    cerr << tot << endl;

    return 0;
}
