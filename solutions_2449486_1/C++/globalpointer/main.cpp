#include <iostream>

int N, M;
int h[105][105];
int rmax[105];
int cmax[105];

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> N >> M;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                std::cin >> h[i][j];
        for (int i = 0; i < N; i++)
            rmax[i] = 0;
        for (int j = 0; j < M; j++)
            cmax[j] = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                rmax[i] = std::max(rmax[i], h[i][j]);
        for (int j = 0; j < M; j++)
            for (int i = 0; i < N; i++)
                cmax[j] = std::max(cmax[j], h[i][j]);

        bool PROGARDENER = true;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (h[i][j] < rmax[i] && h[i][j] < cmax[j])
                    PROGARDENER = false;

        std::cout << "Case #" << t << ": " << (PROGARDENER ? "YES" : "NO") << '\n';
    }
}

