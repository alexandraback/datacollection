#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

#define ll long long
#define h  10000001LL


ll rev(ll x) {
    ll y = 0;
    while (x) {
        y *= 10;
        y += x%10;
        x /= 10;
    }
    return y;
}

ll* vis;
int main() {
    int T;
    cin>>T;
    vis = new ll[h];

    for (int t=1;t<=T;++t) {
        ll N;
        cin>>N;

        memset(vis,-1,h * sizeof(ll));

        ll x = 1;
        vis[x] = 1;
        deque<ll> q;
        q.push_back(x);
        ll ans = -1;
        while (!q.empty()) {
            ll v = q.front();
            q.pop_front();
            if (v == N) {
                ans = vis[v];
                break;
            }

            ll next1 = v+1;
            if (vis[next1] == -1) {
                vis[next1] = vis[v] + 1;
                q.push_back(next1);
            }
            ll next2 = rev(v);
            if (vis[next2] == -1) {
                vis[next2] = vis[v] + 1;
                q.push_back(next2);
            }
        }

        printf("Case #%d: %lld\n", t, ans);
    }
}
