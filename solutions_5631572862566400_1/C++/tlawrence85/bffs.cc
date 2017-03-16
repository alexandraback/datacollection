#include <stdio.h>
#include <vector>
#include <assert.h>

using namespace std;

int bff[1000];
//int best[1000][1000];
int bestPrevs[1000][2];
int bestPrevLens[1000][2];

// [0] is length, [1] is prev
int cycle[1000][2];

void updateBest(int curr, int prev, int len) {
    int idx = 0;
    if (bff[curr] == prev) {
        idx = 1;
    }
    if (len > bestPrevLens[curr][idx]) {
        bestPrevs[curr][idx] = prev;
        bestPrevLens[curr][idx] = len;
    }
}

void follow(int startInd) {
    bool seen[1000];
    memset(seen, 0, sizeof(seen));

    int prev;
    int curr = startInd;
    int len = 1;
    seen[curr] = true;

    while (!seen[bff[curr]]) {
        ++len;
        prev = curr;
        curr = bff[curr];
        seen[curr] = true;

        //if (best[curr][prev] < len) {
            //best[curr][prev] = len;
            updateBest(curr, prev, len);
        //}
    }

    int cycleBegin = curr;
    len = 1;
    while (bff[curr] != cycleBegin) {
        curr = bff[curr];
        ++len;
    }

    curr = cycleBegin;
    while (bff[curr] != cycleBegin) {
        assert(cycle[bff[curr]][0] == 0 ||
               cycle[bff[curr]][0] == len);
        cycle[bff[curr]][0] = len;
        cycle[bff[curr]][1] = curr;
        curr = bff[curr];
    }
    cycle[cycleBegin][0] = len;
    cycle[cycleBegin][1] = curr;
}

int solve() {
    int kids;
    scanf("%d", &kids);

    for (int i = 0; i < kids; ++i) {
        scanf("%d", &bff[i]);
        --bff[i];
    }

    //memset(best, 0, sizeof(best));
    memset(bestPrevs, 0, sizeof(bestPrevs));
    memset(bestPrevLens, 0, sizeof(bestPrevLens));
    memset(cycle, 0, sizeof(cycle));

    for (int i = 0; i < kids; ++i) {
        updateBest(i, -1, 1);
        follow(i);
    }

    int bestCycle = 0;
    int total = 0;
    for (int i = 0; i < kids; ++i) {
        bestCycle = max(bestCycle, cycle[i][0]);

        //if (bestPrevLens[i][0] == 0) bestPrevLens[i][0] = 1;

        if (bff[bff[i]] == i) {
            assert(bestPrevLens[i][0] + 1 == bestPrevLens[bff[i]][1]);
            assert(bestPrevLens[i][0] >= 1 && bestPrevLens[bff[i]][0] >= 1);

            //if (bestPrevLens[bff[i]][0] == 0) bestPrevLens[bff[i]][0] = 1;
            total += bestPrevLens[i][0];
        }

        //printf("%d: %d, %d, %d, %d\n", i, curr, cycle[i][0], bestPrevLens[i][0], bestPrevLens[i][1]);
    }

    return max(bestCycle, total);
}


int main(void) {
    int nC;
    scanf("%d", &nC);
    for (int cC = 0; cC < nC; ++cC) {
        printf("Case #%d: %d\n", cC + 1, solve());
    }

    return 0;
}