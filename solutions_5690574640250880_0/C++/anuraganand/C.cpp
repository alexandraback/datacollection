#include <bits/stdc++.h>

using namespace std;

char board[111][111];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  scanf("%d", &tests);

  for(int testNo = 1; testNo <= tests; testNo++) {
    printf("Case #%d:\n", testNo);
    int row, col, mines;
    scanf("%d %d %d", &row, &col, &mines);

    bool ok = true;

    if(row == 1) {
      for(int i = 0; i < col; i++) board[0][i] = '.';
      for(int i = 1; i <= mines; i++) board[0][col - i] = '*';
    } else if(col == 1) {
      for(int i = 0; i < row; i++) board[i][0] = '.';
      for(int i = 1; i <= mines; i++) board[row - i][0] = '*';
    } else {
      
      int curSafe = 1, safe = row * col - mines;
      if(safe > 1 && safe < 4) {
        ok = false;
      }

      for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
          board[i][j] = '*';

      if(safe >= 4) {
        for(int i = 0; i < 2; i++)
          for(int j = 0; j < 2; j++)
            board[i][j] = '.';
      } 
      
      board[0][0] = 'c';
      curSafe = min(4, safe);
      bool hor = false, ver = false;

      int rPos = 2, cPos = 2;
      while(rPos < row || cPos < col) {
          
        if(!ok) break;
          
        if(curSafe + 2 <= safe && cPos < col) {
          board[0][cPos] = '.';
          board[1][cPos] = '.';
          cPos++;
          curSafe += 2;
          hor = true;
        }

        if(curSafe + 2 <= safe && rPos < row) {
          board[rPos][0] = '.';
          board[rPos][1] = '.';
          rPos++;
          curSafe += 2;
          ver = true;
        }

        assert(curSafe <= safe);
        if(safe - curSafe <= 1) break;

      }

      if((safe - curSafe) % 2 == 1) {
        if(!hor || !ver) ok = false;
      }

      int rHPos = 2, cHPos = 2, rVPos = 3, cVPos = 2;

      while((rHPos < rPos && cHPos < cPos) || (cVPos < cPos && rVPos < rPos)) {

        if(!ok) break;

        if(curSafe < safe && rHPos < rPos && cHPos < cPos) {
          board[rHPos][cHPos] = '.';
          cHPos++;
          curSafe++;
          if(cHPos == col) {
            cHPos = cVPos + 1;
            rHPos++;
          }
        }

        if(curSafe < safe && cVPos < cPos && rVPos < rPos) {
          board[rVPos][cVPos] = '.';
          rVPos++;
          curSafe++;
          if(rVPos == row) {
            rVPos = rHPos + 1;
            cVPos++;
          }
        }

        if(curSafe == safe) break;
  
      }

      if(ok) assert(curSafe == safe);

    }

    
    
    if(!ok) puts("Impossible");
    else {
      board[0][0] = 'c';
      for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) printf("%c", board[i][j]);
        puts("");
      }
    }

    cerr << "Case #" << testNo << ": Done" << endl;

  }
  return 0;
}