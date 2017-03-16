#include <iostream>
#include <cstdio>
using namespace std;

char board[6][6];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int numx,numy,numt;
    int xwin,ywin,draw,end;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        for(int i=0;i<4;i++)
        scanf("%s",board[i]);

        xwin=ywin=draw=0;
        end=1;
        //hang
        for(int i=0;i<4;i++)
        {
            numx=numy=numt=0;
            for(int j=0;j<4;j++)
            {
                if(board[i][j]=='X') numx++;
                if(board[i][j]=='O') numy++;
                if(board[i][j]=='T') numt++;
                if(board[i][j]=='.') end=0;
            }
            if(numx==4||(numx==3&&numt==1)) xwin=1;
            if(numy==4||(numy==3&&numt==1)) ywin=1;
        }

        //lie
        for(int i=0;i<4;i++)
        {
            numx=numy=numt=0;
            for(int j=0;j<4;j++)
            {
                if(board[j][i]=='X') numx++;
                if(board[j][i]=='O') numy++;
                if(board[j][i]=='T') numt++;
                if(board[j][i]=='.') end=0;
            }
            if(numx==4||(numx==3&&numt==1)) xwin=1;
            if(numy==4||(numy==3&&numt==1)) ywin=1;
        }

        //xie
            numx=numy=numt=0;
            for(int i=0;i<4;i++)
            {
                if(board[i][i]=='X') numx++;
                if(board[i][i]=='O') numy++;
                if(board[i][i]=='T') numt++;
                if(board[i][i]=='.') end=0;
            }
            if(numx==4||(numx==3&&numt==1)) xwin=1;
            if(numy==4||(numy==3&&numt==1)) ywin=1;

            numx=numy=numt=0;
            for(int i=0;i<4;i++)
            {
                if(board[i][3-i]=='X') numx++;
                if(board[i][3-i]=='O') numy++;
                if(board[i][3-i]=='T') numt++;
                if(board[i][3-i]=='.') end=0;
            }
            if(numx==4||(numx==3&&numt==1)) xwin=1;
            if(numy==4||(numy==3&&numt==1)) ywin=1;

            if(xwin==1)
            {
                printf("Case #%d: X won\n",cas);
            }
            else if(ywin==1)
            {
                printf("Case #%d: O won\n",cas);
            }
            else if(end==0)
            {
                printf("Case #%d: Game has not completed\n",cas);
            }
            else
            {
                printf("Case #%d: Draw\n",cas);
            }

    }
    return 0;
}
