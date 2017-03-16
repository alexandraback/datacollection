#include <stdio.h>
#include <string.h>

void solve(int test)
{
    char b[6][6];
    
    int i, j;

    for(i=1; i<=4; i++){
        scanf("%s", b[i]+1);
        if(strlen(b[i]+1) < 4) i--;
    }
    
    
    int winner=0;
    int empty=0;
    int count[3];
    for(i=1; i<=4; i++){
        count[0] = count[1] = count[2] = 0;
        for(j=1; j<=4; j++){
            if(b[i][j] == '.'){
                empty++;
                break;
            }
            if(b[i][j] == 'T')
            {
                count[1]++;
                count[2]++;
            }
            else if(b[i][j] == 'O')
                count[1]++;
            else if(b[i][j] == 'X')
                count[2]++;
        }
        if(j == 5)
        {
            if(count[1] == 4){
                if(winner == 0 || winner == 1)
                    winner = 1;
                else
                    winner = -2;
            }
            if(count[2] == 4){
                if(winner == 0 || winner == 2)
                    winner = 2;
                else
                    winner = -2;
            }
        }
    }
    for(j=1; j<=4; j++){
        count[0] = count[1] = count[2] = 0;
        for(i=1; i<=4; i++){
            if(b[i][j] == '.'){
                empty++;
                break;
            }
            if(b[i][j] == 'T')
            {
                count[1]++;
                count[2]++;
            }
            else if(b[i][j] == 'O')
                count[1]++;
            else if(b[i][j] == 'X')
                count[2]++;
        }
        if(i == 5)
        {
            if(count[1] == 4){
                if(winner == 0 || winner == 1)
                    winner = 1;
                else
                    winner = -2;
            }
            if(count[2] == 4){
                if(winner == 0 || winner == 2)
                    winner = 2;
                else
                    winner = -2;
            }
        }
    }
    count[0] = count[1] = count[2] = 0;
    for(i=1; i<=4; i++){
        if(b[i][i] == '.'){
            empty++;
            break;
        }
        if(b[i][i] == 'T')
        {
            count[1]++;
            count[2]++;
        }
        else if(b[i][i] == 'O')
            count[1]++;
        else if(b[i][i] == 'X')
            count[2]++;
    }
    if(i == 5)
    {
        if(count[1] == 4){
            if(winner == 0 || winner == 1)
                winner = 1;
            else
                winner = -2;
        }
        if(count[2] == 4){
            if(winner == 0 || winner == 2)
                winner = 2;
            else
                winner = -2;
        }
    }
    count[0] = count[1] = count[2] = 0;
    for(i=1; i<=4; i++){
        if(b[i][5-i] == '.'){
            empty++;
            break;
        }
        if(b[i][5-i] == 'T')
        {
            count[1]++;
            count[2]++;
        }
        else if(b[i][5-i] == 'O')
            count[1]++;
        else if(b[i][5-i] == 'X')
            count[2]++;
    }
    if(i == 5)
    {
        if(count[1] == 4){
            if(winner == 0 || winner == 1)
                winner = 1;
            else
                winner = -2;
        }
        if(count[2] == 4){
            if(winner == 0 || winner == 2)
                winner = 2;
            else
                winner = -2;
        }
    }
    
    printf("Case #%d: ", test);
    if(winner == -2 || (winner == 0 && empty == 0))
        printf("Draw\n");
    else if(winner == 0)
        printf("Game has not completed\n");
    else if(winner == 1)
        printf("O won\n");
    else if(winner == 2)
        printf("X won\n");
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    
    int t;
    scanf("%d", &t);

    int i;
    for(i=1; i<=t; i++)
    {
        solve(i);
    }
    
    return 0;
}
