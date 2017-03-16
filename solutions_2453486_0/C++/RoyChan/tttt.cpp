#include <iostream>
using namespace std;

bool check(char b[][4], char c){
  for (int i=0; i<4; i++){
    if ((b[i][0]==c || b[i][0]=='T')&&(b[i][1]==c || b[i][1]=='T')&&(b[i][2]==c || b[i][2]=='T')&&(b[i][3]==c || b[i][3]=='T'))
      return true;
    if ((b[0][i]==c || b[0][i]=='T')&&(b[1][i]==c || b[1][i]=='T')&&(b[2][i]==c || b[2][i]=='T')&&(b[3][i]==c || b[3][i]=='T'))
      return true;
  }
  if ((b[0][0]==c || b[0][0]=='T')&&(b[1][1]==c || b[1][1]=='T')&&(b[2][2]==c || b[2][2]=='T')&&(b[3][3]==c || b[3][3]=='T'))
    return true;
  if ((b[0][3]==c || b[0][3]=='T')&&(b[1][2]==c || b[1][2]=='T')&&(b[2][1]==c || b[2][1]=='T')&&(b[3][0]==c || b[3][0]=='T'))
    return true;
  return false;
}

int main(){
  int t,i,j,k;
  char b[4][4],c;
  bool finish;
  cin>>t;
  for (i=1; i<=t; i++){
    cout << "Case #" << i << ": ";
    finish=true;
    for (j=0;j<4;j++)
      for (k=0; k<4; k++){
        cin>>b[j][k];
        if (b[j][k]=='.') finish=false;
      }
    if (check(b,'X')) cout << "X won" << endl;
    else if (check(b,'O')) cout << "O won" << endl;
    else{ 
      if (finish) cout << "Draw" << endl;
      else cout << "Game has not completed" << endl;
    }
  }
  return 0;
}
