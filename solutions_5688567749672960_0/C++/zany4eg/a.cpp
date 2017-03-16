#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;
const int MAXN = (int)1e6 + 1;

int d[MAXN], q[MAXN];

vector<int> g[MAXN];



inline int rev(int x) {
    string str = "";
    int val = x;
    while (x) {
        str += x % 10 + '0';
        x /= 10;
    }
    int it = 0;
    while (true) {
        if (str[it] == '0') it++;
        else break;
    }
    str = str.substr(it, str.size() - it);
    return atoi(str.c_str());
}
void init() {
    for (int i = 1; i < MAXN; i++) {
        g[i].push_back(i + 1);
        g[i].push_back(rev(i));
    }
    int start = 1;
    fill(d, d + MAXN, -1);
    d[start] = 1;
    int head = 0, tail = 0;
    q[tail++] = start;
    while (head < tail) {
        int v = q[head++];
        for (int to: g[v])
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                q[tail++] = to;
            }
    }

}
int main() {
//    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    int T;
    scanf("%d", &T);
    for (int tc = 1, q; tc <= T; tc++) {
        scanf("%d", &q);
        printf("Case #%d: %d\n", tc, d[q]);
    }

    return 0;
}
