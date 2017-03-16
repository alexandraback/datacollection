#include "common.h"
bool check(char p,char a,char b,char c,char d){
  char fs[4]={a,b,c,d};
  for(int i=0;i<4;++i){
    if(fs[i]!=p && fs[i]!='T'){
      return false;
    }
  }
  return true;
}
void solve(){
  string t[4];
  bool done=true;
  for(int i=0;i<4;++i){
    cin >> t[i];
    for(int j=0;j<4;++j){
      if(t[i][j]=='.'){
        done=false;
      }
    }
  }
  int state=0;
  for(int pid=2;pid--;){
    char p=pid?'X':'O';
    bool won = false;
    for(int i=0;i<4;++i){
      if(check(p,t[i][0],t[i][1],t[i][2],t[i][3])){
        won=true;        
      }
      if(check(p,t[0][i],t[1][i],t[2][i],t[3][i])){
        won=true;        
      }
    }
    
    if(check(p,t[0][0],t[1][1],t[2][2],t[3][3])){
       won=true;        
    }
    if(check(p,t[3][0],t[2][1],t[1][2],t[0][3])){
       won=true;        
    }
    if(won){
      state |= (1<<pid);
    }    
  }
  if(state==0 && done){
    state=3;
  }
  char * describe [4] = {
    "Game has not completed",
    "O won",
    "X won",
    "Draw",
  };
  cout << describe[state] << endl;  
}
int main(){
  int t;
  cin >> t;
  for(int i=1;i<=t;++i){
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}