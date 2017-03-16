#include <iostream>
using namespace std;

int max(int a, int b)
{
  if(a > b) return a;
  return b;
}

bool checkWinning(int B[][4])
{
  for(int i=0;i<4;i++)
  {
    if( B[i][0] + B[i][1] + B[i][2] + B[i][3] == 4) return true;
    if( B[0][i] + B[1][i] + B[2][i] + B[3][i] == 4) return true;
  }
  if( B[0][0] + B[1][1] + B[2][2] + B[3][3] == 4 ) return true;
  if( B[0][3] + B[1][2] + B[2][1] + B[3][0] == 4 ) return true;
  
  return false;
}

bool checkDraw(int EX[][4], int OH[][4])
{
  int sum = 0;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      sum += max(EX[i][j] , OH[i][j]);
    }
  }
  if (sum == 16) return true;
  
  return false;
}

int main()
{
  int T;
  cin >> T;
  int caseNum = 1;
  while(caseNum <= T)
  {
    int EX[4][4];
    int OH[4][4];
    
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
        char c;
        cin >> c;
        EX[i][j] = 0;
        OH[i][j] = 0;
        if(c == 'X') EX[i][j] = 1;
        if(c == 'O') OH[i][j] = 1;
        if(c == 'T') {EX[i][j] = 1; OH[i][j] = 1;}
      }
    }
    
    if ( checkWinning(EX) )
    {
      cout << "Case #" << caseNum << ": X won" << endl;
    }
    else
    {
      if( checkWinning(OH) ) 
      {
        cout << "Case #" << caseNum << ": O won" << endl;
      }
      else
      {
         if( checkDraw(EX,OH) )
         {
           cout << "Case #" << caseNum << ": Draw" << endl;
         } 
         else
         {
           cout << "Case #" << caseNum << ": Game has not completed" << endl;
         }
      }
    }
  
    caseNum++;
  }

  return 0;
}
