#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int T;
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int R,C,W;
    cin >> R >> C >> W; cin.ignore();
    int y = (R * (C/W));
    // last line
    if(C%W==0){
      y += W-1;
    } else {
      y += W;
    }

    cout << "Case #" << i+1 << ": " << y <<endl;
  }
  return 0;
}
