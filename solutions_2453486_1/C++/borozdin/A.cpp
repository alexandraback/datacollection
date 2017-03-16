#include <iostream>
#include <algorithm>
using namespace std;

char s[5][5];

bool wins(char c)
{
    for (int i = 0; i < 4; i++)
    {
        bool fail = false;
        for (int j = 0; j < 4 && !fail; j++)
            if (s[i][j] != c && s[i][j] != 'T')
                fail = true;
        if (!fail)
            return true;
    }

    for (int j = 0; j < 4; j++)
    {
        bool fail = false;
        for (int i = 0; i < 4 && !fail; i++)
            if (s[i][j] != c && s[i][j] != 'T')
                fail = true;
        if (!fail)
            return true;
    }

    bool fail = false;
    for (int i = 0; i < 4 && !fail; i++)
        if (s[i][i] != c && s[i][i] != 'T')
            fail = true;
    if (!fail)
        return true;

    fail = false;
    for (int i = 0; i < 4 && !fail; i++)
        if (s[i][3 - i] != c && s[i][3 - i] != 'T')
            fail = true;
    if (!fail)
        return true;

    return false;
}

void solve()
{
    bool winX = wins('X');
    bool winO = wins('O');
    if (winX && winO)
        printf("Draw\n");
    else if (winX)
        printf("X won\n");
    else if (winO)
        printf("O won\n");
    else
    {
        bool found = false;
        for (int i = 0; i < 4 && !found; i++)
            for (int j = 0; j < 4 && !found; j++)
                if (s[i][j] == '.')
                    found = true;
        if (found)
            printf("Game has not completed\n");
        else
            printf("Draw\n");
    }
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int tstCnt;
    scanf("%d", &tstCnt);
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        for (int i = 0; i < 4; i++)
            scanf("%s", s[i]);
        printf("Case #%d: ", tst);
        solve();
    }

    return 0;
}
