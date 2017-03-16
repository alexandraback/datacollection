#include <cstdio>

char board[4][4];

char read_char(){
  char c;
  do{
    scanf("%c",&c);
  }while( (c!='.') && (c!='X') && (c!='O') && (c!='T') );
  return c;
}

void read_board(){
  for(int i=0;i<4;++i){
    for(int j=0;j<4;++j){
      board[i][j]=read_char();
    }
  }
}

bool win(char cha){
  //columns
  for(int c = 0; c<4; ++c){
    int count=0;
    for(int r=0; r<4; ++r){
      if( (board[c][r]==cha) || (board[c][r]=='T') ) count++;
    }
    if(count==4) return true;
  }
  //rows
  for(int r=0; r<4; ++r){
    int count=0;
    for(int c = 0; c<4; ++c){
      if( (board[c][r]==cha) || (board[c][r]=='T') ) count++;
    }
    if(count==4) return true;
  }
  //diagonals
  if( ( (board[0][0]==cha) || (board[0][0]=='T')) &&
      ( (board[1][1]==cha) || (board[1][1]=='T')) &&
      ( (board[2][2]==cha) || (board[2][2]=='T')) &&
      ( (board[3][3]==cha) || (board[3][3]=='T')) ) return true;
  if( ( (board[0][3]==cha) || (board[0][3]=='T')) &&
      ( (board[1][2]==cha) || (board[1][2]=='T')) &&
      ( (board[2][1]==cha) || (board[2][1]=='T')) &&
      ( (board[3][0]==cha) || (board[3][0]=='T')) ) return true;
  return false;
}

bool is_full(){
  int count = 0;
  for(int i=0;i<4;++i){
    for(int j=0;j<4;++j){
      if(board[i][j] != '.') count++;
    }
  }
  return count == 16;
}

int main(){
  int T;
  scanf("%d",&T);
  for(int t=0;t<T;++t){
    read_board();
    bool xwon = win('X');
    bool owon = win('O');
    bool full = is_full();
    printf("Case #%d: ",t+1);
    if(xwon){
      printf("X won");
    }else if(owon){
      printf("O won");
    }else if(full){
      printf("Draw");
    }else{
      printf("Game has not completed");
    }
    printf("\n");
  }
}
