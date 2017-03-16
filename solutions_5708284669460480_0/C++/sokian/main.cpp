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

bool check(const string &s, const string &t) {
    for (char c : t) {
        if (!binary_search(s.begin(), s.end(), c)) {
            return false;
        }
    }
    return true;
}


string K, L;
int k, l, s;

struct vertex {
    int next[26];
    bool leaf;
    int p;
    int pch;
    int link;
    int go[26];
};

vertex t[300+1];
int sz;

void init() {
    sz = 0;
    t[0].p = t[0].link = -1;
    memset (t[sz].next, 255, sizeof(t[sz].next));
    memset (t[sz].go, 255, sizeof(t[sz].go));
    t[sz].leaf = false;
    sz = 1;
}

void add_string (const string & s) {
    int v = 0;
    for (size_t i=0; i<(int)s.length(); ++i) {
        int c = s[i]-'A';
        if (t[v].next[c] == -1) {
            memset (t[sz].next, 255, sizeof(t[sz].next));
            memset (t[sz].go, 255, sizeof(t[sz].go));
            t[sz].leaf = false;
            t[sz].link = -1;
            t[sz].p = v;
            t[sz].pch = c;
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go (int v, int c);

int get_link (int v) {
    if (t[v].link == -1)
    if (v == 0 || t[v].p == 0)
        t[v].link = 0;
    else
        t[v].link = go (get_link (t[v].p), t[v].pch);
    return t[v].link;
}

int go (int v, int c) {
    if (t[v].go[c] == -1)
    if (t[v].next[c] != -1)
        t[v].go[c] = t[v].next[c];
    else
        t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
    return t[v].go[c];
}

double dp[200][200];
double calc(int pos, int vert) {
    if (pos == s) {
        if (t[vert].leaf) {
            return 1.0;
        } else {
            return 0.0;
        }
    }
    double &res = dp[pos][vert];
    if (res > -0.5) {
        return res;
    }
    res = 0;
    if (t[vert].leaf) {
        res += 1;
    }
    for (char c : K) {
        res += 1.0 / k * (calc(pos + 1, go(vert, c - 'A')));
    }
    return res;
}


void solve(int test) {
    cout << "Case #" << test << ": ";
    cout << setprecision(10) << fixed;

    double ans = 0.0;

    k = nxt();
    l = nxt();
    s = nxt();

    cin >> K >> L;
    sort(K.begin(), K.end());

    if (!check(K, L)) {
        cout << ans << "\n";
        return;
    }

    int delta = l;
    for (int i = 1; i < l; ++i) {
        if (L.substr(i) == L.substr(0, l - i)) {
            delta = i;
            break;
        }
    }
    ans = 1 + (s - l) / delta;

    double ans2 = 0.0;
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            dp[i][j] = -1.0;
        }
    }
    init();
    add_string(L);
    ans2 = calc(0, 0);


    ans -= ans2;
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
