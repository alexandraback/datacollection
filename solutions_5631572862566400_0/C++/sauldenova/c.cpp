#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int T, N, color, bestSolution;
int fav[MAXN];
int colors[MAXN];
int distanceToCycle[MAXN];
int size[MAXN];
int cycleMembers[MAXN][2];
int currentDepth[MAXN];
int cycleStart[MAXN];
int biggestDistanceToStart[MAXN];
bool visited[MAXN];

int findSolution(int i, int parent=-1, int depth=1) {
    if (!visited[i]) {
        visited[i] = true;
        currentDepth[i] = depth;
        int result = findSolution(fav[i], i, depth + 1) + 1;
        colors[i] = colors[fav[i]];
        distanceToCycle[i] = max(0, result);
        currentDepth[i] = -1;
        if (cycleStart[i] == -1) {
            cycleStart[i] = cycleStart[fav[i]];
        }

        if (size[colors[i]] == 2) {
            biggestDistanceToStart[cycleStart[i]] = max(biggestDistanceToStart[cycleStart[i]], distanceToCycle[i]);

            bestSolution = max(bestSolution, biggestDistanceToStart[cycleMembers[colors[i]][0]] + biggestDistanceToStart[cycleMembers[colors[i]][1]] + 2);
        }

        //printf(">%d %d\n", i, result);
        return result;
    } else {
        if (currentDepth[i] != -1) {
            size[color] = depth - currentDepth[i];
            colors[i] = color;
            distanceToCycle[i] = 0;
            if (size[color] > 2) {
                bestSolution = max(bestSolution, size[color]);
            } else if(size[color] == 2) {
                cycleStart[i] = i;
                cycleStart[parent] = parent;
                cycleMembers[color][0] = i;
                cycleMembers[color][1] = parent;
            }

            color++;

            return currentDepth[i] - depth;
        }

        return distanceToCycle[i];
    }
    /*if(!visited[i]) {
        visited[i] = true;
        currentDepth[i] = depth;
        bestSolution = findSolution(fav[i], i, depth + 1);
        currentDepth[i] = -1;
    } else {
        if (specialNodes[i] != -1) {
            if (specialNodes[i] < depth - 1) {
                specialNodes[i] = depth - 1;
            }

            bestSolution = 2 + specialNodes[i] + specialNodes[fav[i]];
        } else if (currentlyVisited[i]) {
            if (depth - visited[i] == 2) {
                if (specialNodes[i] < depth - 3) {
                    specialNodes[i] = depth - 3;
                }

                if (specialNodes[parent] == -1) {
                    specialNodes[parent] = 0;
                }

                bestSolution = 2 + specialNodes[i] + specialNodes[parent];
            } else {
                bestSolution = depth - visited[i];
            }
        }
    }//*/
}

int main(void) {
    memset(currentDepth, -1, sizeof(currentDepth));
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        memset(visited, false, sizeof(visited));
        memset(colors, -1, sizeof(colors));
        memset(distanceToCycle, -10000, sizeof(distanceToCycle));
        memset(cycleStart, -1, sizeof(cycleStart));
        memset(biggestDistanceToStart, -1, sizeof(biggestDistanceToStart));
        memset(cycleMembers, -1, sizeof(cycleMembers));
        color = 0;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d\n", &fav[i]);
            fav[i]--;
        }

        bestSolution = -1;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                findSolution(i);
            }
        }

        /*for (int i = 0; i < N; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");

        for (int i = 0; i < N; i++) {
            printf("%d ", distanceToCycle[i]);
        }
        printf("\n");

        for (int i = 0; i < N; i++) {
            printf("%d ", cycleStart[i]);
        }
        printf("\n");

        for (int i = 0; i < N; i++) {
            printf("%d ", biggestDistanceToStart[i]);
        }
        printf("\n");

        for (int i = 0; i < color; i++) {
            printf("%d ", size[i]);
        }
        printf("\n");//*/

        printf("Case #%d: %d\n", t, bestSolution);
    }
    return 0;
}
