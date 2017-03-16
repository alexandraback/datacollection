#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

int lawns[100][100];

int main() {
    int T;
    assert(scanf("%d", &T) != EOF);

    for (int t = 1; t <= T; ++t) {
        int N, M;
        assert(scanf("%d %d", &N, &M) != EOF);

        for (int y = 0; y < N; ++y)
            for (int x = 0; x < M; ++x)
                assert(scanf("%d", &lawns[y][x]) != EOF);

        bool ok = true;
        for (int y = 0; y < N && ok; ++y)
            for (int x = 0; x < M && ok; ++x) {
                // horizontal
                bool c = true;
                for (int x2 = 0; x2 < M; ++x2) {
                    if (lawns[y][x2] > lawns[y][x]) {
                        c = false;
                        break;
                    }
                }
                if (c) continue;

                // vertical
                c = true;
                for (int y2 = 0; y2 < N; ++y2) {
                    if (lawns[y2][x] > lawns[y][x]) {
                        c = false;
                        break;
                    }
                }
                ok = c;
            }
        
        if (ok) 
            printf("Case #%d: YES\n", t);
        else
            printf("Case #%d: NO\n", t);
    }

    return 0;
}
