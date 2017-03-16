#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxl = 23, maxn = 1005;

struct flow {
    int n;
    std::vector<std::vector<int>> cap;
    std::vector<bool> seen;
    flow(int n) : n(n) {
        cap.resize(n);
        for (auto &v : cap) v.resize(n);
        seen.resize(n);
    }
    void set(int a, int b, int c) {
        cap[a][b] = c;
    }
    int push(int i, int d, int max) {
        seen[i] = true;
        if (i == d) return max;
        for (int j = 0; j < n; j++) if (!seen[j]) {
            if (cap[i][j]) {
                int p = push(j, d, std::min(max, cap[i][j]));
                if (p) {
                    cap[i][j] -= p;
                    cap[j][i] += p;
                    return p;
                }
            }
        }
        return 0;
    }
    int max(int s, int d) {
        int mf = 0;
        while (true) {
            std::fill(all(seen), false);
            int p = push(s, d, 1e9);
            if (!p) break;
            mf += p;
        }
        return mf;
    }
};

int n, aid, bid, x[maxn], y[maxn];
char s[maxl], t[maxl];
std::map<std::string, int> a, b;

void clear() {
    aid = bid = 0;
    a.clear(); b.clear();
}
int f(std::map<std::string, int> &m, int &id, std::string &s) {
    if (m.find(s) == m.end()) m[s] = id++;
    return m[s];
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %s %s", s, t);
            std::string ss = s, tt = t;
            x[i] = f(a, aid, ss); y[i] = f(b, bid, tt);
        }
        flow f(1+aid+bid+1);
        for (int i = 0; i < n; i++) f.set(x[i]+1, y[i]+1+aid, 1);
        for (int i = 0; i < aid; i++) f.set(0, i+1, 1);
        for (int i = 0; i < bid; i++) f.set(i+1+aid, 1+aid+bid, 1);
        int mf = f.max(0, 1+aid+bid);
        //printf("mf = %d\n", mf);
        int ans = n - (mf + aid-mf + bid-mf);
        printf("Case #%d: %d\n", testnum, ans);
        clear();
    }
}

