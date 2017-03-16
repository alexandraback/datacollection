// program a
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx = 1e6 + 5;

int t;
ll n;
bool vis[mx];

struct node {
    ll v;
    int s;
    node() {}
    node(ll _v, int _s) : v(_v), s(_s) {}
};

ll reverse(ll a) {
    vector<ll> v;
    while(a) {
        v.push_back(a % 10);
        a /= 10;
    }
    ll res = 0, p = 1;

    for(int i = v.size() - 1; i >= 0; i --) {
        res += v[i] * p;
        p *= 10;
    }
    return res;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> t;
    for(int cas = 1; cas <= t; cas ++) {
        cin >> n;
        int res = 1;
        queue<node> que;
        memset(vis, 0, sizeof(vis));
        while(!que.empty()) que.pop();
        que.push(node(1, 1));
        vis[1] = 1;
        while(!que.empty()) {
            node cur = que.front();
            vis[cur.v] = 1;
            que.pop();
            if(cur.v == n) {
                res = cur.s;
                break;
            }
            int nn = reverse(cur.v);
            if(!vis[cur.v + 1])
                que.push(node(cur.v + 1, cur.s + 1));
            if(!vis[nn])
            que.push(node(nn, cur.s + 1));
        }
        cout << "Case #" << cas << ": " << res << endl;
    }
    return 0;
}
