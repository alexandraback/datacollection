#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum BState { UNKNOWN=0, MISS, HIT };

int main()
{
     int test_cases;
     cin >> test_cases;
     for(int z=1; z<=test_cases; z++)
     {
          int R, C, W;
          cin >> R >> C >> W;

          BState board[R][C];
          for(int i=0; i<R; i++)
               for(int j=0; j<C; j++)
                    board[i][j]=UNKNOWN;

          int score=0;
          int hits=0;
          while(hits!=W)
          {
               int ships[R][C];
               for(int i=0; i<R; i++)
                    for(int j=0; j<C; j++)
                         ships[i][j]=0;

               //Find all the places you can put the ship
               int possible_positions=0;

               //Horizontal ship
               for(int i=0; i<R; i++)
                    for(int j=0; j<C; j++)
                    {
                         int k;
                         for(k=0; k<W; k++)
                              if(j+k >= C || board[i][j+k]==MISS)
                                   break;

                         if(k==W)
                         {
                              for(k=0; k<W; k++)
                                   ships[i][j+k]++;
                              possible_positions++;
                         }
                    }

               //Vertical ship
               for(int i=0; i<R; i++)
                    for(int j=0; j<C; j++)
                    {
                         int k;
                         for(k=0; k<W; k++)
                              if(i+k >= R || board[i+k][j]==MISS)
                                   break;

                         if(k==W)
                         {
                              for(k=0; k<W; k++)
                                   ships[i+k][j]++;
                              possible_positions++;
                         }

                    }

               //Find the most useful square to attack
               int x=-1, y=-1;
               for(int i=0; i<R; i++)
                    for(int j=0; j<C; j++)
                         if(board[i][j]==UNKNOWN && (x==-1 || ships[i][j] > ships[x][y]))
                         {
                              x=i;
                              y=j;
                         }

               //Brat will move ship out of way if possible;
               //not possible iff we are covering every possible position with this sqaure
               if(possible_positions==ships[x][y])
               {
                    board[x][y]=HIT; //we attack this square
                    hits++;
               }
               else
                    board[x][y]=MISS;

               //Always need to increment score
               score++;
          }
          
          cout << "Case #" << z << ": " << score << endl;
     }

     return 0;
}
