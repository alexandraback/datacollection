#include <iostream>
#include <string>
using namespace std;

int main(){
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++){
    int x, y;
    string sx, sy;
    cin >> x >> y;
    if (y > 0)
      sy = "SN";
    else{
      sy = "NS";
      y = -y;
    }
    if (x > 0)
      sx = "WE";
    else{
      sx = "EW";
      x = -x;
    }

    cout << "Case #" << i << ": ";
    for (int j = 0; j < x; j++) cout << sx;
    for (int j = 0; j < y; j++) cout << sy;
    cout << endl;
  }
}
