#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 21;
int a[N][N];

void clear() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = 0;
        }
    }
}

inline bool isConnected(int x, int m, int n) {
    if (x == m * n) {
        return true;
    }
    int i, j;
    bool flag = false;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            flag = a[i][j] == 0;
            if (flag) {
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    vector<pair<int, int>> v = {make_pair(i, j)};
    a[i][j] = 1;
    int t = 1;
    while (!v.empty()) {
        auto p = v.back();
        v.pop_back();
        if (p.first != 0 && !a[p.first - 1][p.second]) {
            a[p.first - 1][p.second] = 1;
            v.push_back(make_pair(p.first - 1, p.second));
            ++t;
        }
        if (p.first != m - 1 && !a[p.first + 1][p.second]) {
            a[p.first + 1][p.second] = 1;
            v.push_back(make_pair(p.first + 1, p.second));
            ++t;
        }
        if (p.second != 0 && !a[p.first][p.second - 1]) {
            a[p.first][p.second - 1] = 1;
            v.push_back(make_pair(p.first, p.second - 1));
            ++t;
        }
        if (p.second != n - 1 && !a[p.first][p.second + 1]) {
            a[p.first][p.second + 1] = 1;
            v.push_back(make_pair(p.first, p.second + 1));
            ++t;
        }
    }
    return t == m * n - x;
}

inline void gen(int x, int m, int n) {
    clear();
    auto p = make_pair(rand() % m, rand() % n);
    a[p.first][p.second] = 1;
    vector<pair<int, int>> v;
    if (p.first != 0) {
        v.push_back(make_pair(p.first - 1, p.second));
    }
    if (p.first != m - 1) {
        v.push_back(make_pair(p.first + 1, p.second));
    }
    if (p.second != 0) {
        v.push_back(make_pair(p.first, p.second - 1));
    }
    if (p.second != n - 1) {
        v.push_back(make_pair(p.first, p.second + 1));
    }
    for (int i = 1; i < x; ++i) {
        int t = rand() % ((int) v.size());
        swap(v[t], v.back());
        p = v.back();
        v.pop_back();
        a[p.first][p.second] = 1;
        if (p.first != 0 && a[p.first - 1][p.second] != 1) {
            v.push_back(make_pair(p.first - 1, p.second));
        }
        if (p.first != m - 1 && a[p.first + 1][p.second] != 1) {
            v.push_back(make_pair(p.first + 1, p.second));
        }
        if (p.second != 0 && a[p.first][p.second - 1] != 1) {
            v.push_back(make_pair(p.first, p.second - 1));
        }
        if (p.second != n - 1 && a[p.first][p.second + 1] != 1) {
            v.push_back(make_pair(p.first, p.second + 1));
        }
    }
}

vector<pair<int,int>> getV(int m, int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        v[i].first -= v[0].first;
        v[i].second -= v[0].second;
    }
    v[0] = make_pair(0, 0);
    return v;
}

vector<pair<int,int>> getH(int m, int n) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) {
                v.push_back(make_pair(j, i));
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        v[i].first -= v[0].first;
        v[i].second -= v[0].second;
    }
    v[0] = make_pair(0, 0);
    return v;
}

const int T = 10000;

void debugPrint(int m, int n, const char* str) {
    printf("%s\n", str);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", a[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool checkSize(int x, int m, int n) {
    gen(x, x, x);
    int lx = x, ly = x, hx = 0, hy = 0;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            if (a[i][j]) {
                lx = min(lx, i);
                hx = max(hx, i);
                ly = min(ly, j);
                hy = max(hy, j);
            }
        }
    }
    const bool v = (hx - lx + 1) <= m && (hy - ly + 1) <= n;
    const bool h = (hx - lx + 1) <= n && (hy - ly + 1) <= m;
    return v || h;
}

bool f(int x, int m, int n) {
    if ((m * n) % x != 0) {
//        debugPrint(0, 0, "modulus");
        return false;
    }
    for (int i = 0; i < T; ++i) {
        if (!checkSize(x, m, n)) {
//            debugPrint(x, x, "size");
            return false;
        }
    }
    map<vector<pair<int, int>>, bool> k;
    for (int i = 0; i < T; ++i) {
        gen(x, m, n);
        auto v = getV(m, n);
        auto h = getH(m, n);

        if (!k.count(v) && !k.count(h)) {
            k[v] = false;
            k[h] = false;
//            debugPrint(m, n, "connection");
        }
        bool flag = isConnected(x, m, n);
        k[v] = k[v] || flag;
        k[h] = k[h] || flag;
    }
    for (auto p : k) {
        if (!p.second) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;

    for (int u = 0; u < t; ++u) {
        int x, m, n;
        cin >> x >> m >> n;
        printf("Case #%d: %s\n", u + 1, f(x, m, n) ? "GABRIEL" : "RICHARD");
    }

//    for (int x = 1; x <= 4; ++x) {
//        for (int m = 1; m <= 4; ++m) {
//            for (int n = 1; n <= 4; ++n) {
//                printf("Case %d %d %d: %s\n", x, m, n, f(x, m, n) ? "GABRIEL" : "RICHARD");
//            }
//        }
//    }

    return 0;
}