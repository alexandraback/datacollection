#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<string> ttt) {
      for(int i=0; i<4; i++) {
            bool x_won = true, o_won = true;
            for(int j=0; j<4; j++) {
                  if(ttt[i][j] == 'O' || ttt[i][j] == '.') {
                        x_won = false;
                  }
                  if (ttt[i][j] == 'X' || ttt[i][j] == '.') {
                        o_won = false;
                  }
            }
            if(x_won) {
                  cout<<"X won";
                  return;
            }
            if(o_won) {
                  cout<<"O won";
                  return;
            }
      }

      for(int i=0; i<4; i++) {
            bool x_won = true, o_won = true;
            for(int j=0; j<4; j++) {
                  if(ttt[j][i] == 'O' || ttt[j][i] == '.') {
                        x_won = false;
                  }
                  if (ttt[j][i] == 'X' || ttt[j][i] == '.') {
                        o_won = false;
                  }
            }
            if(x_won) {
                  cout<<"X won";
                  return;
            }
            if(o_won) {
                  cout<<"O won";
                  return;
            }
      }

      {
            bool x_won = true, o_won = true;
            for(int j=0; j<4; j++) {
                  if(ttt[j][j] == 'O' || ttt[j][j] == '.') {
                        x_won = false;
                  }
                  if (ttt[j][j] == 'X' || ttt[j][j] == '.') {
                        o_won = false;
                  }
            }
            if(x_won) {
                  cout<<"X won";
                  return;
            }
            if(o_won) {
                  cout<<"O won";
                  return;
            }
      }

      {
            bool x_won = true, o_won = true;
            for(int j=0; j<4; j++) {
                  if(ttt[3-j][j] == 'O' || ttt[3-j][j] == '.') {
                        x_won = false;
                  }
                  if (ttt[3-j][j] == 'X' || ttt[3-j][j] == '.') {
                        o_won = false;
                  }
            }
            if(x_won) {
                  cout<<"X won";
                  return;
            }
            if(o_won) {
                  cout<<"O won";
                  return;
            }
      }


      {
            bool draw = true;
            for(int i=0; i<4; i++) {
                  for(int j=0; j<4; j++) {
                        if(ttt[i][j] == '.') {
                              draw = false;
                        }
                  }
            }
            if(draw) {
                  cout<<"Draw";
            } else {
                  cout<<"Game has not completed";
            }
      }

      return;
}

int main() {
      int T;
      cin>>T;
      vector<string> ttt(4);
      for(int t=1; t<=T; t++) {
            cout<<"Case #"<<t<<": ";
            for(int j=0; j<4; j++) {
                  cin>>ttt[j];
            }
            solve(ttt);
            cout<<endl;
      }
      return 0;
}

