#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAX_SIZE 50
#define ONLINE
int board[MAX_SIZE][MAX_SIZE];

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


bool simpleCheckPossible(int R, int C, int M)
{
    if(R*C-M==1||M==0)
    {
        return true;
    }
    else
    if(R==1&&C==1)//1X1
    {
        if(M==0)
            return true;
        else
            return false;
    }
    else
    if(R==1)//1XN
    {
        //C
        const int e = C-M;
        if(e>=2)
            return true;
        else
            return false;
    }
    else
    if(C==1)//NX1
    {
        //R
        const int e = R-M;
        if(e>=2)
            return true;
        else
            return false;
    }
    else
    if(R==2&&C==2)//2X2
    {
        if(M==0)
            return true;
        else
            return false;
    }
    else
    if(R==2||C==2)
    {
        if(M%2==1|| (R*C-M)<4)
            return false;
        else
            return true;
    }
    else//NXN
    {
        const int e = R*C-M;
        if(e>=4)
            return true;
        else
            return false;
    }

}

void initBoard(int R, int C)
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
            board[i][j]='.';
        }
}
void initBoardStar(int R, int C)
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
            board[i][j]='*';
        }
}
void computeMethod1(int R, int C, int M)
{
    int e = R*C-M;
    //e>=4
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            board[i][j]='.';

    board[0][0]='c';
    e=e-4;

    int square=2;

    while(square<R || square<C)
    {
        //rows, col index

        if(square <R)
            for(int j=0; j<square&&j<C; j++)
            {
                if(e>0)
                {
                    board[square][j]='.';
                    e--;
                    //printf("%d %d %d\n",e,square,j);
                }
                else
                {
                    board[square][j]='*';
                }

            }
        //cols

        if(square <C)
            for(int i=0;i<square&&i<R;i++)
            {
                if(e>0)
                {
                    board[i][square]='.';
                    e--;
                    //printf("%d %d %d\n",e,i,square);
                }
                else
                {
                    board[i][square]='*';
                }
            }
        if(square<C&&square<R)
        {
            if(e>0)
            {
                board[square][square]='.';
                e--;
                    //printf("%d %d %d\n",e,i,square);
            }
            else
            {
                board[square][square]='*';
            }
        }
        square++;
    }

}


int pointBoard[MAX_SIZE][MAX_SIZE];

int updateNeighborsPoint(int R, int C, int i, int j)
{
    for(int dx=-1; dx<2; dx++)
        for(int dy=-1; dy<2; dy++)
        {
            if(dx==0&&dy==0)
                continue;

            int nx = i+dx;
            int ny = j+dy;

            if(nx>=0&&nx<R&&ny>=0&&ny<C)
                pointBoard[nx][ny]++;

        }
}

int computePoints(int R, int C)
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
            //fill zero
            pointBoard[i][j] = 0;
        }

    //fill point to other
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
        {
            if(board[i][j]=='*')
                updateNeighborsPoint(R,C,i,j);
        }
}

struct Point
{
    int x;
    int y;
}coordinates[MAX_SIZE*MAX_SIZE];

bool used[MAX_SIZE][MAX_SIZE];
void clearUsed(int R, int C)
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            used[i][j] = false;
}
int waterFill(int R, int C, int cx, int cy)
{
    Point p;
    p.x = cx;
    p.y = cy;
    coordinates[0] = p;

    clearUsed(R,C);
    used[cx][cy] = true;

    int first = 0, top = 1;//first read,  top write
    while(first<top)
    {
        Point nowP = coordinates[first];

        if(pointBoard[nowP.x][nowP.y]==0)
            for(int dx=-1; dx<2; dx++)
                for(int dy=-1; dy<2; dy++)
                {
                    if(dx==0&&dy==0)
                        continue;

                    int nx = nowP.x+dx;
                    int ny = nowP.y+dy;

                    if(nx>=0&&nx<R&&ny>=0&&ny<C)
                    {
                        if(!used[nx][ny]&&board[nx][ny]=='.')
                        {
                            used[nx][ny] = true;

                            Point flip;
                            flip.x = nx;
                            flip.y = ny;

                            coordinates[top++] = flip;
                        }
                    }

                }
        first++;
    }
    return top;
}

