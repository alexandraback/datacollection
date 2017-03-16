/* 
 * File:   main.cpp
 * Author: paulo
 *
 * Created on 6 de Maio de 2012, 05:30
 */

#include <stdio.h>
#include <string.h>

bool diamond = false;

bool paths[1000][1000];
bool reached[1000];

void find_diamond(int current, int nclasses, int depth) {
    // Checks if it should stop
    if (diamond || depth > nclasses)
        return;
    for (int i = 0; i < nclasses && !diamond; i++) {
        // If it's the first depth, clears the reached classes
        if (depth == 0) {
            memset(reached, 0, sizeof (bool)*1000);
            find_diamond(i, nclasses, depth + 1);
        } else {
            if (paths[current][i]) {
                if (reached[i]) {
                    diamond = true;
                    return;
                } else
                {
                    reached[i] = true;
                    find_diamond(i, nclasses, depth+1);
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        // Clears the diamond flag
        diamond = false;
        // Clears the graph
        memset(paths, 0, sizeof (bool)*1000 * 1000);
        int N;
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            // How many paths leaving from this node are there
            int npaths;
            scanf("%d", &npaths);
            // Reads the paths
            for (int k = 0; k < npaths; k++) {
                int cl;
                scanf("%d", &cl);
                paths[j][cl - 1] = true;
            }
        }
        // Finds the diamonds, if any
        find_diamond(0, N, 0);

        if (diamond)
            printf("Case #%d: Yes\n", i + 1);
        else
            printf("Case #%d: No\n", i + 1);
    }
    return 0;
}

