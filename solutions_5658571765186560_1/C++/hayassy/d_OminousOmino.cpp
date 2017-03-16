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


    if(R*C%X != 0){ // board is invalid
      cout << "Case #" << i+1 << ": RICHARD" << endl;
      continue;
    }
    if(X >= 7){ // because of hole
      cout << "Case #" << i+1 << ": RICHARD" << endl;
      continue;
    }
    if(X <= 2){ // only one choice
      cout << "Case #" << i+1 << ": GABRIEL" << endl;
      continue;
    }

    // for small, X,R,C <= 4
    if(X == 3){ // 1*3 | 2*3, 3*3
      // always makable 2*3
      if(R == 1 || C==1){ // other than 1*3n is ok
        cout << "Case #" << i+1 << ": RICHARD" << endl;
      } else {
        cout << "Case #" << i+1 << ": GABRIEL" << endl;
      }
    }
    if(X == 4){ // 2*2, 4*1, 4*2 | 4*3, 4*4
      // always makable 4*3
      if(R <= 2 || C <= 2) { // 2* is out 'case of 'T'
        cout << "Case #" << i+1 << ": RICHARD" << endl;
      } else {
        cout << "Case #" << i+1 << ": GABRIEL" << endl;
      }
    }

    // for large, X,R,C <= 20
    // but X <= 6
    if(X == 5){ // R orC is 5n
      // because of 'W', couldn't make 5*3
      if(R <= 3 || C <= 3) {
        cout << "Case #" << i+1 << ": RICHARD" << endl;
      } else {
        cout << "Case #" << i+1 << ": GABRIEL" << endl;
      }
    }
    if(X == 6){
      // can't make 3*6 ('J')
      if(R <= 3 || C <= 3) {
        cout << "Case #" << i+1 << ": RICHARD" << endl;
      } else {
        cout << "Case #" << i+1 << ": GABRIEL" << endl;
      }
    }
  }

  return 0;
}
