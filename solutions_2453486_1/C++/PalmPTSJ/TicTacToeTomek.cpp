#include <stdio.h>
#include <stdlib.h>

char checkWinStatus(char b[4])
{
    char startC = b[0]=='T'?b[1]:b[0];
    //printf("CHECK %s\n",b);
    for(int i = 0;i < 4;i++)
    {
        if(b[i] == '.') return 'N';
        if(b[i] != 'T' && b[i] != startC) // Other player
            return 'D';
    }
    return startC;
}

void printAns(int caseN,char stat)
{
    printf("Case #%d: ",caseN);
    switch(stat)
    {
        case 'O' :
            printf("O won");
            break;
        case 'X' :
            printf("X won");
            break;
        case 'N' :
            printf("Game has not completed");
            break;
        case 'D' :
            printf("Draw");
            break;
    }
    printf("\n");
}

int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t=0;t < tt;t++)
    {
        char board[4][4];
        for(int i = 0;i < 4;i++)
        {
            for(int j =0 ;j < 4;j++)
            {
                char c = '\n';
                while(c == '\n')
                    scanf("%c",&c);
                board[i][j] = c;
            }
        }
        bool isBoardComplete = true;
        /*
        N = Not Completed yet
        D = Draw
        O = O wins
        X = X wins
        */
        char state;
        // column & row
        for(int i = 0;i < 4;i++)
        {
            char row[4];
            for(int j = 0;j < 4;j++)
                row[j] = board[i][j];
            state = checkWinStatus(row);
            if(state == 'N') isBoardComplete = false;
            if(state == 'O' || state == 'X' ) break;
            char col[4];
            for(int j = 0;j < 4;j++)
                col[j] = board[j][i];
            state = checkWinStatus(col);
            if(state == 'O' || state == 'X' ) break;
        }
        if(state == 'O' || state=='X')
        {
            printAns(t+1,state);
            continue;
        }

        // diag
        char diag1[4];
        char diag2[4];
        for(int i = 0;i < 4;i++)
        {
            diag1[i] = board[i][i];
            diag2[i] = board[i][3-i];
        }

        state = checkWinStatus(diag1);
        if(state == 'O' || state=='X')
        {
            printAns(t+1,state);
            continue;
        }

        state = checkWinStatus(diag2);
        if(state == 'O' || state=='X')
        {
            printAns(t+1,state);
            continue;
        }

        if(isBoardComplete) printAns(t+1,'D');
        else printAns(t+1,'N');
    }
}
