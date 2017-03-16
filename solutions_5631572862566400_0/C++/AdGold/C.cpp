#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;


int nxt[2000], seen[2000];
int N, T;
vector<int> children[2000];


int maxLoop(int at, int depth)
{
    if (seen[at])
        return depth - seen[at];
    seen[at] = depth;
    return maxLoop(nxt[at], depth+1);
}

int depth(int at)
{
    // printf("depth at %d\n", at);
    int m = 0;
    for (int i = 0; i < (int)children[at].size(); i++) {
        // if (children[at][i] == nxt[at])
            // continue;
        m = max(m, depth(children[at][i]));
    }
    // printf("Final depth at %d is %d\n", at, m+1);
    return m + 1;
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", nxt + i);
        for (int i = 1; i < 2000; i++) {
            children[i].clear();
        }
        int best = 0;
        for (int i = 1; i <= N; i++) {
            memset(seen, 0, sizeof(seen));
            int loop = maxLoop(i, 1);
            // printf("loop from %d, best %d\n", i, loop);
            if (loop > best)
                best = loop;
        }
        for (int i = 1; i <= N; i++) {
            if (nxt[nxt[i]] != i) {
                // printf("%d is a child of %d\n", i, nxt[i]);
                children[nxt[i]].push_back(i);
            }
        }
        // for (int i = 1; i <= N; i++) {
            // printf("%d: ", i);
            // for (int j = 0; j < (int)children[i].size(); j++) {
                // printf("%d, ", children[i][j]);
            // }
            // printf("\n");
        // }
        int twoCycles = 0;
        for (int i = 1; i <= N; i++) {
            if (nxt[nxt[i]] == i) {
                // printf("%d in 2-cycle\n", i);
                twoCycles += depth(i);
                // printf("added %d\n", depth(i));
            }
        }
        // printf("%d, %d\n", best, twoCycles);
        best = max(best, twoCycles);
        printf("Case #%d: %d\n", t, best);
    }
}