bool checkBoardOneClick(int R, int C, int M)//simulation play
{
    //search 'c'
    int click_x, click_y;
    for(int i=0; i<R; i++)// find c
        for(int j=0; j<C; j++)
        {
            if(board[i][j]=='c')
            {
                click_x = i;
                click_y = j;
                break;
            }
        }

    computePoints(R, C);

    //water fill

    int traveled = waterFill(R, C, click_x, click_y);
    if(R*C-M==traveled)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool showPointBoard(int R, int C)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(board[i][j]!='.')
                putchar(board[i][j]);
            else
                printf("%d",pointBoard[i][j]);
        }
        printf("\n");
    }
}



bool computeGameBoard(int R,int C, int M)
{
    if(M==0)
    {
        initBoard(R,C);
        board[0][0]='c';
        return true;
    }
    if(R*C-M==1)
    {
        initBoardStar(R,C);
        board[0][0]='c';
        return true;
    }

    if(R==1&&C==1)//1X1
    {
        board[0][0]='c';
    }
    else
    if(R==1)//1XN
    {
        //C
        int e = C-M;
        //e>=2
        board[0][0]='c';
        e--;
        int i;
        for(i=1; i<C; i++)
        {
            if(e>0)
            {
                board[0][i]='.';
                e--;
            }
            else
            {
                board[0][i]='*';
            }
        }

    }
    else
    if(C==1)//NX1
    {
        //R
        int e = R-M;
        //(e>=2)
        board[0][0]='c';
        e--;
        int i;
        for(i=1; i<R; i++)
        {
            if(e>0)
            {
                board[i][0]='.';
                e--;
            }
            else
            {
                board[i][0]='*';
            }
        }
    }
    else
    if(R==2&&C==2)//2X2
    {
        //M==0
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                board[i][j] = '.';
        board[0][0] = 'c';
    }
    else
    if(R==2)
    {
        int e = R*C-M;
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                board[i][j] = '.';
        board[0][0] = 'c';
        e-=4;
        for(int j=2; j<C; j++)
        {
            for(int i=0; i<R; i++)
            {
                if(e>0)
                {
                    board[i][j]='.';
                    e--;
                }
                else
                {
                    board[i][j]='*';
                }
            }
        }
    }
    else
    if(C==2)
    {
        int e = R*C-M;
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                board[i][j] = '.';
        board[0][0] = 'c';
        e-=4;
        for(int i=2; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(e>0)
                {
                    board[i][j]='.';
                    e--;
                }
                else
                {
                    board[i][j]='*';
                }
            }
        }
    }
    else//NXN
    //if(R>2&&C>2)
    {
        computeMethod1(R,C,M);
    }


    //simulate play
    bool simuplay = checkBoardOneClick(R,C, M);
    //check

    #ifndef ONLINE
    showPointBoard(R,C);
    if(simuplay)
    {
        printf("good\n");
    }
    else
    {
        printf("not god\n");
    }
    #endif
    //use method 2
    if(!simuplay)
    {
        if(R*C==5)
            return false;
        if(R*C==7)
            return false;
    }

    int r_t = R*C*10000;
    while(!simuplay&&r_t)
    {
        //random change last col and last row

        int row = rand()%R;
        int col = rand()%C;

        swap(&board[row][C-1], &board[R-1][col]);
        simuplay = checkBoardOneClick(R,C, M);
        r_t--;
    }
    //last two rows
    for(int Drange = 2; Drange<R&&Drange<C&&!simuplay; Drange++)
    {


        r_t = R*C*10000;
        while(!simuplay&&r_t)
        {
            //random change last col and last row

            int row = rand()%R;
            int dc =rand()%Drange%C;

            int col = rand()%C;
            int d = rand()%Drange%R;

            swap(&board[row][C-1-dc], &board[R-1-d][col]);
            simuplay = checkBoardOneClick(R,C, M);
            r_t--;
        }
    }
    r_t = 150000*2;
    while(!simuplay&&r_t)
    {

        int a, b, c, d;
        a = rand()%R;
        b = rand()%C;
        c = rand()%R;
        d = rand()%C;

        swap(&board[a][b], &board[c][d]);
        simuplay = checkBoardOneClick(R,C, M);
        r_t--;
    }


    //check


    //use random method

    //check

    return simuplay;
}

void outputGameBoard(int R,int C)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
            putchar(board[i][j]);
        printf("\n");
    }
}


int main()
{
    int T=0;
    srand(577);
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        int R,C,M;
        scanf("%d %d %d",&R,&C,&M);
        printf("Case #%d:\n",i+1);
        if(simpleCheckPossible(R,C,M))
        {
            bool test = computeGameBoard(R,C,M);

            if(test)
                outputGameBoard(R,C);
            else
                printf("Impossible\n");
        }
        else
        {
            printf("Impossible\n");
        }
    }

}
