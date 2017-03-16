#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <map>
#include <stdlib.h>
using namespace std;
#define ACCEPTED 0
#define F first
#define S second
#define PI (acos(-1.0))
#define EPS (1e-11)
#define INF (1<<30)
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
/* ============================================== */
char board[9][9];
int win(char ch){
  int i, j;
  for(i=0; i<4; i++){
    for(j=0; j<4; j++) if(board[i][j]!='T' && board[i][j]!=ch) break;
    if(j==4) return 1;
  }
  for(i=0; i<4; i++){
    for(j=0; j<4; j++) if(board[j][i]!='T' && board[j][i]!=ch) break;
    if(j==4) return 1;
  }
  for(i=0; i<4; i++) if(board[i][i]!='T' && board[i][i]!=ch) break;
  if(i==4) return 1;
  for(i=0; i<4; i++) if(board[i][3-i]!='T' && board[i][3-i]!=ch) break;
  if(i==4) return 1;
  return 0;
}
int ended(){
  int i, j;
  for(i=0; i<4; i++)
    for(j=0; j<4; j++)
      if(board[i][j]=='.') return 0;
  return 1;
}
int main(){
  int t, T, i;

  scanf("%d", &T);
  for(t=1; t<=T; t++){
    for(i=0; i<4; i++) scanf("%s", board[i]);
    if(win('O')) printf("Case #%d: O won\n", t);
    else if(win('X')) printf("Case #%d: X won\n", t);
    else if(!ended()) printf("Case #%d: Game has not completed\n", t);
    else printf("Case #%d: Draw\n", t);
  }
  
  return ACCEPTED;
}
/* ============================================== */
