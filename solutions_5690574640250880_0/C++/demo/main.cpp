#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N=20;
int r,c,m,n;//n=r*c
bool ismine[N][N];
int neibor[N][N];
bool v[N][N];
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int sx,sy;
bool isIn(int x,int y)
{
    return x>=0&&x<r&&y>=0&&y<c;
}

void fillBoard()
{
    memset(neibor,-1,sizeof(neibor));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
    {
        if(ismine[i][j]) continue;
        int neibors=0;
        for(int k=0;k<8;k++)
        {
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(isIn(x,y)&&ismine[x][y])
                neibors++;
        }
        neibor[i][j]=neibors;

    }
}

void walk(int x,int y)
{
    if(v[x][y]) return ;
    v[x][y]=true;
    if(neibor[x][y]==0)
    {
        for(int k=0;k<8;k++)
        {
            int tx=x+dir[k][0];
            int ty=y+dir[k][1];
            if(isIn(tx,ty)&&neibor[tx][ty]!=-1)
                walk(tx,ty);
        }
    }
}

bool canOneClick()
{
    sx=sy=-1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
    {
        if(neibor[i][j]>=0&&sx==-1)
        {
            sx=i;
            sy=j;
        }
        if(neibor[i][j]==0)
        {
            sx=i;
            sy=j;
        }
    }
    memset(v,false,sizeof(v));
    if(sx!=-1)
      walk(sx,sy);
    int nClear=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(v[i][j]) nClear++;
    return nClear+m==n;
}

void printSolution()
{
    char op[N][N];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(neibor[i][j]==-1) op[i][j]='*';
            else op[i][j]='.';
        }
        op[i][c]='\0';
    }
    if(sx!=-1) op[sx][sy]='c';
    for(int i=0;i<r;i++) printf("%s\n",op[i]);
}



bool succeed;
void generateMines(int step,int minesleft)
{
    if(succeed) return ;
    if(n-step<minesleft) return ;
    if(step==n)
    {
        if(minesleft) return ;
        fillBoard();
        if(canOneClick())
        {
            printSolution();
            succeed=true;
        }
        return ;
    }
    int x=step/c,y=step%c;
    if(minesleft)
    {
        ismine[x][y]=true;
        generateMines(step+1,minesleft-1);
        ismine[x][y]=false;
    }
    generateMines(step+1,minesleft);
}


int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int t;
    scanf("%d",&t);
    int cs=0;
    while(t--)
    {
        scanf("%d%d%d",&r,&c,&m);
        n=r*c;
        printf("Case #%d:\n",++cs);
        succeed=false;
        generateMines(0,m);
        if(!succeed) printf("Impossible\n");
    }
    return 0;
}











