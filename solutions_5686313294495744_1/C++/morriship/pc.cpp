#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;


map<string, int> fmap, smap;

vector<int> edge[3011];
int can[2011][2011], used[2011], pre[2011];
vector<string> tmpf, tmps;


string in1, in2;
int f, s;

void addedge(int src, int dst) {
    edge[src].push_back(dst);
    edge[dst].push_back(src);
    can[src][dst] = 1;
}

int BFS(int src, int dst) {
    int i, j, k, x, y;
    queue<int> que;
    que.push(0);
    used[0] = 1;
    while (!que.empty()) {
        x = que.front();
        if (x == dst) { break; }
        que.pop();
        rep(i, edge[x].size()) {
            y = edge[x][i];
            if (!used[y] && can[x][y]) {
                used[y] = 1;
                que.push(y);
                pre[y] = x;
            }
        }
    }
    if (que.empty()) { return 0; }
    else {
        for (y = dst; y; y = pre[y]) {
            int x = pre[y];
            can[x][y] = 0;
            can[y][x] = 1;
        }
        return 1;
    }
}

int solve(int src, int dst) {
    int ans(0);
    while (BFS(src, dst)) {
        ans++;
        memset(pre, 0, sizeof(pre));
        memset(used, 0, sizeof(used));
    }
    return ans;
}

int main() {
    int t, tt, i, j, k, n;
    cin >> tt;
    xrep(t, 1, tt+1) {
        rep(i, 3011) edge[i].clear();
        memset(pre, 0, sizeof(pre));
        memset(used, 0, sizeof(used));
        fmap.clear();
        smap.clear();
        tmpf.clear();
        tmps.clear();
        memset(can, 0, sizeof(can));
        f = s = 0;
        
        cin >> n;

        rep(i, n) {
            cin >> in1 >> in2;
            if (!fmap[in1]) { fmap[in1] = ++f; }
            if (!smap[in2]) { smap[in2] = ++s; }
            tmpf.push_back(in1);
            tmps.push_back(in2);
        }
        rep(i, n) {
            in1 = tmpf[i];
            in2 = tmps[i];
            addedge(fmap[in1], smap[in2]+f);
        }
        xrep(i, 1, f+1) { addedge(0, i); }
        xrep(i, f+1, f+s+1) { addedge(i, f+s+1); }
        // cout << solve(0, f+s+1) << endl;
        cout << "Case #" << t << ": " << n - (f + s - solve(0, f+s+1)) << endl;
    }
}
