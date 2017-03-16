#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#pragma comment(linker, "/STACK:167772160")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.);

char buff[5][5];

const int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool win(int x, int y, char c)
{
    for (int i = 0; i < 8; ++i)
    {
        int cnt = 0;
        int nx = x;
        int ny = y;
        for (int j = 0; j < 4; ++j)
        {
            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
                break;
            if (buff[nx][ny] != 'T' && buff[nx][ny] != c)
                break;
            ++cnt;
            nx += dirx[i];
            ny += diry[i];
        }
        if (cnt == 4) return true;
    }
    return false;
}

void solve()
{
    for (int i = 0; i < 4; ++i)
    {
        scanf("%s", buff[i]);
    }
    bool hasEmp = false;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (win(i, j, 'X'))
            {
                puts("X won");
                return;
            }
            if (win(i, j, 'O'))
            {
                puts("O won");
                return;
            }
            if (buff[i][j] == '.')
                hasEmp = true;
        }
    }
    if (hasEmp)
        puts("Game has not completed");
    else
        puts("Draw");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }
	return 0;
}