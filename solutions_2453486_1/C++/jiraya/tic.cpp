#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<queue>
#include<cstdlib>

using namespace std;

#define LL long long
#define REP(i,a,b) for(int i = a;i<b;i++)
#define REP0(i,b) REP(i,0,b)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)

char BOARD[5][5];


void PRINT(char won,char wonby,int cases)
{
    if(won == 'X')
        printf("Case #%d: X won\n",cases+1);
    else if(won == 'O')
        printf("Case #%d: O won\n",cases+1);
    else if(won == 'i')
        printf("Case #%d: Game has not completed\n",cases+1);
    else if(won =='d')
        printf("Case #%d: Draw\n",cases+1);
}


void GETIN()
{
    REP0(i,4)
    scanf("%s",BOARD[i]);
    getchar();;
    //getchar();

}



int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("test.out","w",stdout);
    int CASES,TEST_CASES = 0;
    scanf("%d",&CASES);
   // printf("%d",CASES);
    getchar();
    while(TEST_CASES<CASES)
    {
        //printf("%d\n",TEST_CASES+1);
        char isWON = 'i';
        char WONBY = 'n';
        GETIN();
        int freespace = 0;
        REP0(j,4)
        {
            REP0(k,4)
            {
                if(BOARD[j][k] == '.')
                    freespace++;
            }
        }



        REP0(j,4)
        {
            if(!strcmp(BOARD[j],"XXXX") || !strcmp(BOARD[j],"XXXT") || !strcmp(BOARD[j],"XXTX") || !strcmp(BOARD[j],"XTXX") || !strcmp(BOARD[j],"TXXX"))
            {
                isWON = 'X';
                break;
            }
            else if(!strcmp(BOARD[j],"OOOO") || !strcmp(BOARD[j],"OOOT") || !strcmp(BOARD[j],"OOTO") || !strcmp(BOARD[j],"OTOO") || !strcmp(BOARD[j],"TOOO"))
            {
                isWON = 'O';
                break;
            }
        }

        REP0(j,4)
        {
            if((BOARD[0][j] =='X' || BOARD[0][j] == 'T') &&(BOARD[1][j] =='X' || BOARD[1][j] == 'T') &&(BOARD[2][j] =='X' || BOARD[2][j] == 'T')&&(BOARD[3][j] =='X' || BOARD[3][j] == 'T'))
            {
                isWON = 'X';
                WONBY = 'X';
                break;
            }
            else if((BOARD[0][j] =='O' || BOARD[0][j] == 'T') &&(BOARD[1][j] =='O' || BOARD[1][j] == 'T') &&(BOARD[2][j] =='O' || BOARD[2][j] == 'T')&&(BOARD[3][j] =='O' || BOARD[3][j] == 'T'))
            {
                isWON = 'O';
                WONBY = 'O';
                break;
            }
        }
        if((isWON != 'O' || isWON!='X') && (BOARD[0][0] =='O' || BOARD[0][0] == 'T') &&(BOARD[1][1] =='O' || BOARD[1][1] == 'T') &&(BOARD[2][2] =='O' || BOARD[2][2] == 'T')&&(BOARD[3][3] =='O' || BOARD[3][3] == 'T'))
        {
            isWON = 'O';
            WONBY = 'O';

        }
        else if((isWON != 'O' || isWON!='X') && (BOARD[0][0] =='X' || BOARD[0][0] == 'T') &&(BOARD[1][1] =='X' || BOARD[1][1] == 'T') &&(BOARD[2][2] =='X' || BOARD[2][2] == 'T')&&(BOARD[3][3] =='X' || BOARD[3][3] == 'T'))
        {
            isWON = 'X';
            WONBY = 'X';
        }
        else if((isWON != 'O' || isWON!='X') && (BOARD[0][3] =='X' || BOARD[0][3] == 'T') &&(BOARD[1][2] =='X' || BOARD[1][2] == 'T') &&(BOARD[2][1] =='X' || BOARD[2][1] == 'T')&&(BOARD[3][0] =='X' || BOARD[3][0] == 'T'))
        {
            isWON = 'X';
            WONBY = 'X';
        }
        else if((isWON != 'O' || isWON!='X') && (BOARD[0][3] =='O' || BOARD[0][3] == 'T') &&(BOARD[1][2] =='O' || BOARD[1][2] == 'T') &&(BOARD[2][1] =='O' || BOARD[2][1] == 'T')&&(BOARD[3][0] =='O' || BOARD[3][0] == 'T'))
        {
            isWON = 'O';
            WONBY = 'O';
        }
        if(isWON == 'i' && freespace == 0)
            isWON = 'd';
        PRINT(isWON,WONBY,TEST_CASES);

        TEST_CASES++;
    }
}
