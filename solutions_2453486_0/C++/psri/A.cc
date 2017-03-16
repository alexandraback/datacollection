#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>

using std::map;
using std::pair;
using std::vector;
using std::sort;


#define FOR(i, a , b) for(int i = (a); i <= (b); ++i)
#define FOREACH(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

bool check(char board[5][5], char c){
  bool flag;
  //Check if c has won by rows
  FOR(i, 0, 3){
    flag = true;
    FOR(j, 0, 3){
      if(board[i][j] != c && board[i][j] != 'T'){
	flag = false;
	break;
      }
    }
    if (flag){
      return true;
    }
  }
  //Check if c has won by columns
  FOR(i, 0, 3){
    flag = true;
    FOR(j, 0, 3){
      if(board[j][i] != c && board[j][i] != 'T'){
	flag = false;
	break;
      }
    }
    if (flag){
      return true;
    }
  }
  //Check if C has won by first diagonal
  flag = true;
  FOR(i, 0, 3){
    if(board[i][i] != c && board[i][i] != 'T'){
      flag = false;
      break;
    }
  }
  if (flag)
    return true;
  //Check if C has won by second diagonal
  flag = true;
  FOR(i, 0, 3){
    if(board[i][3-i] != c && board[i][3-i] != 'T'){
      flag = false;
      break;
    }
  }
  if (flag)
    return true;
  return false;
}

int main(){
  int N;
  char board[5][5];
  scanf("%d", &N);
  FOR(I, 1, N){
    FOR(a, 0, 3){
      scanf("%s", board[a]);
    }
    int state = 4;
    //Check for empty cells
    FOR(i, 0, 3){
      FOR(j, 0, 3){
	if(board[i][j] == '.'){
	  state = 3;
	  break;
	}
      }
      if (state == 3)
	break;
    }
    if (check(board, 'X')){
      state = 2;
    }
    else if(check(board, 'O')){
      state = 1;
    }
    printf("Case #%d: ", I);
    switch (state){
    case 1: 
      printf("O won\n"); break;
    case 2:
      printf("X won\n"); break;
    case 3:
      printf("Game has not completed\n"); break;
    case 4:
      printf("Draw\n"); break;
    default:
      assert(false);
    }
  }
  return 0;
}



// Local Variables:
// compile-command: "g++ -O3 -o A A.cc"
// End:
