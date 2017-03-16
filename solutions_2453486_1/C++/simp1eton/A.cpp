#include <iostream>
#include <cstdio>
using namespace std;

int testcase;
char B[5][5];
bool win,lose,draw,incomplete;

int main(){
  freopen("A-large.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    win = lose = draw = incomplete = 0;
    for(int i=0;i<4;++i)
      scanf(" %s",B[i]);
    int t1, t2;
    for(int i=0;i<4;++i){
      t1 = t2 = 0;
      for(int j=0;j<4;++j){
        if(B[i][j] == 'X') ++t1;
        if(B[i][j] == 'O') ++t2;
        if(B[i][j] == 'T') ++t1, ++t2;
        if(B[i][j] == '.') incomplete = 1;
      }
      if(t1 == 4) win = 1;
      if(t2 == 4) lose = 1;
    }
    
    for(int j=0;j<4;++j){
      t1 = t2 = 0;
      for(int i=0;i<4;++i){
        if(B[i][j] == 'X') ++t1;
        if(B[i][j] == 'O') ++t2;
        if(B[i][j] == 'T') ++t1, ++t2;
        if(B[i][j] == '.') incomplete = 1;
      }
      if(t1 == 4) win = 1;
      if(t2 == 4) lose = 1;
    }
    
    t1 = t2 = 0;
    for(int i=0;i<4;++i){
      if(B[i][i] == 'X') ++t1;
      if(B[i][i] == 'O') ++t2;
      if(B[i][i] == 'T') ++t1, ++t2;
      if(B[i][i] == '.') incomplete = 1;
    }
    if(t1 == 4) win = 1;
    if(t2 == 4) lose = 1;
    
     t1 = t2 = 0;
    for(int i=0;i<4;++i){
      if(B[i][3-i] == 'X') ++t1;
      if(B[i][3-i] == 'O') ++t2;
      if(B[i][3-i] == 'T') ++t1, ++t2;
      if(B[i][3-i] == '.') incomplete = 1;
    }
    if(t1 == 4) win = 1;
    if(t2 == 4) lose = 1;
    printf("Case #%d: ",TC);
    if(win) printf("X won\n");
    else if(lose) printf("O won\n");
    else if(incomplete) printf("Game has not completed\n");
    else printf("Draw\n");
  }
}
