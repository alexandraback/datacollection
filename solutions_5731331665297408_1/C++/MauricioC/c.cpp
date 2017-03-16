#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

vector<int> edges[51];
int adj[51][51];

int main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int N, M;

        cin >> N >> M;
        memset(adj, 0, sizeof adj);

        vector<pair<string, int> > zips;
        for (int i = 0; i < N; i++) {
            edges[i].clear();

            string temp;
            cin >> temp;
            zips.push_back(make_pair(temp, i));
        }

        sort(zips.begin(), zips.end());

        int inv_perm[N];
        for (int i = 0; i < N; i++)
            inv_perm[zips[i].second] = i;

        for (int i = 0; i < M; i++) {
            int v, w;
            scanf("%d %d", &v, &w);

            edges[inv_perm[v-1]].push_back(inv_perm[w-1]);
            edges[inv_perm[w-1]].push_back(inv_perm[v-1]);
            adj[inv_perm[v-1]][inv_perm[w-1]] = true;
            adj[inv_perm[w-1]][inv_perm[v-1]] = true;
        }

        vector<int> active;
        vector<int> ans;
        vector<bool> seen(N, false);

        active.push_back(0);
        ans.push_back(0);
        seen[0] = true;

        for (int cur = 2; cur <= N; cur++) {
            for (int j = 0; j < N; j++) {
                if (seen[j])
                    continue;

                vector<int> active2 = active;
                vector<bool> visited = seen;

                while (!active2.empty()) {
                    if (adj[j][active2.back()])
                        break;
                    active2.pop_back();
                }

                if (active2.empty()) {
                    fprintf(stderr, "%d is not a neighbor of the stack\n", j);
                    continue;
                }

                queue<int> q;
                q.push(j);
                visited[j] = true;

                for (int i = 0; i < active2.size(); i++) {
                    assert(seen[active2[i]]);
                    visited[active2[i]] = false;
                }

                while(!q.empty()) {
                    int v = q.front();
                    q.pop();

                    for (int i = 0; i < edges[v].size(); i++) {
                        int w = edges[v][i];
                        if (!visited[w]) {
                            q.push(w);
                            visited[w] = true;
                        }
                    }
                }

                bool ok = true;
                for (int i = 0; i < N; i++) {
                    ok &= visited[i] | seen[i];
                    if (!ok)
                        fprintf(stderr, "%d %d: Couldn't reach %d\n", cur, j, i);
                }

                if (ok) {
                    active = active2;
                    active.push_back(j);
                    fprintf(stderr, "* Adding %d to the stack\n", j);
                    ans.push_back(j);
                    seen[j] = true;
                    break;
                }
            }

            assert(cur == ans.size());
        }

        printf("Case #%d: ", z);
        for (int i = 0; i < N; i++)
            cout << zips[ans[i]].first;
        cout << endl;
    }
}
