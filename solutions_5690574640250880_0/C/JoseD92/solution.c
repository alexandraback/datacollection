/*
Problem

Minesweeper is a computer game that became popular in the 1980s, and is still included in some versions of the Microsoft Windows operating system. This problem has a similar idea, but it does not assume you have played Minesweeper.

In this problem, you are playing a game on a grid of identical cells. The content of each cell is initially hidden. There are M mines hidden in M different cells of the grid. No other cells contain mines. You may click on any cell to reveal it. If the revealed cell contains a mine, then the game is over, and you lose. Otherwise, the revealed cell will contain a digit between 0 and 8, inclusive, which corresponds to the number of neighboring cells that contain mines. Two cells are neighbors if they share a corner or an edge. Additionally, if the revealed cell contains a 0, then all of the neighbors of the revealed cell are automatically revealed as well, recursively. When all the cells that don't contain mines have been revealed, the game ends, and you win.

For example, an initial configuration of the board may look like this ('*' denotes a mine, and 'c' is the first clicked cell):

*..*...**.
....*.....
..c..*....
........*.
..........

There are no mines adjacent to the clicked cell, so when it is revealed, it becomes a 0, and its 8 adjacent cells are revealed as well. This process continues, resulting in the following board:

*..*...**.
1112*.....
00012*....
00001111*.
00000001..

At this point, there are still un-revealed cells that do not contain mines (denoted by '.' characters), so the player has to click again in order to continue the game.

You want to win the game as quickly as possible. There is nothing quicker than winning in one click. Given the size of the board (R x C) and the number of hidden mines M, is it possible (however unlikely) to win in one click? You may choose where you click. If it is possible, then print any valid mine configuration and the coordinates of your click, following the specifications in the Output section. Otherwise, print "Impossible".
Input

The first line of the input gives the number of test cases, T. T lines follow. Each line contains three space-separated integers: R, C, and M.
Output

For each test case, output a line containing "Case #x:", where x is the test case number (starting from 1). On the following R lines, output the board configuration with C characters per line, using '.' to represent an empty cell, '*' to represent a cell that contains a mine, and 'c' to represent the clicked cell.

If there is no possible configuration, then instead of the grid, output a line with "Impossible" instead. If there are multiple possible configurations, output any one of them.
Limits

0 ≤ M < R * C.
Small dataset

1 ≤ T ≤ 230.
1 ≤ R, C ≤ 5.
Large dataset

1 ≤ T ≤ 140.
1 ≤ R, C ≤ 50.
*/
/***********************************************************************************************************
*                                            By JoseD92                                                    *
***********************************************************************************************************/
#include <stdio.h>
char matriz[51][51];
int main(){
   int casos, i=0, R, C, M, j, k, flag, x, y, D;
   scanf("%d",&casos);
   while (i++ != casos)
   {
      scanf("%d %d %d",&R,&C,&M);
      D = (R*C)-M;
      for (j = 0; j != R ; j++){
         for (k = 0; k != C ; k++){
            matriz[j][k] = 42;
         }
      }

      flag = 0;
      x = 0;
      y = 0;
      while(!flag && x != R){
         matriz[x][y] = 46;
         flag = clic(x,y,R,C,D-1);
         matriz[x][y] = 42;
         if (!flag){
         ++y;
         if (y == C){y = 0; ++x;}}
      }

      if (flag){
         matriz[x][y] = 99;
         printf("Case #%d:\n",i);
         for (j = 0; j!= R;j++){
            for (k = 0; k!= C;k++){printf("%c",matriz[j][k]);}
            printf("\n");
         }
      }
      else {printf("Case #%d:\nImpossible\n",i);}

   }
}

int clic(int x,int y ,int R,int C,int D){
   int disponibles=0,p[8][2], flag = 0, i=0;
   if (D-disponibles == 0){return 1;}
   if (x > 0){
      if (matriz[x-1][y] != 46){matriz[x-1][y] = 46; p[disponibles][0] = x-1;p[disponibles++][1] = y;}
      if (y > 0 && matriz[x-1][y-1] != 46){matriz[x-1][y-1] = 46; p[disponibles][0] = x-1;p[disponibles++][1] = y-1;}
      if (y < C-1 && matriz[x-1][y+1] != 46){matriz[x-1][y+1] = 46; p[disponibles][0] = x-1;p[disponibles++][1] = y+1;}
   }
   if (y > 0 && matriz[x][y-1] != 46){matriz[x][y-1] = 46; p[disponibles][0] = x;p[disponibles++][1] = y-1;}
   if (y < C-1 && matriz[x][y+1] != 46){matriz[x][y+1] = 46; p[disponibles][0] = x;p[disponibles++][1] = y+1;}
   if (x < R-1){
      if (matriz[x+1][y] != 46){matriz[x+1][y] = 46; p[disponibles][0] = x+1;p[disponibles++][1] = y;}
      if (y > 0 && matriz[x+1][y-1] != 46){matriz[x+1][y-1] = 46; p[disponibles][0] = x+1;p[disponibles++][1] = y-1;}
      if (y < C-1 && matriz[x+1][y+1] != 46){matriz[x+1][y+1] = 46; p[disponibles][0] = x+1;p[disponibles++][1] = y+1;}
   }
   if (D-disponibles == 0){return 1;}
   if (D-disponibles > 0){
      while (i != disponibles){
         flag = clic(p[i][0],p[i][1],R,C,D-disponibles);
         if (flag){return 1;}
         i++;
      }
   }

   for (i=0;i!=disponibles;i++){matriz[p[i][0]][p[i][1]]=42;}

   return 0;
}
























