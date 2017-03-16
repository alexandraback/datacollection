#include <stdio.h>

int main(void)
{
    int t = 0;
    char board[4][5];

    // t: # of cases
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%s\n", board[j]);
        }
        scanf("\n");

        // determine the status
        bool x_wins = false;
        bool o_wins = false;
        bool full = true;
        for (int x = 0; x < 4 && !x_wins && !o_wins; x++)
        {
            bool x_line = true;
            bool o_line = true;
            for (int y = 0; y < 4; y++)
            {
                x_line = x_line && (board[x][y] == 'X' || board[x][y] == 'T');
                o_line = o_line && (board[x][y] == 'O' || board[x][y] == 'T');
            }
            x_wins = x_wins || x_line;
            o_wins = o_wins || o_line;
        }
        for (int y = 0; y < 4 && !x_wins && !o_wins; y++)
        {
            bool x_line = true;
            bool o_line = true;
            for (int x = 0; x < 4; x++)
            {
                x_line = x_line && (board[x][y] == 'X' || board[x][y] == 'T');
                o_line = o_line && (board[x][y] == 'O' || board[x][y] == 'T');
            }
            x_wins = x_wins || x_line;
            o_wins = o_wins || o_line;
        }
        bool x_line_rd = true;
        bool o_line_rd = true;
        bool x_line_ld = true;
        bool o_line_ld = true;
        for (int d = 0; d < 4; d++)
        {
            x_line_rd = x_line_rd && (board[d][d] == 'X' || board[d][d] == 'T');
            o_line_rd = o_line_rd && (board[d][d] == 'O' || board[d][d] == 'T');
            x_line_ld = x_line_ld && (board[d][3 - d] == 'X' || board[d][3 - d] == 'T');
            o_line_ld = o_line_ld && (board[d][3 - d] == 'O' || board[d][3 - d] == 'T');
        }
        x_wins = x_wins || x_line_rd || x_line_ld;
        o_wins = o_wins || o_line_rd || o_line_ld;
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                full = full && (board[x][y] != '.');
            }
        }

        // output
        printf("Case #%d: %s\n", i + 1, x_wins ? "X won" : o_wins ? "O won" : full ? "Draw" : "Game has not completed");
    }

    return 0;
}
