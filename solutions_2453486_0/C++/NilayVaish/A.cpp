#include<cstdio>

bool cRow(char B[4][15], char c)
{
    for(int i = 0; i < 4; ++i)
    {
        bool found = true;
        for (int j = 0; j < 4; ++j) if (B[i][j] != c && B[i][j] != 'T') found = false;
        if (found) return true;
    }

    return false;
}

bool cCol(char B[4][15], char c)
{
    for(int i = 0; i < 4; ++i)
    {
        bool found = true;
        for (int j = 0; j < 4; ++j) if (B[j][i] != c && B[j][i] != 'T') found = false;
        if (found) return true;
    }

    return false;
}

bool cDiag(char B[4][15], char c)
{
    bool found = true;
    for(int i = 0; i < 4; ++i)
    {
        if (B[i][i] != c && B[i][i] != 'T') found = false;
    }
    if (found) return true;
    found = true;

    for(int i = 0; i < 4; ++i)
    {
        if (B[i][3-i] != c && B[i][3-i] != 'T') found = false;
    }

    if (found) return true;
    return false;
}

int main()
{
    int T;
    scanf("%d\n", &T);

    for(int ii = 1; ii <= T; ++ii)
    {
        char B[4][15];
        int status = 2;

        for(int i = 0; i < 4; ++i) scanf("%s\n", B[i]);

        if (cRow(B,'X') || cCol(B,'X') || cDiag(B,'X')) status = 0;
        else if (cRow(B,'O') || cCol(B,'O') || cDiag(B,'O')) status = 1;

        if (status == 0) printf("Case #%d: X won\n",ii);
        else if (status == 1) printf("Case #%d: O won\n",ii);
        else
        {
            for(int i = 0; i < 4; ++i)
            {
                if (B[i][0] == '.' ||
                    B[i][1] == '.' ||
                    B[i][2] == '.' ||
                    B[i][3] == '.') status = 3;
            }
            if(status == 3)
            {
                printf("Case #%d: Game has not completed\n",ii);
                continue;
            }
            else printf("Case #%d: Draw\n",ii);
        }
    }
    return 0;
}
