#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    int r, c, m;
    int i, j;
    bool inv;
    bool solved = false;
    char mat[100][100];
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d %d %d\n", &r, &c, &i);
        m = r * c - i;
        printf("Case #%d:\n", t + 1);
        solved = false;

        inv = false;
        if (r < c)
        {
            i = c;
            c = r;
            r = i;
            inv = true;
        }

        if (m == 1)
        {
            solved = true;
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    mat[i][j] = '*';
                }
            }
            mat[0][0] = 'c';
        }
        else if (c == 1)
        {
            solved = true;
            for (i = 1; i < m; i++)
            {
                mat[i][0] = '.';
            }
            for (i = m; i < r; i++)
            {
                mat[i][0] = '*';
            }
            mat[0][0] = 'c';
        }
        else if (c == 2)
        {
            if (m % 2 == 0 && m >= 4)
            {
                solved = true;
                for (i = 0; i < m/2; i++)
                {
                    mat[i][0] = '.';
                    mat[i][1] = '.';
                }
                for (i = m/2; i < r; i++)
                {
                    mat[i][0] = '*';
                    mat[i][1] = '*';
                }
                mat[0][0] = 'c';
            }
        }
        else
        {
            if (m == 4 || m == 6 || m >= 8)
            {
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        mat[i][j] = '*';
                    }
                }
                solved = true;
                if (m <= (2 * c + 1))
                {
                    if (m % 2 == 1)
                    {
                        for (i = 0; i < m/2 - 1; i++)
                        {
                            mat[0][i] = '.';
                            mat[1][i] = '.';
                        }
                        mat[2][0] = '.';
                        mat[2][1] = '.';
                        mat[2][2] = '.';
                    }
                    else
                    {
                        for (i = 0; i < m/2; i++)
                        {
                            mat[0][i] = '.';
                            mat[1][i] = '.';
                        }
                    }
                }
                else
                {
                    for (i = 0; i < m; i++)
                    {
                        mat[i/c][i%c] = '.';
                    }
                    if (m % c == 1)
                    {
                        mat[m/c][1] = '.';
                        mat[m/c - 1][c - 1] = '*';
                    }
                }
                mat[0][0] = 'c';
            }
        }

        if (!solved)
        {
            printf("Impossible\n");
        }
        else
        {
            if (!inv)
            {
                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        printf("%c", mat[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                for (j = 0; j < c; j++)
                {
                    for (i = 0; i < r; i++)
                    {
                        printf("%c", mat[i][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
