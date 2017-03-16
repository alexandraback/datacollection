/**************************************
Author  : Htedsv
Time    :六  4/13 09:17:43 2013
FileName:A.cpp
Desc    :
*************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int T, row[4], col[4]; char s[10];

int main()
{
    scanf("%d", &T );
    for ( int I = 0; I < T; ++I )
    {
        memset( row, 0, sizeof(row));
        memset( col, 0, sizeof(col));
        bool finished = true;
        int t_row = -1, t_col = -2, left = 0, right = 0;
        for ( int i = 0; i < 4; ++i )
        {
            scanf("%s", s);
            for ( int j = 0; j < 4; ++j )
            {
                if (s[j] == '.' ) finished= false;
                if (s[j] == 'T' ) 
                {
                    t_row = i;
                    t_col = j;
                }
                if (s[j] == 'X')
                {
                    row[i]++;
                    col[j]++;
                    if (i == j) left++;
                    if (i+j == 3) right++;
                }
                if (s[j] == 'O')
                {
                    row[i]--;
                    col[j]--;
                    if (i == j) left--;
                    if (i+j == 3) right--;
                }
            }
        }
        bool sign = false;
        for ( int i = 0; i < 4; ++i )
        {
            if (row[i] == 4 || col[i] == 4 || (row[i] == 3 && t_row == i) || (col[i] == 3 && t_col == i ))
            { printf( "Case #%d: X won\n", I+1); sign = true; break;}
        }
        if (sign) continue;
        for ( int i = 0; i < 4; ++i )
        {
            if (row[i] == -4 || col[i] == -4 || (row[i] == -3 && t_row == i) || (col[i] == -3 && t_col == i ))
            { printf( "Case #%d: O won\n", I+1); sign = true; break;}
        }
        if (sign) continue;
        
        if ((left == 4 || (left == 3 && t_col == t_row)) || (right == 4 || (right == 3 && t_col+t_row == 3)))
            { printf( "Case #%d: X won\n", I+1); continue; }
        if ( (left == -4 || (left == -3 && t_col == t_row)) || (right == -4 || (right == -3 && t_col+t_row == 3)))
            { printf( "Case #%d: O won\n", I+1);continue;}
        if ( finished )
            printf( "Case #%d: Draw\n", I+1);
        else 
            printf( "Case #%d: Game has not completed\n", I+1);
    }
}
