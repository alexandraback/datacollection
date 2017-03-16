#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>

using namespace std;
typedef unsigned long long ull; 

int main(int argc, char *argv[])
{
    int T;
    int cno = 1; 
    cin >> T; 
    while(T--)
    {
         int N, M;
         cin >> N >> M; 
         
         ull table[120][120]; 
         
         int toytype[120], boxtype[120]; 
         ull toys[120], boxes[120]; 
         ull copytoys[120], copyboxes[120]; 
         for (int i  = 0; i < N; i++)
         {
             cin >> toys[i+1]; 
             cin >> toytype[i+1]; 
         }  
         for (int i = 0; i < M; i++)
         {
             cin >> boxes[i+1]; 
             cin >> boxtype[i+1]; 

         }
         
         for (int  i = 0; i < 120; i++) for (int j = 0;  j < 120; j++)
             table[i][j] = 0; 

         for (int i = 1; i <= N; i++)
         {
             for (int j = 1; j <= M; j++)
             {
                 table[i][j] = 0; 
                 if (toytype[i] != boxtype[j])
                 {
                    table[i][j] = table[i-1][j]; 
                    table[i][j] >?= table[i][j-1]; 
                 }
                 else
                 {
                     ull val = 0;
                     for (int k = 0; k <= N; k++)
                         copytoys[k] = toys[k]; 
                     for (int k = 0; k <= M; k++)
                         copyboxes[k] = boxes[k]; 
                     for (int x = i, y = j; x > 0 && y > 0; )
                     {
                         ull m = toys[x]; 
                         m <?= boxes[y]; 
                         val += m; 
                         table[i][j] >?= val + table[x-1][y-1];
                         toys[x] -= m; 
                         boxes[y] -= m; 
                          
                         if (toys[x] == 0)
                         {
                            x--; 
                            while (x > 0 && toytype[x] != boxtype[y])
                                  x--;
                         } 
                         else if (boxes[y] == 0)
                         {
                            y--;
                            while (y > 0 && toytype[x] != boxtype[y])
                                  y--;
                         }        
                     }
                     for (int k = 0; k <= N; k++)
                         toys[k] = copytoys[k]; 
                     for (int k = 0; k <= M; k++)
                         boxes[k] = copyboxes[k]; 
                 }
             }
         }
         cout << "Case #" << cno++ << ": " << table[N][M] << endl;          
    }
    return EXIT_SUCCESS;
}
