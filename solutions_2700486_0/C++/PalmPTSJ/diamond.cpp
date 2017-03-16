#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
char** genBoard()
{
    char **p = (char**)calloc(sizeof(char*),20); // at 10
    for(int i = 0;i < 20;i++)
        p[i] = (char*)calloc(sizeof(char),20);
    return p;
}

void freeBoard(char** b)
{
    for(int i = 0;i < 20;i++)
        free(b[i]);
    free(b);
}

void printBoard(char **b)
{
    for(int i = 0;i < 20;i++) {
        for(int j = 0;j < 20;j++)
            printf("%c ",b[i][j]);
        printf("\n");
    }
    printf("\n");
}

char** upd(char** board,char way)
{
    char** nB = genBoard();
    // clone
    for(int i = 0;i < 20;i++)
    {
        for(int j = 0;j < 20;j++)
        {
            nB[i][j] = board[i][j];
        }
    }
    // simulate fall
    int x=10,y=19;
    while(true)
    {
        y--;
        // if hit
        if(y==0) break;
        else if((y >= 2 && nB[x][y-2] == 1) || nB[x-1][y-1] == 1 || nB[x+1][y-1] == 1)
        {
            // try to slide
            if(way == 'L') {
                if(nB[x-1][y-1] == 0) x -= 1;
                else if(nB[x+1][y-1] == 0) x += 1;
                else break;
            }

            if(way == 'R') {
                if(nB[x+1][y-1] == 0) x += 1;
                else if(nB[x-1][y-1] == 0) x -= 1;
                else break;
            }
        }
    }
    nB[x][y] = 1;
    //freeBoard(board);
    //printf("TEST");
    return nB;
}

int main()
{
    int t,tt;
    scanf("%d",&tt);
    for(t = 0;t < tt;t++)
    {
        printf("Case #%d: ",t+1);
        int n,x,y;
        scanf("%d %d %d",&n,&x,&y);
        // gen all possibile case
        vector<char**> poss;
        vector<char**> poss2;
        // gen ini map
        char** iMap = genBoard();
        poss.push_back(iMap);
        //printf("TEST");
        int frame = 0;
        double totPoss = 0;
        double totHave = 0;
        if(x > -10 && x < 10 && y < 20) {
        for(int i = 0;i < n;i++)
        {
            //printf("%d\n",i);
            if(frame == 0) {
                for(int j = 0;j < poss.size();j++)
                {
                    //printBoard(poss[j]);
                    //printf("S");
                    poss2.push_back(upd(poss[j],'L'));
                    poss2.push_back(upd(poss[j],'R'));
                    //printf("S");
                    freeBoard(poss[j]);
                }
                poss.clear();
                //printf("1");
            }
            else {
                for(int j = 0;j < poss2.size();j++)
                {
                    //printBoard(poss2[j]);
                    //printf("S");
                    poss.push_back(upd(poss2[j],'L'));
                    poss.push_back(upd(poss2[j],'R'));

                    freeBoard(poss2[j]);
                }
                poss2.clear();
                //printf("2");
            }
            frame = 1 - frame;
        }
        //printf("T");
        if(frame ==0)
        {
            // loop poss
            for(int j = 0;j < poss.size();j++)
            {
                //printBoard(poss[j]);
                if(poss[j][x+10][y] == 1) totHave++;
                totPoss++;
                freeBoard(poss[j]);
            }
        }
        else
        {
            for(int j = 0;j < poss2.size();j++)
            {
                //printBoard(poss2[j]);
                if(poss2[j][x+10][y] == 1) totHave++;
                totPoss++;
                freeBoard(poss2[j]);
            }
        }
        }
        else
        {
            totPoss = 1;
        }
        printf("%lf\n",totHave / totPoss);
    }
}
