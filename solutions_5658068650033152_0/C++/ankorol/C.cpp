#include <iostream>

using namespace std;


int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N, M, K;
        cin >> N >> M >> K;
        if ((N == 1) || (M == 1))
        {
            cout << "Case #" << t << ": " << K << endl;
            continue;
        }
        int ans = K;
        for (int i = 0; i < (1 << N * M); ++i)
        {
            int a[20][20] = {0};
            int tt = 0;
            for (int j = 0; j < N; ++j)
                for (int l = 0; l < M; ++l)
                {
                    if ((i & (1 << (j * M + l))) != 0)
                    {
                        a[j][l] = 1;
                        tt++;
                    }
                }
            int q[30] = {0};
            int qb = 0;
            int qe = 0;
            int w[20][20] = {0};
            for (int j = 0; j < N; ++j)
            {
                if (a[j][0] == 0)
                {
                    q[qe++] = j * 100;
                    w[j][0] = 1;
                }
                if (a[j][M - 1] == 0)
                {
                    q[qe++] = j * 100 + M - 1; 
                    w[j][M - 1] = 1;
                }
            }
            for (int l = 1; l < M - 1; ++l)
            {
                if (a[0][l] == 0)
                {
                    q[qe++] = l;
                    w[0][l] = 1;
                }
                if (a[N - 1][l] == 0)
                {
                    q[qe++] = (N - 1) * 100 + l;
                    w[N - 1][l] = 1;
                }
            }
            
            int kol = 0;
            while (qb < qe)
            {
                int x = q[qb] / 100;
                int y = q[qb] % 100;
                kol++;
                qb++;
                if ((x - 1 >= 0) && (w[x - 1][y] == 0) && (a[x - 1][y] == 0))
                {
                    q[qe++] = (x - 1) * 100 + y;
                    w[x - 1][y] = 1;
                }
                if ((x + 1 < N) && (w[x + 1][y] == 0) && (a[x + 1][y] == 0))
                {
                    q[qe++] = (x + 1) * 100 + y;
                    w[x + 1][y] = 1;
                }
                if ((y - 1 >= 0) && (w[x][y - 1] == 0) && (a[x][y - 1] == 0))
                {
                    q[qe++] = x * 100 + y - 1;
                    w[x][y - 1] = 1;
                }
                if ((y + 1 < M) && (w[x][y + 1] == 0) && (a[x][y + 1] == 0))
                {
                    q[qe++] = x * 100 + y + 1;
                    w[x][y + 1] = 1;
                }
            }
            if (N * M - kol >= K)
            {
                if (ans > tt)
                    ans = tt;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}