#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    int t;
    scanf("%d", &t);
    char a[51][51];
    for(int CASE = 1; CASE <= t; CASE ++)
    {
        int row, col, M;
        scanf("%d %d %d", &row, &col, &M);
        int remain = row*col - M;
        bool flag = false;
        for(int i = 0; i < row; i ++)
            for(int j = 0; j < col; j ++)
                a[i][j] = '*';
        if(M == 0)
        {
            flag = true;
            for(int i = 0; i < row; i ++)
                for(int j = 0; j < col; j ++)
                    a[i][j] = '.';
            a[0][0] = 'c';
        }
        else if(remain == 1)
        {
            flag = true;
            a[0][0] = 'c';
        }
        else
        {
            if(row == 1 || col == 1)
            {
                flag = true;
                if(row == 1)
                {
                    a[0][0] = 'c';
                    for(int i = 1; i < remain; i ++)
                        a[0][i] = '.';
                }
                else
                {
                    a[0][0] = 'c';
                    for(int i = 1; i < remain; i ++)
                        a[i][0] = '.';
                }
            }
            else if(row == 2 || col == 2)
            {
                if(remain % 2 == 0 && remain > 2)
                {
                    flag = true;
                    if(row == 2)
                    {
                        a[0][0] = 'c'; a[1][0] = '.';
                        for(int i = 1; i < remain/2; i ++)
                            a[0][i] = a[1][i] = '.';
                    }
                    else
                    {
                        a[0][0] = 'c'; a[0][1] = '.';
                        for(int i = 1; i < remain/2; i ++)
                            a[i][0] = a[i][1] = '.';
                    }
                }
            }
            else
            {
                if(remain % 2 == 0 && remain > 2)
                {
                    flag = true;
                    a[0][0] = 'c'; a[0][1] = a[1][0] = a[1][1] = '.';
                    remain -= 4;
                    if(remain < 2*(col-2))
                    {
                        for(int i = 2; i < col && remain > 0; i ++)
                        {
                            a[0][i] = a[1][i] = '.';
                            remain -= 2;
                        }
                    }
                    else
                    {
                        for(int i = 2; i < col; i ++)
                            a[0][i] = a[1][i] = '.';
                        remain -= 2*(col-2);
                        if(remain < 2*(row-2))
                        {
                            for(int i = 2; i < row && remain > 0; i ++)
                            {
                                a[i][0] = a[i][1] = '.';
                                remain -= 2;
                            }
                        }
                        else
                        {
                            for(int i = 2; i < row; i ++)
                                a[i][0] = a[i][1] = '.';
                            remain -= 2*(row-2);
                            int m = 2;
                            while(true)
                            {
                                if(remain == 0)
                                    break;
                                a[m][m] = '.';
                                remain --;
                                for(int i = m; i < col && remain > 0; i ++)
                                {
                                    a[m][i] = '.';
                                    remain --;
                                }
                                if(remain == 0)
                                    break;
                                for(int i = m; i < row && remain > 0; i ++)
                                {
                                    a[i][m] = '.';
                                    remain --;
                                }
                                if(remain == 0)
                                    break;
                                m ++;
                            }
                        }
                    }
                }
                else if(remain > 8)
                {
                    flag = true;
                    remain -= 9;
                    a[0][0] = 'c';
                    a[0][1] = a[0][2] = '.';
                    a[1][0] = a[1][1] = a[1][2] = '.';
                    a[2][0] = a[2][1] = a[2][2] = '.';
                    if(remain < 3*(col-3))
                    {
                        for(int i = 3; i < col && remain > 0; i ++)
                        {
                            a[0][i] = a[1][i] = '.';
                            remain -= 2;
                        }
                        if(remain > 0)
                        {
                            for(int i = 3; i < col && remain > 0; i ++)
                            {
                                a[2][i] = '.';
                                remain -= 1;
                            }
                        }   
                    }
                    else
                    {
                        for(int i = 3; i < col; i ++)
                            a[0][i] = a[1][i] = a[2][i] = '.';
                        remain -= 3*(col-3);
                        if(remain < 3*(row-3))
                        {
                            for(int i = 3; i < row && remain > 0; i ++)
                            {
                                a[i][0] = a[i][1] = '.';
                                remain -= 2;
                            }
                            if(remain > 0)
                            {
                                for(int i = 3; i < row && remain > 0; i ++)
                                {
                                    a[i][2] = '.';
                                    remain -= 1;
                                }
                            }
                        }
                        else
                        {
                            for(int i = 3; i < col; i ++)
                                a[i][0] = a[i][1] = a[i][2] = '.';
                            remain -= 3*(row-3);
                            int m = 3;
                            while(true)
                            {
                                if(remain == 0)
                                    break;
                                a[m][m] = '.';
                                remain --;
                                for(int i = m; i < col && remain > 0; i ++)
                                {
                                    a[m][i] = '.';
                                    remain --;
                                }
                                if(remain == 0)
                                    break;
                                for(int i = m; i < row && remain > 0; i ++)
                                {
                                    a[i][m] = '.';
                                    remain --;
                                }
                                if(remain == 0)
                                    break;
                                m ++;
                            }
                        }
                    }
                }
            }
        }
        
        printf("Case #%d:\n", CASE);
        if(flag)
        {
            for(int i = 0; i < row; i ++)
            {
                for(int j = 0; j < col; j ++)
                {
                    printf("%c", a[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("Impossible\n");
        }
            
    }
    return 0;
}
