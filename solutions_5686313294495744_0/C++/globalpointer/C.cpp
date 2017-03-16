#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxl = 23, maxn = 1005;

int n, id = 1, ans = 1e9, x[maxn], y[maxn];
bool done[2][maxn + maxn];
char s[maxl], t[maxl];
std::map<std::string, int> map;

void clear() {
    id = 1;
    map.clear();
    ans = 1e9;
}
int f(std::string &s) {
    if (!map[s]) map[s] = id++;
    return map[s];
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %s %s", s, t);
            std::string ss = s, tt = t;
            x[i] = f(ss); y[i] = f(tt);
        }
        for (int i = 0; i < (1<<n); i++) {
            int c = 0;
            for (int j = 0; j < n; j++) if (i & (1<<j)) c++;
            bool works = true;
            std::fill(done[0], done[0]+id+3, false);
            std::fill(done[1], done[1]+id+3, false);
            for (int j = 0; j < n; j++) if (i & (1<<j)) {
                done[0][x[j]] = done[1][y[j]] = true;
            }
            for (int j = 0; j < n; j++) if (!(i & (1<<j))) {
                if (!done[0][x[j]] || !done[1][y[j]]) {
                    works = false;
                    break;
                }
            }
            if (works) domin(ans, c);
        }
        printf("Case #%d: %d\n", testnum, n-ans);
        clear();
    }
}

