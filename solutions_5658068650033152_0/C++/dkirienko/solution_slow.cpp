#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// #define _DEBUG_

vector <int> P;
int N, M, K;

int Map[20][20];

int DX[4] = {0, 0, 1, -1};
int DY[4] = {-1, 1, 0, 0};


void DFS(int x, int y)
{
    Map[x][y] = 2;
    for(int i = 0; i < 4; i ++)
    {
        int nx = x + DX[i];
        int ny = y + DY[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < M && Map[nx][ny] == 0)
            DFS(nx, ny);
    }
}

int solve()
{
    int i, j, mask, ans = 0;
    cin >> N >> M >> K;
    ans = N * M;
    for (mask = 0; mask < 1 <<(N * M); ++mask)
    {
        int stones = 0;
        for(j = 0 ; j < N * M; ++j)
        {
            Map[j / M][j % M] = (mask >> j) & 1;
            stones += (mask >> j) & 1;
        }
        if (stones >= ans)
            continue;
        for (i = 0; i < N; ++i)
        {
            if (Map[i][0] == 0)
                DFS(i, 0);
            if (Map[i][M - 1] == 0)
                DFS(i, M - 1);
        }
        for (j = 0; j < M; ++j)
        {
            if (Map[0][j] == 0)
                DFS(0, j);
            if (Map[N - 1][j] == 0)
                DFS(N - 1, j);
        }
        #ifdef _DEBUG_
            for(i = 0; i < N; ++i)
            {
                for(j = 0; j < M; ++j)
                    cout<<Map[i][j];
                cout << endl;
            }
            cout << endl;
        #endif
        int points = 0;
        for (i = 0; i < N; ++i)
            for(j = 0; j < M; ++j)
                if (Map[i][j] != 2)
                    points++;
        if (points >= K && stones < ans)
            ans = stones;
    }
    return ans;
}

int main()
{
    int T, num;
    cin >> T;
    for (num = 1; num <= T; ++num)
    {
        cout << "Case #" << num << ": " << solve() << endl;
    }
}

