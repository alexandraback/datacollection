#include<cstdio>
using namespace std;

// Lawn
int grid[102][102];

// Maximums
int rowm[102],colm[102];

// Main
int main(void)
{
  int tc,row,col,R,C,cs=1;
  bool ok;

  // Read Input
  scanf("%d",&tc);
  while(tc--)
  {
    // Lawn
    scanf("%d%d",&R,&C);
    for(row=0;row<R;row++)
      for(col=0;col<C;col++)
        scanf("%d",&grid[row][col]);

    // Find Maximum
    for(row=0;row<R;row++)
    {
      rowm[row]=grid[row][0];
      for(col=1;col<C;col++)
        if(grid[row][col]>rowm[row])
          rowm[row]=grid[row][col];
    }
    for(col=0;col<C;col++)
    {
      colm[col]=grid[0][col];
      for(row=0;row<R;row++)
        if(grid[row][col]>colm[col])
          colm[col]=grid[row][col];
    }

    // Check
    ok=true;
    for(row=0;row<R;row++)
    {
      for(col=0;col<C;col++)
      {
        if(grid[row][col]!=rowm[row]&&grid[row][col]!=colm[col])
        {
          ok=false;
          break;
        }
      }
      if(!ok) break;
    }

    // Output
    printf("Case #%d: ",cs++);
    if(ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
