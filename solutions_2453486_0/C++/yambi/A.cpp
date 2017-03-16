#include <iostream>
#include <vector>
using namespace std;

bool checkO(char a, char b, char c, char d){
  if(a!='O'&&a!='T')return false;
  if(b!='O'&&b!='T')return false;
  if(c!='O'&&c!='T')return false;
  if(d!='O'&&d!='T')return false;
  return true;
}
bool checkX(char a, char b, char c, char d){
  if(a!='X'&&a!='T')return false;
  if(b!='X'&&b!='T')return false;
  if(c!='X'&&c!='T')return false;
  if(d!='X'&&d!='T')return false;
  return true;
}


void solve(){
  char state[4][4];
  bool over = true;
  bool xwon = false;
  bool owon = false;
  for(int i=0;i<4;++i){
    for(int j=0;j<4;++j){
      cin>>state[i][j];
      if(state[i][j]=='.')over=false;
    }
  }
  //columns, rows
  for(int i=0;i<4;++i){
    if(checkX(state[i][0],state[i][1],state[i][2],state[i][3]))xwon=true;
    if(checkX(state[0][i],state[1][i],state[2][i],state[3][i]))xwon=true;
    if(checkO(state[i][0],state[i][1],state[i][2],state[i][3]))owon=true;
    if(checkO(state[0][i],state[1][i],state[2][i],state[3][i]))owon=true;
  }
  //diagonal
  {
    if(checkX(state[0][0],state[1][1],state[2][2],state[3][3]))xwon=true;
    if(checkX(state[3][0],state[2][1],state[1][2],state[0][3]))xwon=true;
    if(checkO(state[0][0],state[1][1],state[2][2],state[3][3]))owon=true;
    if(checkO(state[3][0],state[2][1],state[1][2],state[0][3]))owon=true;
  }

  if(xwon)cout << "X won" << endl;
  else if(owon)cout << "O won" << endl;
  else if(over)cout << "Draw" << endl;
  else cout << "Game has not completed" << endl;
}
int main(){
  int N;cin>>N;
  for(int i=1;i<=N;++i){
    cout << "Case #" << i <<": ";
    solve();
  }
  return 0;
}

