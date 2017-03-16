#include <bits/stdc++.h>

using namespace std;
using LINT = long long int;
using PII = pair<int,int>;

#define PB push_back
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i, a, b) for(int i=(a);i<(b);++i)

int n;
int graph[1007];
vector<int> rgraph[1007];

int ranks[1007];
bool closed[1007];

int dfs(int node) {
    int len = 0;

    // cout << 'f' << node << endl;

    closed[node] = true;

    for(int neigh : rgraph[node]) {
        if(closed[neigh]) continue;
        // cout << "ff" << neigh << endl;
        len = max(len, dfs(neigh) + 1);
    }

    // cout << 'x' << node << ' ' << len << endl;

    return len;
}

void process(int caseNum) {
    cin >> n;

    memset(ranks, 0, sizeof ranks);
    memset(closed, 0, sizeof closed);
    REP(i, 1007) rgraph[i].clear();

    REP(i, n) {
        int x;
        cin >> x;
        x--;

        graph[i] = x;
        rgraph[x].push_back(i);

        ranks[x]++;

    }

    queue<int> q;

    REP(i, n)
        if(ranks[i] == 0)
            q.push(i);


    while(q.size()) {

        int node = q.front();
        q.pop();

        closed[node] = true;

        ranks[graph[node]] --;
        if(ranks[graph[node]] == 0)
            q.push(graph[node]);
    }


    int maxpath = 0;

    REP(i, n)
        if(!closed[i]) {
            int cur = i;
            int cnt = 0;
            for(;;) {
                cnt++;
                cur = graph[cur];
                if(cur == i) break;
            }
            maxpath = max(maxpath, cnt);
        }
/*

    REP(i, n) {
        // cout << 'r' << i << ' ';
        for(int neigh : rgraph[i])
            cout << neigh << ' ';
        cout << endl;
    }
*/

    int clique = 0;

    REP(i, n) {
        if(graph[graph[i]] != i || i > graph[i]) // 2 clique
            continue;
        // cout << i << ' ' << graph[i] << ' ' << graph[graph[i]] << endl;

        // cout << 'z' << endl;

        memset(closed, 0, sizeof closed);
        closed[i] = true;

        int cnt = dfs(graph[i]) + 2;

        // cout << cnt << endl;

        memset(closed, 0, sizeof closed);
        closed[graph[i]] = true;
        cnt += dfs(i);
        // cout << cnt << endl;

        clique += cnt;


    }

    maxpath = max(maxpath, clique);


    cout << "Case #" << caseNum << ": " << maxpath << endl;

}

int main() {

    int t;
    cin >> t;
    REP(i, t) process(i+1);

    return 0;
}
