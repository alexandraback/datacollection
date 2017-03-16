#include <iostream>
#include <string>
using namespace std;

//// main
int main(){
  int T;
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int X,R,C;
    cin >> X >> R >> C; cin.ignore();

    if(R*C%X != 0){
      cout << "Case #" << i+1 << ": RICHARD" << endl;
      continue;
    }
    if(X >= 7){ // because of hole
      cout << "Case #" << i+1 << ": RICHARD" << endl;
      continue;
    }
    if(X <= 2){
      cout << "Case #" << i+1 << ": GABRIEL" << endl;
      continue;
    }

    // for small, X,R,C <= 4
    if(X == 3){ // 1*3 | 2*3, 3*3
      if(R == 1 || C==1){ //
        cout << "Case #" << i+1 << ": RICHARD" << endl;
      } else {
        cout << "Case #" << i+1 << ": GABRIEL" << endl;
      }
    }
    if(X == 4){ // 2*2, 4*1, 4*2 | 4*3, 4*4
      if(R <= 2 || C <= 2) {
        cout << "Case #" << i+1 << ": RICHARD" << endl;
      } else {
        cout << "Case #" << i+1 << ": GABRIEL" << endl;
      }
    }
  }

  return 0;
}
