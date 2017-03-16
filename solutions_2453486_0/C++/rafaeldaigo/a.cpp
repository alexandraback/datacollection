#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int xline[40] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
int yline[40] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 0, 1, 2, 3, 3, 2, 1, 0};

int main()
{
    int t, teste;
    int n;
    int i, j;
    char mat[10][10];
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        for (i = 0; i < 5; i++)
        {
            gets(mat[i]);
        }

        bool solved = false;

        if (solved == false)
        {
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    int x = xline[4 * i + j];
                    int y = yline[4 * i + j];
                    if (mat[x][y] != 'O' && mat[x][y] != 'T')
                    {
                        break;
                    }
                }
                if (j == 4)
                {
                    printf("Case #%d: O won\n", t + 1);
                    solved = true;
                    break;
                }
            }
        }

        if (solved == false)
        {
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    int x = xline[4 * i + j];
                    int y = yline[4 * i + j];
                    if (mat[x][y] != 'X' && mat[x][y] != 'T')
                    {
                        break;
                    }
                }
                if (j == 4)
                {
                    printf("Case #%d: X won\n", t + 1);
                    solved = true;
                    break;
                }
            }
        }

        if (solved == false)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (mat[i][j] == '.')
                    {
                        break;
                    }
                }
                if (j < 4)
                    break;
            }
            if (i < 4)
            {
                printf("Case #%d: Game has not completed\n", t + 1);
            }
            else
            {
                printf("Case #%d: Draw\n", t + 1);
            }
        }
    }
    return 0;
}
