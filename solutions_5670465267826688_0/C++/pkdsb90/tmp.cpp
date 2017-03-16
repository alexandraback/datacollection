#pragma  comment(linker, "/STACK:36777216")
#include <bits/stdc++.h>
#define  lc(x) (x << 1)
#define  rc(x) (lc(x) + 1)
#define  lowbit(x) (x & (-x))
#define  PI    (acos(-1))
#define  lowbit(x) (x & (-x))
#define  LL    long long
#define  DB    double
#define  ULL   unsigned long long
#define  PII   pair<int, int>
#define  PLL   pair<LL, LL>
#define  PB    push_back
#define  MP    make_pair

using namespace std;

const int N = 1e5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const DB  EPS = 1e-8;

int T, cas;
vector <int> vec;
LL n, len;

inline int Gao(int u, int v) {
    if (v < 0) u = -u, v = -v;
    int ret, op = 0;
    if (u < 0) op = true, u = -u;
    if (u == 1) ret = v;
    else if (v == 1) ret = u;
    else if (u == v) ret = -1;
    else if (u == 3 && v == 2) ret = -4;
    else if (u == 2 && v == 3) ret = 4;
    else if (u == 4 && v == 2) ret = 3;
    else if (u == 2 && v == 4) ret = -3;
    else if (u == 4 && v == 3) ret = -2;
    else if (u == 3 && v == 4) ret = 2;
    if (op) ret = -ret;
    return ret;
}

PII countPos() {
    int t = n > 4 ? 4 : n;
    int cur = 1, ret1 = -1, ret2 = -1;
    for (int i = 0; i < t * len; i ++) {
        cur = Gao(cur, vec[i % len]);
        if (cur == 2) {
            ret1 = i;
            break;
        }
    }
    cur = 1;
    for (int i = t * len - 1; i >= 0; i --) {
        cur = Gao(vec[i % len], cur);
        if (cur == 4) {
            ret2 = t * len - 1 - i;
            break;
        }
    }
    return MP(ret1, ret2);
}

bool Check() {
    int cur = 1;
    for (int i = 0; i < len; i ++)
        cur = Gao(cur, vec[i]);
    if (cur == 1) return false;
    if (cur == -1 && n % 2 == 0) return false;
    if (n % 4 != 2 && cur != -1) return false;
    PII t = countPos();
    int pos1 = t.first, pos2 = t.second;
//    cout << cur << ' ' << n << ' ' << pos1 << ' ' << pos2 << endl;
    if (pos1 == -1 || pos2 == -1) return false;
    if (pos1 + pos2 + 2 < len * n) return true;
    return false;
}

char ch[N];

int main(){
    freopen("C-small-attempt5.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> T;
    while (T --) {
        cin >> len >> n;
        vec.resize(len);
        scanf(" %s", ch);
        for (int i = 0; i < len; i ++)
            vec[i] = ch[i] - 'i' + 2;
        if (Check()) {
            printf("Case #%d: YES\n", ++ cas);
        } else {
            printf("Case #%d: NO\n", ++ cas);
        }
    }
}
