#include<cstdio>
using namespace std;

// Board
char grid[4][5];
int dir[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

// Check
bool check(int row,int col,char ch)
{
  int r,c,i,j;

  for(i=0;i<8;i++)
  {
    for(j=1;j<4;j++)
    {
      r=row+j*dir[i][1];
      c=col+j*dir[i][0];
      if(r<0||c<0||r>=4||c>=4||(grid[r][c]!=ch&&grid[r][c]!='T')) break;
    }
    if(j==4) return true;
  }
  return false;
}

// Main
int main(void)
{
  int tc,row,col,i,j,r,c,cs=1;
  bool Xwin,Owin,has_p;

  // Read Input
  scanf("%d",&tc);
  while(tc--)
  {
    // Row
    has_p=false;
    for(row=0;row<4;row++)
    {
      scanf("%s",grid[row]);
      for(col=0;col<4;col++)
        if(grid[row][col]=='.') has_p=true;
    }

    printf("Case #%d: ",cs++);

    // Check boundary
    Xwin=Owin=false;
    for(col=0;col<4;col++)
    {
      // O
      if(grid[0][col]=='O')
      {
        Owin=check(0,col,'O');
        if(Owin) break;
      }

      // X
      else if(grid[0][col]=='X')
      {
        Xwin=check(0,col,'X');
        if(Xwin) break;
      }
    }
    if(Owin) puts("O won");
    else if(Xwin) puts("X won");
    else
    {
      for(col=0;col<4;col++)
      {
        // O
        if(grid[3][col]=='O')
        {
          Owin=check(3,col,'O');
          if(Owin) break;
        }

        // X
        else if(grid[3][col]=='X')
        {
          Xwin=check(3,col,'X');
          if(Xwin) break;
        }
      }
      if(Owin) puts("O won");
      else if(Xwin) puts("X won");
      else
      {
        for(row=0;row<4;row++)
        {
          // O
          if(grid[row][0]=='O')
          {
            Owin=check(row,0,'O');
            if(Owin) break;
          }

          // X
          else if(grid[row][0]=='X')
          {
            Xwin=check(row,0,'X');
            if(Xwin) break;
          }
        }
        if(Owin) puts("O won");
        else if(Xwin) puts("X won");
        else
        {
          for(row=0;row<4;row++)
          {
            // O
            if(grid[row][3]=='O')
            {
              Owin=check(row,3,'O');
              if(Owin) break;
            }

            // X
            else if(grid[row][3]=='X')
            {
              Xwin=check(row,3,'X');
              if(Xwin) break;
            }
          }
          if(Owin) puts("O won");
          else if(Xwin) puts("X won");
          else
          {
            if(has_p) puts("Game has not completed");
            else puts("Draw");
          }
        }
      }
    }
  }
  return 0;
}
