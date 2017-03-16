#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

string board[4];
char p[2]={'X','O'};

int row(int i)
{
    int j,k;

    for(k=0;k<2;k++)
    {
        for(j=0;j<4;j++)
        {
            if(board[i][j]==p[k] || board[i][j]=='T') continue;
            break;
        }

        if(j==4) return k+1;
    }

    return 0;
}

int col(int j)
{
    int i,k;

    for(k=0;k<2;k++)
    {
        for(i=0;i<4;i++)
        {
            if(board[i][j]==p[k] || board[i][j]=='T') continue;
            break;
        }

        if(i==4) return k+1;
    }

    return 0;
}

int diag()
{
    int i,j,k,a;

    for(i=k=0;k<2;k++)
    {
        for(a=0;a<4;a++)
        {
            if(board[i+a][i+a]==p[k] || board[i+a][i+a]=='T') continue;
            break;
        }

        if(a==4) return k+1;
    }

    for(i=0,j=3,k=0;k<2;k++)
    {
        for(a=0;a<4;a++)
        {
            if(board[i+a][j-a]==p[k] || board[i+a][j-a]=='T') continue;
            break;
        }

        if(a==4) return k+1;
    }

    return 0;
}

bool dot()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++) if(board[i][j]=='.') return 1;
    }

    return 0;
}

int main()
{
    int i,j,k,T,t,r;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("tic-out-small.txt","w",stdout);

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        r=0;
        for(i=0;i<4;i++) cin>>board[i];

        for(i=0;i<4 && r==0;i++) r=row(i);

        for(i=0;i<4 && r==0;i++) r=col(i);

        for(i=0;i<4 && r==0;i++) r=diag();

        printf("Case #%d: ",t);

        if(r)   printf("%s won\n",r==1 ?"X" : "O");


        else
        {
            if(dot()) printf("Game has not completed\n");

            else printf("Draw\n");
        }
    }

    return 0;
}
