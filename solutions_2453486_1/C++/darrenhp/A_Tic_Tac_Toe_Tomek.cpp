#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int BOARD_SIZE = 4;

int T;

struct Player{
  int row[BOARD_SIZE];
  int line[BOARD_SIZE];
  int diagonal;
  int clinodiagoal;

  void reset(){
    fill_n(row, BOARD_SIZE, 0);
    fill_n(line,BOARD_SIZE, 0); 
    diagonal = 0;
    clinodiagoal = 0;
  }

  void inc(int l, int r){
    row[r]++;
    line[l]++;
    if (l == r) diagonal++;
    if (l + r == BOARD_SIZE - 1) clinodiagoal++;
  }

  bool is_won(){
    for (int i = 0; i < BOARD_SIZE; i++)
      if (row[i] == BOARD_SIZE)
        return true;

    for (int i = 0; i < BOARD_SIZE; i++)
      if (line[i] == BOARD_SIZE)
        return true;

    if (diagonal == BOARD_SIZE)
      return true;

    if (clinodiagoal == BOARD_SIZE)
      return true;

    return false;
  }
};

struct Game{
  char board[BOARD_SIZE][BOARD_SIZE];
  Player x;
  Player o;
  int turns;
  void reset(){
    x.reset();
    o.reset();
    turns = 0;
  }

  void set_board(int l, int r, char c){
    if (c == 'T' || c == 'X')
      x.inc(l,r);
    if (c == 'T' || c == 'O')
      o.inc(l,r);
    if (c == 'T' || c == 'X' || c == 'O')
      turns++;
  }

  void read(){
    for (int l = 0; l < BOARD_SIZE; l++){
      scanf("%s", board[l]);
    }
  }

  void process(){
    for (int l = 0; l < BOARD_SIZE; l++)
      for (int r = 0; r < BOARD_SIZE; r++)
        set_board(l,r,board[l][r]);
  }

  const char* get_state(){
    if (x.is_won())
      return "X won";
    if (o.is_won())
      return "O won";
    if (turns == BOARD_SIZE * BOARD_SIZE)
      return "Draw";
    return "Game has not completed";
  }
};

Game game;

int main(){
  scanf("%d", &T);
  for (int i = 1; i <= T; i++){
    game.reset();
    game.read();
    game.process();
    printf("Case #%d: %s\n", i, game.get_state());
  }
}




