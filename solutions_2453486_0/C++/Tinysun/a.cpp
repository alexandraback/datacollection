
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64_t;

char trans[26] = { 
'y', 'h', 'e', 's', 'o',
'c', 'v', 'x', 'd', 'u',
'i', 'g', 'l', 'b', 'k',
'r', 'z', 't', 'n', 'w',
'j', 'p', 'f', 'm', 'a', 
'q' };

// int _tmain(int argc, _TCHAR* argv[])

char conv(char c)
{
	if ( c == ' ')
		return c;
	return  trans[c - 'a'];
}

char board[4][10];

bool CheckWin(char player)
{
    // vertical
    for(int c=0; c<4; c++)
    {
        if ((board[0][c] == 'T' || board[0][c] == player) &&
            (board[1][c] == 'T' || board[1][c] == player) &&
            (board[2][c] == 'T' || board[2][c] == player) &&
            (board[3][c] == 'T' || board[3][c] == player))
            return true;
    }
    
    // horizental
    for(int r=0; r<4; r++)
    {
        if ((board[r][0] == 'T' || board[r][0] == player) &&
            (board[r][1] == 'T' || board[r][1] == player) &&
            (board[r][2] == 'T' || board[r][2] == player) &&
            (board[r][3] == 'T' || board[r][3] == player))
            return true;
    }
    
    // diagonal
    if ((board[0][0] == 'T' || board[0][0] == player) &&
        (board[1][1] == 'T' || board[1][1] == player) &&
        (board[2][2] == 'T' || board[2][2] == player) &&
        (board[3][3] == 'T' || board[3][3] == player))
        return true;

    if ((board[3][0] == 'T' || board[3][0] == player) &&
        (board[2][1] == 'T' || board[2][1] == player) &&
        (board[1][2] == 'T' || board[1][2] == player) &&
        (board[0][3] == 'T' || board[0][3] == player))
        return true;
    
    return false;
}

bool CheckFill()
{
    for(int r=0; r<4; r++)
        for(int c=0; c<4; c++)
            if (board[r][c] == '.')
                return false;
    return true;
}

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
 
		for(int j=0; j<4; j++)
            fgets(board[j], 10, stdin);
        fgets(buf, 1024, stdin);

        const char *res = "";
        // check win
        if (CheckWin('O'))
            res = "O won";
        else if (CheckWin('X'))
            res = "X won";
        else if (CheckFill())
            res = "Draw";
        else
            res = "Game has not completed";
            
        
		printf("Case #%d: %s", i, res);

		printf("\n");
	}
  
	return  0;  
}
