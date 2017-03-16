#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 1005, inf = 1e9;

int n, f[maxn], ans, foo[maxn], dist[maxn], root[maxn], oeui[maxn];
bool seen[maxn], cycle[maxn], done[maxn],yay[maxn], fuck[maxn];
std::vector<int> c[maxn], cstarts;
std::vector<std::vector<int>> cycles;

void clear() {
    for (int i = 0; i < maxn; i++) { 
        done[i] = seen[i] = cycle[i] = fuck[i] = yay[i] = false;
        foo[i] = oeui[i] = 0;
        c[i].clear();
    }
    cycles.clear();
    cstarts.clear();
    ans = 0;
}
std::vector<int> gostack;
void go(int i) {
    gostack.pb(i);
    seen[i] = true;
    fuck[i] = true;
    if (cycle[f[i]]) {
        dist[i] = dist[f[i]] + 1;
        yay[i] = yay[f[i]];
        root[i] = root[f[i]];
    } else if (seen[f[i]]) {
        if (fuck[f[i]]) {
            cycles.push_back(std::vector<int>());
            int aoeu = 1;
            cycle[f[i]] = true;
            root[f[i]] = f[i];
            for (int j = sz(gostack)-1; gostack[j] != f[i]; j--) {
                cycle[gostack[j]] = true;
                root[gostack[j]] = gostack[j];
                aoeu++;
            }

            dist[f[i]] = aoeu;
            if (dist[f[i]] == 2) yay[f[i]] = true;
            for (int j = sz(gostack)-1; gostack[j] != f[i]; j--) {
                dist[gostack[j]] = aoeu;
            if (dist[f[i]] == 2) yay[gostack[j]] = true;
            }
        } else {
            dist[i] = dist[f[i]] + 1;
            yay[i] = yay[f[i]];
            root[i] = root[f[i]];
        }
    } else {
        go(f[i]);
        if (!cycle[i]) {
            dist[i] = dist[f[i]] + 1;
            root[i] = root[f[i]];
            yay[i] = yay[f[i]];
        }
    }
    fuck[i] = false;
    gostack.pop_back();
}

int main() {
    int testcases; scanf("%d", &testcases);
    for (int testnum = 1; testnum <= testcases; testnum++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) { scanf("%d", f+i); f[i]--; }
        for (int i = 0; i < n; i++) if (!seen[i]) go(i);
        for (int i = 0; i < n; i++) if(cycle[i]) domax(ans, dist[i]);
        for (int i = 0; i < n; i++) domax(oeui[root[i]], dist[i]);
        for (int i = 0; i < n; i++) if (f[f[i]] == i) {
            domax(ans, oeui[i] + oeui[f[i]] - 2);
        }
        printf("Case #%d: ", testnum);
        printf("%d\n", ans);
        clear();
    }
}

