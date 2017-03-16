#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <string>
#include <time.h>

using namespace std;
const int N = 66;
vector<string> s;
string ans, current;
bool got = false;
int n, m;

vector<int> g[N];
bool used[N];
bool dead[N];
int matrix[N][N];

bool cool(int from) {
    queue<int> q;
    vector<char> got(n);

    q.push(from);
    got[from] = true;
    while (!q.empty()) {
        int x = q.front(); q.pop();

        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i];
            if (!dead[y] && !got[y]) {
                got[y] = true;
                q.push(y);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        if (!dead[i] && !got[i]) {
            return false;
        }
    return true;
}

int main() {
    int TESTS;
    scanf("%d", &TESTS);

    for (int _t = 1; _t <= TESTS; ++_t) {
        printf("Case #%d: ", _t);
        memset(matrix, 0, sizeof(matrix));
        got = false;
        
        scanf("%d%d", &n, &m);
        s.resize(n);

        int start = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            if (s[i] < s[start]) start = i;
        }
        for (int i = 0; i < n; ++i) g[i].clear();

        while (m--) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            matrix[x][y] = matrix[y][x] = 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        memset(used, 0, sizeof(used));
        memset(dead, 0, sizeof(dead));
        ans = s[start];

        used[start] = true;
        set< pair<string, int> > q;
        for (int i = 0; i < g[start].size(); ++i) {
            int x = g[start][i];
            q.insert(make_pair(s[x], x));
        }

        vector<int> st;
        st.push_back(start);
        for (int iter = 1; iter < n; ++iter) {
            for (set< pair<string, int> >::iterator it = q.begin(); it != q.end(); ++it) {
                int who = it->second;
                if (dead[who] || used[who]) continue;

                int root = -1;
                for (int i = int(st.size()) - 1; i >= 0; --i)
                    if (matrix[ st[i] ][ who ]) {
                        root = st[i];
                        break;
                    }
                if (root == -1) continue;

                vector<int> path;
                while (st.back() != root) {
                    path.push_back(st.back());
                    st.pop_back();
                }

                for (int i = 0; i < path.size(); ++i) dead[ path[i] ] = true;
                if (!cool(root)) {
                    reverse(path.begin(), path.end());
                    for (int i = 0; i < path.size(); ++i) { 
                        dead[ path[i] ] = false;
                        st.push_back(path[i]);
                    }
                    continue;
                }
                
                used[who] = true;
                st.push_back(who);
                for (int i = 0; i < g[who].size(); ++i) q.insert(make_pair(s[ g[who][i] ], g[who][i]));
                ans += s[who];
                break;
            }
        }
        
        cout << ans << endl;
    }


    
    return 0;
}
