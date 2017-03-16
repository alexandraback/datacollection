#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

char board[10][10],laji[10];
int main()
{
    int cas,t=1;
    bool flag,win;
    char winner,shit;

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&cas);
    while (cas--)
    {
        win=false;
        if(t!=1)
           gets(laji);
        for (int i=0;i<4;i++)
            scanf("%s",board[i]);
        for (int i=0;i<4;i++)
        {
            flag=true;
            if(board[i][0]=='.')
               continue;
            if(board[i][0]=='T')
               shit=board[i][1];
            else
               shit=board[i][0];
            for (int j=1;j<4;j++)
            {
                if(board[i][j]=='.')
                {
                    flag=false;
                    break;
                }
                if (board[i][j]==shit||board[i][j]=='T')
                    continue;
                else
                {
                    flag=false;
                    break;
                }
            }
            if (flag)
            {
                win=true;
                winner=shit;
            }
        }
        if (!win)
        {
            for (int i=0;i<4;i++)
            {
                if(board[0][i]=='.')
                   continue;
                if(board[0][i]=='T')
                   shit=board[1][i];
                else
                   shit=board[0][i];
                flag=true;
                for (int j=1;j<4;j++)
                {
                    if(board[j][i]=='.')
                    {
                        flag=false;
                        break;
                    }
                    if (board[j][i]==shit||board[j][i]=='T')
                        continue;
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if (flag)
                {
                    win=true;
                    winner=shit;
                    break;
                }
            }
        }
        if(!win)
        {
            flag=true;
            if(board[0][0]=='.')
            {
                flag=false;
            }
            if(board[0][0]=='T')
               shit=board[1][1];
            else
               shit=board[0][0];
            for(int i=1;flag&&i<4;i++)
            {
                if(board[i][i]=='.')
                {
                    flag=false;
                    break;
                }
                if(board[i][i]==shit||board[i][i]=='T')
                   continue;
                else
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                win=true;
                winner=shit;
            }
        }
        if(!win)
        {
            flag=true;
            if(board[0][3]=='.')
            {
                flag=false;
            }
            if(board[0][3]=='T')
               shit=board[1][2];
            else
               shit=board[0][3];
            for(int i=1;flag&&i<4;i++)
            {
                if(board[i][3-i]=='.')
                {
                    flag=false;
                    break;
                }
                if(board[i][3-i]==shit||board[i][3-i]=='T')
                   continue;
                else
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                win=true;
                winner=shit;
            }
        }
        if(win)
        {
            printf("Case #%d: %c won\n",t++,winner);
        }
        else
        {
            flag=false;
            for(int i=0;i<4&&!flag;i++)
               for(int j=0;j<4;j++)
               {
                   if(board[i][j]=='.')
                   {
                       flag=true;
                       break;
                   }
               }
            if(flag)
               printf("Case #%d: Game has not completed\n",t++);
            else
               printf("Case #%d: Draw\n",t++);
        }
    }
    return 0;
}
