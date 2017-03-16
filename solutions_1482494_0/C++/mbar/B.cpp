#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

struct node {
    int lvl;
    int req;
};

bool operator<(const node& a, const node& b) {
    return a.req < b.req;
}

ostream& operator<<(ostream& os, const node& n) {
    os << "[lvl="<< n.lvl << ", req=" << n.req << "]";
    return os;
}

int main() {
    int T;
    cin >> T;
    for (int cs=1; cs<=T; ++cs) {
        int N;
        cin >> N;
        vector<node> one(N), two(N);
        int vis[N][2];
        memset(vis, 0, sizeof(vis));
        for (int i=0; i<N; ++i) {
            cin >> one[i].req >> two[i].req;
            one[i].lvl = two[i].lvl = i;
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int cnt = 0;
        int res = 0;
        int oi = 0, ti = 0;
        while (ti<N) {
            if (two[ti].req <= cnt) {
                const node& n = two[ti++];
                ++res;
                cnt += 2;
                if (vis[n.lvl][0]) --cnt;
                vis[n.lvl][0] = vis[n.lvl][1] = 1;
            } else if (oi<N && one[oi].req <= cnt) {
                const node& n = one[oi++];
                if (vis[n.lvl][0]) continue;
                vis[n.lvl][0] = 1;
                ++res;
                ++cnt;
            } else {
                cout << "Case #" << cs << ": Too Bad\n";
                goto done;
            }
        }
        cout << "Case #" << cs << ": " << res << "\n";
      done:
        ;
    }
}
