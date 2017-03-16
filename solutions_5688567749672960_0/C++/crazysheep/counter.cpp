#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

bool seen[1000005];

int bfs(int n) {
    for (int i = 0; i < 1000005; ++i) {
        seen[i] = false;
    }
    queue<pair<int, int> > q;
    q.push(pair<int, int>(1, 1));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (seen[cur.first]) {
            continue;
        }
        seen[cur.first] = true;

        if (cur.first == n) {
            return cur.second;
        }

        q.push(pair<int, int>(cur.first + 1, cur.second + 1));

        char buffer[10];
        sprintf(buffer, "%d", cur.first);
        reverse(buffer, buffer + strlen(buffer));

        int flipped;
        sscanf(buffer, "%d", &flipped);
        
        q.push(pair<int, int>(flipped, cur.second + 1));
    }

    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);

        printf("Case #%d: %d\n", t, bfs(n));
    }
}