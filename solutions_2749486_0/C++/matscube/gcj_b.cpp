#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
  ifstream ifs("input.txt");

  int T; ifs >> T;
  ofstream ofs("output.txt");

  for (int i = 0; i < T; i++) {
    int X, Y; ifs >> X >> Y;
    string s = "";

    if (X > 0) 
      for (int j = 0; j < X; j++) s += "WE";
    else 
      for (int j = 0; j < -X; j++) s += "EW";

    if (Y > 0)
      for (int j = 0; j < Y; j++) s += "SN";
    else 
      for (int j = 0; j < -Y; j++) s += "NS";

    cout << "Case #" << i+1 << ": " << s << endl;
    ofs << "Case #" << i+1 << ": " << s << endl;
  }
  return 0;
}
