#include <iostream>
using namespace std;

const int N = 110;
long long  D[N][N];
long long  F[N][N];
long long  C[N][N];

int vx[] = {1, 0, -1, 0};
int vy[] = {0, 1, 0, -1};

const int V = 4;
long long  T1[V][N][N], T2[V][N][N];

const long long  INF = 10000500;
long long  T[N][N];

void go()
{
    long long  h, n, m;
    cin >> h >> n >> m;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            F[i][j] = C[i][j] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> C[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> F[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int v = 0; v < 4; v++)
            {
                long long  a = F[i][j], b = C[i][j];
                int i2 = i + vy[v], j2 = j + vx[v];
                long long  c = F[i2][j2], d = C[i2][j2];
                if (min(b, d) - max(a, c) < 50)
                    T1[v][i][j] = T2[v][i][j] = INF;
                else
                {
                    T1[v][i][j] = h - (min(b, d) - 50),
                    T2[v][i][j] = h - (a + 20);
                    if (T1[v][i][j] <= 0)
                        T1[v][i][j] = -INF - 1;
                }
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            T[i][j] = INF;
    T[1][1] = -INF;

    for (int iter = 0; iter < n * m; iter++)
    {
        bool was = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                for (int v = 0; v < 4; v++)
                {
                    long long  wc = T[i][j];
                    int i2 = i + vy[v], j2 = j + vx[v];
                    long long  tc = T[i2][j2];
                    if (wc < T1[v][i][j])
                        wc = T1[v][i][j];
                    long long  nc;
                    if (wc <= T2[v][i][j])
                        nc = wc + 10;
                    else
                        nc = wc + 100;
                    if (nc < tc)
                        T[i2][j2] = nc, was = true;
                }
            }
        if (!was)
            break;
    }
    if (T[n][m] < 0)
        T[n][m] = 0;
    cout << T[n][m] / 10 << '.' << T[n][m] % 10;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cerr << i << endl;
        cout << "Case #" << i + 1 << ": ";
        go();
        cout << endl;
    }
}
