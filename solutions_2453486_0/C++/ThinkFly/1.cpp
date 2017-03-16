#include <stdio.h>
#include <iostream>

using namespace std;

void solve_one(int n_case)
{
    char tmp[5][50];
    for (int i=0; i<4; i++)
        scanf(" %s", tmp[i]);
    bool is_over = true;
    bool X_won = true, O_won = true;
    for (int i=0; i<4; i++)
    {
        X_won = true, O_won = true;
        for (int j=0; j<4; j++)
        {
            switch (tmp[i][j])
            {
            case 'X':
                O_won = false;
                break;
            case 'O':
                X_won = false;
                break;
            case 'T':
                break;
            case '.':
                O_won = false;
                X_won = false;
                is_over = false;
                break;
            }
        }
        if (X_won)
        {
            printf("Case #%d: X won\n", n_case);
            return;
        }
        else if(O_won)
        {
            printf("Case #%d: O won\n", n_case);
            return;
        }
    }
    for (int i=0; i<4; i++)
    {
        X_won = true, O_won = true;
        for (int j=0; j<4; j++)
        {
            switch (tmp[j][i])
            {
            case 'X':
                O_won = false;
                break;
            case 'O':
                X_won = false;
                break;
            case '.':
                O_won = false;
                X_won = false;
            }
        }
        if (X_won)
        {
            printf("Case #%d: X won\n", n_case);
            return;
        }
        else if(O_won)
        {
            printf("Case #%d: O won\n", n_case);
            return;
        }
    }
    X_won = true, O_won = true;
    for (int i=0; i<4; i++)
    {
        switch (tmp[i][i])
        {
        case 'X':
            O_won = false;
            break;
        case 'O':
            X_won = false;
            break;
        case '.':
            O_won = false;
            X_won = false;
        }
    }
    if (X_won)
    {
        printf("Case #%d: X won\n", n_case);
        return;
    }
    else if(O_won)
    {
        printf("Case #%d: O won\n", n_case);
        return;
    }
    X_won = true, O_won = true;
    for (int i=0; i<4; i++)
    {
        switch (tmp[3-i][i])
        {
        case 'X':
            O_won = false;
            break;
        case 'O':
            X_won = false;
            break;
        case '.':
            O_won = false;
            X_won = false;
        }

    }
    if (X_won)
    {
        printf("Case #%d: X won\n", n_case);
        return;
    }
    else if(O_won)
    {
        printf("Case #%d: O won\n", n_case);
        return;
    }
    else if (is_over)
    {
        printf("Case #%d: Draw\n", n_case);
        return;
    }
    else
    {
        printf("Case #%d: Game has not completed\n", n_case);
        return;
    }
}
int main()
{
    //freopen("D:\\1.txt", "r", stdin);
    //freopen("D:\\1_ans.txt", "w+", stdout);
    int count;
    scanf("%d", &count);
    for (int i=1; i<=count; i++)
    {
        solve_one(i);
    }
    return 0;
}