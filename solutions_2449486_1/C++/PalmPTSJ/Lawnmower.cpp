#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t=0;t < tt;t++)
    {
        // get board size
        int R,C;
        scanf("%d %d",&R,&C);
        int board[R][C];
        bool boardLock[R][C];
        for(int i = 0; i < R;i++) {
            for(int j = 0;j < C;j++) {
                boardLock[i][j] = false;
                scanf("%d",&board[i][j]);
            }
        }
        // check
        bool ans = true;

        for(int h = 100 ;h > 0;h--)
        {
            bool boardCut[R][C];
            for(int i = 0; i < R;i++) {
                for(int j = 0;j < C;j++) {
                    boardCut[i][j] = false;
                }
            }

            // try to cut the lawn from every side without lock
            for(int i = 0; i < R;i++)
            {
                // try cut , check lock first
                bool canCut = true;
                for(int j = 0;j < C;j++)
                {
                    if(boardLock[i][j])
                    {
                        canCut = false;
                        break;
                    }
                }
                if(!canCut) continue;
                // cut
                for(int j = 0;j < C;j++)
                    boardCut[i][j] = true;
            }

            for(int i = 0; i < C;i++)
            {
                // try cut , check lock first
                bool canCut = true;
                for(int j = 0;j < R;j++)
                {
                    if(boardLock[j][i])
                    {
                        canCut = false;
                        break;
                    }
                }
                if(!canCut) continue;
                // cut
                for(int j = 0;j < R;j++)
                    boardCut[j][i] = true;
            }

            // CHECK IF ALL CAN CUT && LOCK BOARD
            for(int i = 0; i < R;i++) {
                for(int j = 0;j < C;j++) {
                    if(boardCut[i][j] == false && boardLock[i][j] == false)
                    {
                        ans = false;
                        break;
                    }
                    else if(board[i][j] == h) {
                        boardLock[i][j] = true;
                    }
                }
                if(!ans)break;
            }
            if(!ans)break;
        }

        if(!ans) printf("Case #%d: NO\n",t+1);
        else printf("Case #%d: YES\n",t+1);


    }
}
