#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <memory.h>

using namespace std;

int destX, destY;
int cache[202][202][501];
const int INF = 987654321;

int go(int y, int x, int moves)
{
    if (moves > 500 || (y+100) < 0 || (y+100) > 200 || (x+100) < 0 || (x+100) > 200)
        return INF;

    int &ret = cache[y+100][x+100][moves];
    if (ret != -1)
        return ret;

    // printf("\n(%d, %d)[%d] ",y,x,moves);

    if (y == destY && x == destX)
        return ret = 1;

    ret = INF;

    int posX[4] = {-1, 1, 0, 0};
    int posY[4] = {0, 0, -1, 1};

    ++moves;

    for (int i=0; i<4; ++i)
        ret = min(ret, go(y+posY[i]*moves, x+posX[i]*moves, moves)+1);
        //ret = min(ret, go(y + posY[i] * (moves + 1), x + posX[i] * (moves + 1), moves + 1) + 1);

    // printf(" = %d", ret);
    return ret;
}

void reconstruct(int y, int x, int moves, string ret)
{
    if (y == destY && x == destX) {
        cout << ret; //"Answer: " << ret << endl;
        return;
    }

    int posX[4] = {-1, 1, 0, 0};
    int posY[4] = {0, 0, -1, 1};
    char sel[4] = {'W','E','S','N'};

    ++moves;
    for (int i=0; i<4; ++i) {
        if (go(y, x, moves-1) - 1 == go(y + posY[i] * moves, x + posX[i] * moves, moves)) {
            reconstruct(y + posY[i] * moves, x + posX[i] * moves, moves, ret + sel[i]);
            return;
        }
        //else
        //    printf("\n%d != %d", go(y, x, moves-1), go(y + posY[i] * moves, x + posX[i] * moves, moves));
    }
}

int main()
{
    int Test, Cases = 1; scanf("%d", &Test); while(Test--) {
        printf("Case #%d: ", Cases++);

        cin >> destX >> destY;

        memset(cache, -1, sizeof(cache));

        //cout << go(0, 0, 0);

        string ret = "";
        reconstruct(0, 0, 0, ret);

        cout << endl;
    }
}