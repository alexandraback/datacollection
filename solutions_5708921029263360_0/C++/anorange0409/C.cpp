#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[4][4][4];
int cnt[4][4][4];
struct node {
    int c[3];
    node (){}
    node(int x,int y,int z) {
        c[0]=x;
        c[1]=y;
        c[2]=z;
    }
};

vector<node> all;
vector<node> L;
vector<node> ans;
int A[3], N, M, K;

void dfs(int dep, int start) {
    if (dep > ans.size()) {
        ans = L;
        ans.resize(dep);
    }
    for (int k = start; k < all.size(); k++) {
        int x = all[k].c[0];
        int y = all[k].c[1];
        int z = all[k].c[2];
        if (!vis[x][y][z] && cnt[x][y][0] < K &&
            cnt[x][0][z] < K && cnt[0][y][z] < K) {
                vis[x][y][z]=1;
                cnt[x][y][0]++;
                cnt[x][0][z]++;
                cnt[0][y][z]++;
                L[dep] = node(x,y,z);
                dfs(dep+1, k + 1);
                vis[x][y][z]=0;
                cnt[x][y][0]--;
                cnt[x][0][z]--;
                cnt[0][y][z]--;
        }
    }
}

int main() {
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++) {
        printf("Case #%d: ", o);
        cin >> A[0] >> A[1] >> A[2] >> K;
        memset(vis, 0, sizeof vis);
        memset(cnt, 0, sizeof cnt);
        all.clear();
        for (int x=1;x<=A[0];x++)
        for (int y=1;y<=A[1];y++)
        for (int z=1;z<=A[2];z++)
            all.push_back(node(x,y,z));
        if (K >= A[0]&&K>=A[1]&&K>=A[2]) {
            ans = all;
        } else {
            L.resize(30); ans.clear();
            dfs(0,0);
        }
        cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].c[0] << " ";
                cout << ans[i].c[1] << " ";
                cout << ans[i].c[2] << endl;
            }
    }
}
