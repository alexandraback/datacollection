#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int g[107][107], hmax[107], wmax[107], T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int h, w;
        cin >> h >> w;

        for (int i = 0; i < h; ++i)
            hmax[i] = 0;
        for (int i = 0; i < w; ++i)
            wmax[i] = 0;

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                scanf("%d", &g[i][j]);
                hmax[i] = g[i][j] > hmax[i] ? g[i][j] : hmax[i];
                wmax[j] = g[i][j] > wmax[j] ? g[i][j] : wmax[j];
            }

        short flag = 0;
        for (int i = 0; i < h && !flag; ++i)
            for (int j = 0; j < w && !flag; ++j)
                if (g[i][j] < hmax[i] && g[i][j] < wmax[j])
                    flag = 1;

        cout << "Case #" << t+1;
        if (flag)
            printf(": NO\n");
        else
            printf(": YES\n");



    }

    return 0;
}

