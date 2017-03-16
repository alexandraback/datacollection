#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[1010][1010];
int n;
/*
int find_path(int src, int dest) {
    memset(reached, 0, sizeof(reached));
    int flow = 100000000;
    int queue[1010];
    int front = 0; 
    int end = 0;
    queue[end++] = src;

    while (front < end) {
        int current = queue[front++];
        reached[current] = 1;
        for (int i = 0; i < num_edges[current]; ++i) {
            int next = edges[current][i];
            int r = 1 - graph[current][next];
            if (r > 0 && !reached[next]) {
                queue[end++] = next;
            }
        }
    
    }
}

int test1(int begin, int end) {
    static int buffer[10000];

    int flow = find_path(begin, end);
    while (flow) {
        for (int i = 0; i < len; ++i) {
            int v1 = path_v1[i];
            int v2 = path_v2[i];
            graph[v1][v2] += flow;
            graph[v2][v1] -= flow;
        }
        flow = find_path(begin, end);
    }
    return (graph[begin][end] >= 2); 
}

int find_path(int src, int dest) {
    reached[src] = 1;
    if (src == dest)
        return 1;
    for (int i = 0; i < num_edges[src]; ++i) {
        int next = edges[src][i];
        if (!reached[next]) {
            if (find_path(next, dest))
                return 1;
        }
    }
    return 0;
}
*/

int test() {
    int i, j, k;
    for (int k = 0; k < n; ++k) 
        for (int i = 0; i < n; ++i)
            if (map[i][k] > 0)
                for (int j = 0; j < n; ++j) {
                    map[i][j] += map[i][k] * map[k][j];
                }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && map[i][j] >= 2)
                return 1;
    return 0;
}

int main() {
    int num_cases;
    int turn;
    scanf("%d", &num_cases);

    for (turn = 1; turn <= num_cases; ++turn) {
        scanf("%d", &n);
        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; ++i) {
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; ++j) {
                int b;
                scanf("%d", &b);
                map[i][b - 1] = 1;
            }
        }
        printf("Case #%d: ", turn);
        if (test())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
