// A

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

struct bfse {
    bfse(ll num, ll d) : num(num), d(d) {}
    ll num;
    ll d;
};

ll rev(ll n) {
    vector<int> digs;
    while(n % 10 == 0) {
        n /= 10;
    }
    while(n > 0) {
        digs.push_back(n % 10);
        n /= 10;
    }
    ll p = 1;
    ll ret = 0;
    for(int i = digs.size()-1; i >= 0; --i) {
        ret += digs[i] * p;
        p *= 10;
    }
    return ret;
}

ll bfs(ll n) {
    if(n == 1) return 1;

    queue<bfse> bfsq;
    unordered_map<ll,bool> visit;
    bfsq.push(bfse(1, 1));
    visit[1] = true;

    while(!bfsq.empty()) {
        bfse f = bfsq.front(); bfsq.pop();
        ll next = f.num+1;
        if(!visit[next]) {
            ll nextd = f.d+1;
            if(next == n)
                return nextd;
            bfsq.push(bfse(next, nextd));
            visit[next] = true;
        }

        next = rev(f.num);
        if(!visit[next]) {
            ll nextd = f.d+1;
            if(next == n)
                return nextd;
            bfsq.push(bfse(next, nextd));
            visit[next] = true;
        }
    }
}

int main() {
    int t; cin >> t;
    for(int tcase = 1; tcase <= t; ++tcase) {
        ll n; cin >> n;
        printf("Case #%i: %lli\n", tcase, bfs(n));
    }
    return 0;
}
