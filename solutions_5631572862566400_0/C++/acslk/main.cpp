#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <bits/stl_set.h>

using namespace std;
int T, N;

vector<int> to;
vector<vector<int>> from;
vector<bool> visited;

int recurse(int fromV) {
    int ret = 0;
    visited[fromV] = true;
    for (int f : from[fromV]) {
        if (!visited[f]) {
            int r = recurse(f);
            if (r > ret)
                ret = r;
        }
    }
    return ret + 1;
}

int calc (int start) {
    visited = vector<bool>(N+1, false);
    int cur = start, next, prev = -1;
    visited[cur] = true;
    int size = 1;
    while (true) {
        next = to[cur];
        if (next == start)
            return size;
        else if (next == prev) {
            int ret = recurse(cur) - 1 + size;
            for (int i = 1; i <= N; i++) {
                if (!visited[i] && !visited[to[i]]) {
                    if (find(from[i].begin(), from[i].end(), to[i]) != from[i].end()) {
                        visited[i] = true;
                        visited[to[i]] = true;
                        ret += recurse(i) + recurse(to[i]);
                    }
                }
            }
            return ret;
        } else if (visited[next])
            return -1;
        visited[next] = true;
        prev = cur;
        cur = next;
        size++;
    }
}

int main () {

    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> N;

        to.clear();
        from.clear();
        for (int i = 0; i <= N; i++) {
            vector<int> a;
            from.push_back(a);
        }

        to.push_back(0);
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            to.push_back(a);
            from[a].push_back(i);
        }

        int ret = 0;

        for (int start = 1; start <= N; start++) {
            int c = calc(start);
            if (c > ret)
                ret = c;
        }

        printf("Case #%d: %d\n", t+1, ret);
    }
}