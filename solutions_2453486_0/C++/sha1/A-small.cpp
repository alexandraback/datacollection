#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
#define sz 10

char board[sz][sz];

bool checkboard(char ch)
{
    int i,j,k;
    bool flag=true;
    //row check
    for(i=0;i<4;i++)
    {
        flag=true;
        for(j=0;j<4;j++)
        {
            if(board[i][j]!=ch && board[i][j]!='T')
            {
                flag=false;
                break;
            }
        }
        if(flag==true)  return true;
    }
    //column check
    for(i=0;i<4;i++)
    {
        flag=true;
        for(j=0;j<4;j++)
        {
            if(board[j][i]!=ch && board[j][i]!='T')
            {
                flag=false;
                break;
            }
        }
        if(flag==true)  return true;
    }

    //right diagonal
    flag=true;
    for(i=0,j=3;i<4;i++,j--)
    {
        if(board[i][j]!=ch && board[i][j]!='T')
        {
            flag=false;
            break;
        }
    }
    if(flag==true)  return true;

    //left diagonal
    flag=true;
    for(j=3;j>=0;j--)
    {
        if(board[j][j]!=ch && board[j][j]!='T')
        {
            flag=false;
            break;
        }
    }
    if(flag==true)  return true;

    return false;
}

bool checkempty()
{
    int i,j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(board[i][j]=='.')
                return true;
        }
    }

    return false;
}

int main()
{
    int i,j,k,num,t,test;


    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);

    scanf("%d",&test);

    for(t=1;t<=test;t++)
    {
        for(i=0;i<4;i++)
        {
            scanf("%s",board[i]);
        }

        printf("Case #%d: ",t);

        if(checkboard('X'))
            printf("X won");
        else if(checkboard('O'))
            printf("O won");
        else if(checkempty())
            printf("Game has not completed");
        else
            printf("Draw");
        puts("");


    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
