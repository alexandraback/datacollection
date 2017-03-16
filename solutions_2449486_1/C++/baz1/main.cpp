//#include <QtCore>
#include <stdio.h>

static int board[100][100];
static int hasCut[100][100];
static int N, M;

void getBoard()
{
    scanf("%d", &N);
    scanf("%d", &M);
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            scanf("%d", &board[x][y]);
            hasCut[x][y] = false;
        }
    }
}

int getMin(int &x, int &y)
{
    int current_min = 100;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if ((!hasCut[i][j]) && (board[i][j] < current_min))
            {
                x = i;
                y = j;
                current_min = board[i][j];
            }
        }
    }
    return current_min;
}

char *run()
{
    int x, y, min, i;
    while ((min = getMin(x, y)) < 100)
    {
        for (i = 0; i < M; ++i)
        {
            if (board[i][y] > min) break;
        }
        if (i < M)
        {
            for (i = 0; i < N; ++i)
            {
                if (board[x][i] > min) break;
            }
            if (i < N) return "NO";
        } else {
            for (i = 0; i < M; ++i)
                hasCut[i][y] = true;
            for (i = 0; i < N; ++i)
            {
                if (board[x][i] > min) break;
            }
        }
        if (i >= N)
        {
            for (i = 0; i < N; ++i)
                hasCut[x][i] = true;
        }
    }
    return "YES";
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        getBoard();
        printf("Case #%d: %s\n", i, run());
    }
    return 0;
}
