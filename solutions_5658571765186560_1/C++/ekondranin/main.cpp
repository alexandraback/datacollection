#include <bits/stdc++.h>
//#define endl "\n"
#define FOR(x, y, z) for (int x = (y); x < (z); ++x)
#define FORR(x, y, z) for (int x = (y); x > (z); --x)
#define GET(a, n) for (int i = 0; i < (n); ++i) cin >> a[i];
#define GETM(a, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
#define PRINTM(a, n, m) for (int i = 0; i < (n); ++i) { for (int j = 0; j < m; ++j) cout << a[i][j] << " ";  cout << endl; };
#define PRINT(a, n) for (int i = 0; i < (n); ++i) cout << a[i] << " ";
#define IT(a) a.begin(), a.end()
#define DEB(a) cout << #a << " = " << a << endl; cout.flush();
#define DEBA(a) for (auto i: a) cout << i << " "; cout << endl;
#define IFDEB(b, a) if (b) { cout << #a << " = " << a << endl; cout.flush(); }
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <vector <int>> VVI;
typedef pair <int, int> PII;
const int MOD = 1000000007;
template <class T> typename T::value_type arr_sum(const T& v, int n) { typename T::value_type sum = 0; FOR(i, 0, n) sum += v[i]; return sum; }
struct Sync_stdio { Sync_stdio() { cin.tie(NULL); ios_base::sync_with_stdio(false); } } _sync_stdio;

vector <vector <vector <vector <int>>>> v(7);
vector <vector <vector <vector <int>>>> v2(7);
vector <vector <vector <vector <int>>>> v3(7);

void gen(int t)
{
    if (t == 1) {
        vector <vector <int>> a(13, vector <int> (13));
        a[6][6] = 1;
        v[1].push_back(a);
        return;
    }
    gen(t - 1);
    FOR (i, 0, v[t - 1].size()) {
        FOR (k1, 1, 12) {
            FOR (k2, 1, 12) {
                 if (v[t - 1][i][k1][k2] == 1) {
                     continue;
                 }
                 if (v[t - 1][i][k1][k2 - 1] == 0 && v[t - 1][i][k1 - 1][k2] == 0 &&
v[t - 1][i][k1][k2 + 1] == 0 && v[t - 1][i][k1 + 1][k2] == 0) {
                     continue;
                 }
                 v[t - 1][i][k1][k2] = 1;
                 v[t].push_back(v[t - 1][i]);
                 v[t - 1][i][k1][k2] = 0;
            }
        }
    }
}

void cut(int t) {
    for (auto &i: v[t]) {
        int l = INT_MAX;
        int r = INT_MIN;
        int u = INT_MAX;
        int d = INT_MIN;
        FOR (j, 0, 13) {
            FOR (k, 0, 13) {
                if (i[j][k] == 0) {
                    continue;
                }
                l = min(l, k);
                r = max(r, k);
                u = min(u, j);
                d = max(d, j);
            }
        }
        vector <vector <int>> a(d - u + 1, vector <int> (r - l + 1));
        FOR (j, u, d + 1) {
            FOR (k, l, r + 1) {
                a[j - u][k - l] = i[j][k];
            }
        }
        v2[t].push_back(a);
    }
}

void del(int t)
{
    set <LL> s;
    for (const auto &i: v2[t]) {
        LL hash = 0;
        FOR (j, 0, i.size()) {
            FOR (k, 0, i[j].size()) {
                hash <<= 2;
                hash += i[j][k] + 1;
            }
            hash <<= 2;
            hash += 3;
        }
        if (s.find(hash) != s.end()) {
            continue;
        }
        s.insert(hash);
        v3[t].push_back(i);
    }
}

void dfs(vector <vector <int>> &a, int i, int j) {
    a[i][j] = 2;
    if (i - 1 >= 0 && a[i - 1][j] == 0) {
        dfs(a, i - 1, j);
    }
    if (j - 1 >= 0 && a[i][j - 1] == 0) {
        dfs(a, i, j - 1);
    }
    if (i + 1 < a.size() && a[i + 1][j] == 0) {
        dfs(a, i + 1, j);
    }
    if (j + 1 < a[0].size() && a[i][j + 1] == 0) {
        dfs(a, i, j + 1);
    }
}

void reflect(vector <vector <int>> &a)
{
    FOR (i, 0, a.size() / 2) {
        FOR (j, 0, a[0].size()) {
            swap(a[i][j], a[a.size() - 1 - i][j]);
        }
    }
}

void rot (vector <vector <int>> &a)
{
    vector <vector <int>> b(a[0].size(), vector <int> (a.size()));
    FOR (i, 0, a.size()) {
        FOR (j, 0, a[0].size()) {
            b[j][a.size() - 1 - i] = a[i][j];
        }
    }
    a = b;
}

int check(vector <vector <int>> &a, int r, int c)
{
    if ((a.size() > r || a[0].size() > c) && (a.size() > c || a[0].size() > r)) {
        return 1;
    }
    FOR (l1, 0, 2) {
        reflect(a);
        FOR (l2, 0, 4) {
            rot(a);
            FOR (i, 0, 2) {
                FOR (j, 0, 2) {
                    vector <vector <int>> b(r, vector <int> (c));
                    if (a.size() + i > r) {
                        continue;
                    }
                    if (a[0].size() + j > c) {
                        continue;
                    }
                    FOR (i1, 0, a.size()) {
                        FOR (j1, 0, a[0].size()) {
                            b[i + i1][j + j1] = a[i1][j1];
                        }
                    }
                    FOR (i1, 0, r) {
                        FOR (i2, 0, c) {
                            if (b[i1][i2] == 1) {
                                continue;
                            }
                            dfs(b, i1, i2);
                            goto NEXT;
                        }
                    }
NEXT:
                    int ok = 1;
                    FOR (i1, 0, r) {
                        FOR (i2, 0, c) {
                            if (b[i1][i2] == 0) {
                                ok = 0;
                            }
                        }
                    }
                    if (ok) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    gen(6);
    FOR (i, 1, 7) {
        cut(i);
        del(i);
    }
    FOR (l, 0, t) {
        int x, r, c;
        cin >> x >> r >> c;
        if (x >= 7 || (r * c) % x) {
            cout << "Case #" << l + 1 << ": RICHARD" << endl;
            continue;
        }
        int ok = 0;
        for (auto &i: v3[x]) {
            if (check(i, r, c)) {
                ok = 1;
                cout << "Case #" << l + 1 << ": RICHARD" << endl;
                break;
            }
        }
        if (!ok) {
            cout << "Case #" << l + 1 << ": GABRIEL" << endl;
        }
    }
}
