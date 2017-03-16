#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(){
  int T;
  cin>>T;
  for(int times = 0; times < T; ++times){
    vector<string> board;
    string s = "";
    bool xwon, owon;
    xwon = owon = false;
    int total = 0;
    for(int i = 0; i < 4; ++i){
      cin>>s;
      board.push_back(s);
      for(int i = 0; i < 4; ++i)if(s[i] != '.')total++;
    }
    // Check horizontal
    for(int i = 0; i < 4; ++i){
      int xcnt = 0, ocnt = 0;
      for(int j = 0; j < 4; ++j){
	if(board[i][j] != '.'){
	  if(board[i][j] == 'X' || board[i][j] == 'T')xcnt++;
	  if(board[i][j] == 'O' || board[i][j] == 'T')ocnt++;
	}
      }
      if(xcnt == 4)xwon = true;
      if(ocnt == 4)owon = true;
    }
    //Check verticle
    for(int i = 0; i < 4; ++i){
      int xcnt = 0, ocnt = 0;
      for(int j = 0; j < 4; ++j){
	if(board[j][i] != '.'){
	  if(board[j][i] == 'X' || board[j][i] == 'T'){xcnt++;}
	  if(board[j][i] == 'O' || board[j][i] == 'T'){ocnt++;}
	}
      }
      if(xcnt == 4)xwon = true;
      if(ocnt == 4)owon = true;
    }
    // Check diagonal
    int xcnt = 0, ocnt = 0;
    for(int i = 0; i < 4; ++i){
      if(board[i][i] == 'X' || board[i][i] == 'T'){xcnt++;}
      if(board[i][i] == 'O' || board[i][i] == 'T'){ocnt++;}
    }
    if(xcnt == 4)xwon = true;
    if(ocnt == 4)owon = true;

    xcnt = ocnt = 0;
    for(int i = 0; i < 4; ++i){
      if(board[i][4 - i - 1] == 'X' || board[i][4 - i - 1] == 'T'){xcnt++;}
      if(board[i][4 - i - 1] == 'O' || board[i][4 - i - 1] == 'T'){ocnt++;}
    }
    if(xcnt == 4)xwon = true;
    if(ocnt == 4)owon = true;

    if(xwon)cout<<"Case #"<<times + 1<<": "<<"X won"<<endl;
    else if(owon)cout<<"Case #"<<times + 1<<": "<<"O won"<<endl;
    else if(!xwon && !owon && total == 16)cout<<"Case #"<<times + 1<<": "<<"Draw"<<endl;
    else {
      cout<<"Case #"<<times + 1<<": "<<"Game has not completed"<<endl;
    }
  }
  return 0;
}
