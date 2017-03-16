#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>

using namespace std;
int posx[9]={-1 ,-1, -1,0,0,0,1,1,1 };
int posy[9]={-1,0,1,-1,1,0,-1,0,1};
int ansBoard[50][50];

bool isValidPos(pair<int,int> loc,int board[50][50],int rows,int cols)
{
    if(loc.first<0 || loc.second<0 || loc.first>=rows ||loc.second>=cols)
        return false;
    if(board[loc.first][loc.second])
        return false;
    return true;
}

bool isValidPos1(pair<int,int> loc,int board[50][50],int rows,int cols)
{
    if(loc.first<0 || loc.second<0 || loc.first>=rows ||loc.second>=cols)
        return false;
    if(board[loc.first][loc.second]==1)
        return true;
    return false;
}

int Rec1(int board[50][50],pair<int,int> loc,int rows,int cols,int not_mines,int zeros)
{
    if(!isValidPos1(loc,board,rows,cols))
        return -1;
    int zerosTemp=0;
    board[loc.first][loc.second]=2;
    /*for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<board[i][j]<<' ';
        cout<<endl;
    }*/
    for(int i=0;i<9;i++)
    {
        pair<int,int> locTemp(loc.first+posx[i],loc.second+posy[i]);
        if(isValidPos(locTemp,board,rows,cols)){
            zerosTemp++;
            board[locTemp.first][locTemp.second]=1;
        }
    }
   /* cout<<"After Processing :"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<board[i][j]<<' ';
        cout<<endl;
    }*/
    if(zeros+zerosTemp>not_mines)
        return -1;
    if(zeros+zerosTemp==not_mines){
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                ansBoard[i][j]=board[i][j];
        return not_mines;
    }
    //cout<<"Zeros Temp :"<<zeros+zerosTemp<<endl;
    int num=-1;
    for(int i=0;i<9;i++)
    {
        int boardTemp[50][50];
        memset(boardTemp,0,sizeof(boardTemp));
        for(int i1=0;i1<rows;i1++)
        {
            for(int j1=0;j1<cols;j1++)
                boardTemp[i1][j1]=board[i1][j1];
        }
        pair<int,int> locTemp(loc.first+posx[i],loc.second+posy[i]);
        num=Rec1(boardTemp,locTemp,rows,cols,not_mines,zeros+zerosTemp);
        if(num==not_mines)
            return num;
    }
    return -1;
}


int main()
{
    int T;
    cin>>T;
    int I=0;
    int board[50][50];
    while(T--)
    {
        I++;
        int R,C,M,K;
        cin>>R>>C>>M;
       // cout<<"MAT :"<<R<<' '<<C<<' '<<M<<endl;
        K=R*C-M;
        pair<int,int> startPos;
      //  memset(board,0,sizeof(board));
        memset(ansBoard,0,sizeof(ansBoard));
        bool solFound=false;
        if(K==1)
        {
            solFound=true;
            startPos.first=0;
            startPos.second=0;
        }
        else{
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
         //       cout<<"For Location : "<<i<<' '<<j<<endl;
                memset(board,0,sizeof(board));
                pair<int,int> loc(i,j);
                board[i][j]=1;
                if(Rec1(board,loc,R,C,K,1)!=-1)
                    {
                        startPos.first=i;
                        startPos.second=j;
                        solFound=true;
                        break;
                    }
            }
            if(solFound)
                break;
        }
        }
        cout<<"Case #"<<I<<':'<<endl;
        if(solFound){
            for(int i=0;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    if(i==startPos.first && j==startPos.second)
                        cout<<'c';
                    else if(ansBoard[i][j]==0)
                        cout<<'*';
                    else
                        cout<<'.';
                }
                cout<<endl;
            }
        }
        else
            cout<<"Impossible"<<endl;
    }
}

