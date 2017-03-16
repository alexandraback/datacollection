#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int result[64][64] = {{0}};
int graph[64][64] = {{0}};
int res = 0;
int N = 0;
int M = 0;
bool found = false;

void dfs(int root) {
    /*
    if (root == 0) {
        cerr << "graph:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cerr << graph[i][j];
            }
            cerr << endl;
        }
        cerr << endl;
    }
    */
    
    if (root == N - 1) {
        res++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (i != root &&  graph[root][i] != 0) {
            dfs(i);
        }
    }
}

void construct(int root) {
    if (found) {
        return;
    }

    if (root == N - 1) {
        res = 0;
        dfs(0);
        // cout << "res = " << res << endl;
        if (res == M) {
            found = true;
            return;
        }
        return;
    }

    int remain = N - root - 1;
    for (int i = 0; i < N; i++) {
        graph[root][i] = 0;
    }
    for (int i = 0; i < (1<<remain) && found == false; i++) {
        int x = i;
        int idx = root + 1;
        while (x > 0) {
            if ((x & 1) && root != idx) {
                graph[root][idx] = 1;
            } else {
                graph[root][idx] = 0;
            }
            idx += 1;
            x = (x >> 1);
        }
        construct(root + 1);
    }
}

int main(int argc, char *argv[])
{
    int T = 0;
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        cin >> N >> M;
        found = false;
        memset(graph, 0, sizeof(graph));
        construct(0);

        if (found) {
            cout << "Case #" << cas << ": POSSIBLE" << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << graph[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "Case #" << cas << ": IMPOSSIBLE" << endl;
        }
    }
    return 0;
}

    
