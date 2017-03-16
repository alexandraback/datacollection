#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<cassert>
using namespace std;
int N;
vector<int> E[1001];
vector<int> R[1001];
int inEdgeCnt[1001];
bool visited[1001];
int paths[1001][1001];
bool solve() {
    queue<int> Q;
    for (int i=1; i<=N; i++)
        if (inEdgeCnt[i] == 0) Q.push(i);
    while(!Q.empty()) {
        int x = Q.front();
        // cout << x << endl;
        Q.pop();
        assert(paths[x][x] == 0);
        paths[x][x] = 1;

        for (int j=0; j<E[x].size(); j++) {
            int nxt = E[x][j];
            inEdgeCnt[nxt]--;
            if (inEdgeCnt[nxt] == 0) Q.push(nxt);

            for (int k=1; k<=N; k++)
            paths[nxt][k] += paths[x][k];
        }
    }
    for (int i=1; i<=N; i++) for(int k=1;k<=N;k++) if(paths[i][k] > 1) return true;
    return false;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++) {
        cin >> N;
        for (int i=1;i<=N;i++) {
            inEdgeCnt[i] = 0;
            E[i].clear();
            R[i].clear();
            for(int j=1;j<=N;j++) paths[i][j] = 0;
        }
        for (int i=1; i<=N; i++) {
            int Mi;
            cin >> Mi;
            for (int j = 0; j < Mi; j++) {
                int x;
                cin >> x;
                inEdgeCnt[x]++;
                E[i].push_back(x);
                R[x].push_back(i);
            }
        }

        if (solve()) printf("Case #%d: Yes\n", kase);
        else printf("Case #%d: No\n", kase);
    }
    return 0;
}
