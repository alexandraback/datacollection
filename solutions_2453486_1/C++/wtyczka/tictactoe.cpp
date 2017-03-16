#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct Jump {
    int init, jump;
};

enum Result {
    WON_X,
    WON_O,
    DRAW,
    UNKN
};

Result checkJump(const vector<char> &board, const Jump &jump)
{
    int x_count = 0, o_count = 0, t_count = 0;

    vector<char>::const_iterator it = board.begin() + jump.init;

    int n = 4;
    while (n--) {
        if (*it == 'X')
            x_count++;
        else
        if (*it == 'O')
            o_count++;
        else
        if (*it == 'T')
            t_count++;

        it += jump.jump;
    }

    if (o_count + t_count == 4)
        return WON_O;

    if (x_count + t_count == 4)
        return WON_X;

    if (x_count + o_count + t_count == 4)
        return DRAW;
    
    return UNKN;
}

Result alg(const vector<char> &board)
{
    static Jump advances[] = {
        {0, 1}, {4, 1}, {8, 1}, {12, 1},
        {0, 4}, {1, 4}, {2, 4}, {3, 4},
        {0, 5}, {3, 3}};

    int counters[] = {0, 0, 0, 0};

    for (int i = 0; i < sizeof(advances) / sizeof(advances[0]); i++) {
        Result r = checkJump(board, advances[i]);
        counters[r]++;
    }

    if (counters[WON_O] > 0) return WON_O;
    if (counters[WON_X] > 0) return WON_X;
    if (counters[UNKN] > 0) return UNKN;
    return DRAW;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    scanf("%d\n", &t);

    for (int i = 0; i < t; i++) {

        vector<char> board;

        int n = 4;
        while (n--) {
            int m = 4;
            while (m--) {
                board.push_back(getchar());
            }
            getchar();
        }
        getchar();

        printf("Case #%d: ", i + 1);

        switch (alg(board)) {
            case WON_O:
                printf("O won\n");
                break;
            case WON_X:
                printf("X won\n");
                break;
            case UNKN:
                printf("Game has not completed\n");
                break;
            case DRAW:
                printf("Draw\n");
                break;
        }
    }
}

