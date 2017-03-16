
#include <cstdio>
#include <list>
using namespace std;

#define N 1000
int table[N][N];
list<char> lst[N][N];

void solve()
{
    int x, y;
    scanf("%d%d", &x, &y);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            table[i][j] = 0;
        }
    }

    table[N / 2][N / 2] = 1;

    const int
        dx[] = {0, 0, 1, -1},
        dy[] = {1, -1, 0, 0};
    const char
        msg[] = {'N', 'S', 'E', 'W'};

    for (int run = 1; run <= 500; run++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (table[i][j] == run)
                {
                    if (i == x + N / 2 && j == y + N / 2)
                    {
                        for (auto it = lst[i][j].begin(); it != lst[i][j].end();
                            ++it)
                        {
                            printf("%c", *it);
                        }
                        return;
                    }

                    for (int p = 0; p < 4; p++)
                    {
                        int ni = i + dx[p] * run;
                        int nj = j + dy[p] * run;

                        if (0 <= ni && 0 <= nj &&
                            ni < N && nj < N &&
                            table[ni][nj] == 0)
                        {
                            table[ni][nj] = run + 1;
                            lst[ni][nj] = lst[i][j];
                            lst[ni][nj].push_back(msg[p]);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int n;
    scanf("%d", &n);

    for (int t = 1; t <= n; t++)
    {
        printf("Case #%d: ", t);
        solve();
        printf("\n");
    }
}