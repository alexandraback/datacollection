#include <bits/stdc++.h>
const int MAXN = 2005;
using namespace std;
struct node {
    int v, next;
} edge[MAXN * 4];
int e, head[MAXN], mark[MAXN], cx[MAXN], cy[MAXN];
void add_edge(int x, int y) {
    edge[e].v = y;
    edge[e].next = head[x];
    head[x] = e++;
    edge[e].v = x;
    edge[e].next = head[y];
    head[y] = e++;
}
int path(int u) {
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if(!mark[v]) {
            mark[v] = 1;
            if(cy[v] == -1 || path(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int solve(int n) {
    int ans = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for(int i = 1; i <= n; i++) {
        memset(mark, 0, sizeof(mark));
        ans += path(i);
    }
    return ans;
}
int cnt;
unordered_map<string, int> S1, S2;
set< pair<string, string> > ps;
string s1, s2, A[MAXN];
int insert(unordered_map<string, int>& s, string x) {
    if(s.find(x) == s.end()) {
        s[x] = ++ cnt;
        A[cnt] = x;
    }
    return s[x];
}
int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int T; cin>>T;
    for(int cs = 1; cs <= T; cs ++) {
        cerr << "Processing Case #" <<cs <<endl;
        int n; cin >> n;
        e = 0;
        cnt = 0;
        S1.clear(); S2.clear();
        ps.clear();
        memset(head, -1, sizeof(head));
        for(int i = 0; i < n; i ++) {
            cin >> s1 >> s2;
            add_edge(insert(S1, s1), insert(S2, s2));
            ps.insert(make_pair(s1, s2));
        }
        int ans = ps.size() - (cnt - solve(cnt) / 2);
        printf("Case #%d: %d\n", cs, ans);
    }
    return 0;
}
