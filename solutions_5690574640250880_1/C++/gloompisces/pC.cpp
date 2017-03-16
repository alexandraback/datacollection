#include <stdio.h>
#include <string.h>

int map[55][55];

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    
    int R, C, M, ans;
    int cases;
    scanf("%d", &cases);
    for (int case_index = 1; case_index <= cases; case_index++)
    {
        memset(map, 0, sizeof(map));
        scanf("%d %d %d", &R, &C, &M);
        ans = 0;
        map[1][1] = 1;
        
        if (M > 0)
        {
            if (R == 1)
            {
                for (int i = 1; i <= M; i++)
                {
                    map[1][C - i + 1] = 2;
                }
            }
            else if (C == 1)
            {
                for (int i = 1; i <= M; i++)
                {
                    map[R - i + 1][1] = 2;
                }
            }
            else
            {
                if (M == R * C - 1)
                {
                    for (int i = 1; i <= R; i++)
                    {
                        for (int j = 1; j <= C; j++)
                        {
                            if (i != 1 || j != 1)
                            {
                                map[i][j] = 2;
                            }
                        }
                    }
                }
                else if (M == R * C - 2 || M == R * C - 3)
                {
                    ans = -1;
                }
                else
                {
                    if (R == 2)
                    {
                        if (M % 2 == 0)
                        {
                            for (int i = 1; i <= M / 2; i++)
                            {
                                map[1][C - i + 1] = 2;
                                map[2][C - i + 1] = 2;
                            }
                        }
                        else
                        {
                            ans = -1;
                        }
                    }
                    else if (C == 2)
                    {
                        if (M % 2 == 0)
                        {
                            for (int i = 1; i <= M / 2; i++)
                            {
                                map[R - i + 1][1] = 2;
                                map[R - i + 1][2] = 2;
                            }
                        }
                        else
                        {
                            ans = -1;
                        }
                    }
                    else
                    {
                        int _not = R * C - M;
                        if (_not == 5 || _not == 7)
                        {
                            ans = -1;
                        }
                        else if (_not == 6)
                        {
                            for (int i = 1; i <= R; i++)
                            {
                                for (int j = 1; j <= C; j++)
                                {
                                    if (i > 3 || j > 2)
                                    {
                                        map[i][j] = 2;
                                    }
                                }
                            }
                        }
                        else if (_not % C != 1 && _not / C >= 2)
                        {
                            for (int i = 1; i <= R; i++)
                            {
                                for (int j = 1; j <= C; j++)
                                {
                                    if ((i - 1) * C + j > _not)
                                    {
                                        map[i][j] = 2;
                                    }
                                }
                            }
                        }
                        else if (_not % R != 1 && _not / R >= 2)
                        {
                            for (int j = 1; j <= C; j++)
                            {
                                for (int i = 1; i <= R; i++)
                                {
                                    if ((j - 1) * R + i > _not)
                                    {
                                        map[i][j] = 2;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (_not / R > 2)
                            {
                                for (int i = 1; i <= R; i++)
                                {
                                    for (int j = 1; j <= C; j++)
                                    {
                                        if ((i - 1) * C + j > _not + 1)
                                        {
                                            map[i][j] = 2;
                                        }
                                    }
                                }
                                map[_not / R][C] = 2;
                            }
                            else
                            {
                                for (int i = 1; i <= R; i++)
                                {
                                    for (int j = 1; j <= C; j++)
                                    {
                                        map[i][j] = 2;
                                    }
                                }
                                
                                for(int i = 1; i <= R; i++)
                                {
                                    if (_not == 0)
                                    {
                                        break;
                                    }
                                    else if (_not == 2)
                                    {
                                        map[i][1] = 0;
                                        map[i][2] = 0;
                                        _not = 0;
                                    }
                                    else if (_not == 4)
                                    {
                                        map[i][1] = 0;
                                        map[i][2] = 0;
                                        _not = 2;
                                    }
                                    else
                                    {
                                        map[i][1] = 0;
                                        map[i][2] = 0;
                                        map[i][3] = 0;
                                        _not -= 3;
                                    }
                                }
                                
                                map[1][1] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        printf("Case #%d:\n", case_index);
        if (ans == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            for (int i = 1; i <= R; i++)
            {
                for (int j = 1; j <= C; j++)
                {
                    if (map[i][j] == 1)
                    {
                        printf("c");
                    }
                    else if (map[i][j] == 2)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
    }
    
    return 0;
}
