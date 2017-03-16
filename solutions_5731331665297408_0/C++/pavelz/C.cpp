#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <vector>

using namespace std;

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


#define MAX_N 60

vector<int> neighbor[MAX_N];
int n, m;
int zip[MAX_N];
int currentNode[MAX_N];

int sequence[MAX_N];
int visitedCount;
bool used[MAX_N];
bool visited[MAX_N];

void mark(int node) {
    if (visited[node] || used[node]) return;
    visited[node] = true;
    FOR(j, (int)neighbor[node].size()) mark(neighbor[node][j]);
}


bool checkReachable(int maxDepth) {
    FOR(i, n) visited[i] = false;
    FOR(i, maxDepth + 1) {
        int node = currentNode[i];
        FOR(j, (int)neighbor[node].size()) mark(neighbor[node][j]);
    }
    FOR(i, n) if (!visited[i] && !used[i]) return false;
    return true;
}

void find(int index, int depth) {
    used[index] = true;
    currentNode[depth] = index;
    sequence[visitedCount++] = index;

    while (true) {
        int minZip = 100000000;
        int minZipDepth = -1;
        for(int i=depth;i>=0;i--) {
        //FOR(i, depth + 1) {
            /*int localMinZip = 100000000;
            bool found = false;
            FOR(j, (int)neighbor[currentNode[i]].size()) {
                int nn = neighbor[currentNode[i]][j];
                if (!used[nn] && zip[nn] < localMinZip) {
                    localMinZip = zip[nn];
                    found = true;
                }
            }
            if (found && localMinZip < minZip) {
                if (checkReachable(i)) {
                    minZip = localMinZip;
                    minZipDepth = i;
                }
            }*/
            FOR(j, (int)neighbor[currentNode[i]].size()) {
                int nn = neighbor[currentNode[i]][j];
                if (!used[nn] && zip[nn] < minZip && checkReachable(i)) {
                    minZip = zip[nn];
                    minZipDepth = i;
                }
            }
        }
        if (minZipDepth == depth) {
            int localMinZip = 100000000;
            int minZipIndex = -1;
            FOR(j, (int)neighbor[index].size()) {
                int nn = neighbor[index][j];
                if (!used[nn] && zip[nn] < localMinZip) {
                    localMinZip = zip[nn];
                    minZipIndex = nn;
                }
            }
            if (minZipIndex == -1) {
                printf("Error\n");
                exit(0);
            }
            find(minZipIndex, depth + 1);
        } else
            return;
    }
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        scanf("%d%d", &n, &m);
        FOR(i, n) {
            neighbor[i].clear();
            used[i] = false;
        }

        FOR(i, n) scanf("%d", &zip[i]);
        FOR(i, m) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            neighbor[a].push_back(b);
            neighbor[b].push_back(a);
        }

        int minZip = 100000000;
        visitedCount = 0;
        int start = -1;
        FOR(i, n) if (zip[i] < minZip) {
            start = i;
            minZip = zip[i];
        }
        find(start, 0);
        FOR(i, n) if (!used[i]) {
            printf("Error2\n");
            exit(1);
        }
        if (visitedCount != n) {
            printf("Error3\n");
            exit(1);
        }

        printf("Case #%d: ", c);
        FOR(i, n) printf("%d", zip[sequence[i]]);
        printf("\n");
    }
}
