#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Status {Xw, Ow, Draw, NC};

Status CheckRow(string* a, int row) {
  int X=0;
  int O=0;
  for(int i=0; i<4; ++i) {
    if (a[row][i] == '.') return NC;
    else if (a[row][i] == 'X') ++X;
    else if (a[row][i] == 'O') ++O;
    else {++X; ++O;}
  }
  if (X==4) return Xw;
  if (O==4) return Ow;
  return Draw;
}
Status CheckCol(string* a, int col) {
  int X=0;
  int O=0;
  for(int i=0; i<4; ++i) {
    if (a[i][col] == '.') return NC;
    else if (a[i][col] == 'X') ++X;
    else if (a[i][col] == 'O') ++O;
    else {++X; ++O;}
  }
  if (X==4) return Xw;
  if (O==4) return Ow;
  return Draw;
}
Status CheckDiag1(string* a) {
  int X=0;
  int O=0;
  for(int i=0; i<4; ++i) {
    if (a[i][i] == '.') return NC;
    else if (a[i][i] == 'X') ++X;
    else if (a[i][i] == 'O') ++O;
    else {++X; ++O;}
  }
  if (X==4) return Xw;
  if (O==4) return Ow;
  return Draw;
}
Status CheckDiag2(string* a) {
  int X=0;
  int O=0;
  for(int i=0; i<4; ++i) {
    if (a[i][3-i] == '.') return NC;
    else if (a[i][3-i] == 'X') ++X;
    else if (a[i][3-i] == 'O') ++O;
    else {++X; ++O;}
  }
  if (X==4) return Xw;
  if (O==4) return Ow;
  return Draw;
}

Status Solve(string* a) {
  Status s;
  Status tmp = Draw;
  s = CheckDiag1(a);
  if(s ==Xw || s == Ow) return s;
  if(s == NC) tmp = NC;
  s = CheckDiag2(a);
  if(s ==Xw || s == Ow) return s;
  if(s == NC) tmp = NC;
  for(int i=0; i<4; ++i) {
    s = CheckRow(a, i);
    if(s == Xw || s == Ow) return s;
    if(s == NC) tmp = NC;
    s = CheckCol(a, i);
    if(s == Xw || s == Ow) return s;
    if(s == NC) tmp = NC;
  }
  return tmp;
}

int main(int argc, char* argv[]) {
  ifstream in(argv[1]);
  int T;
  in >> T;
  for(int i=0; i<T; ++i) {
    string a[4];
    for(int j=0; j<4; ++j) {
      in >> a[j];
    }
    cout << "Case #" << (i+1) << ": ";
    Status s = Solve(a);
    if (s == Xw) cout << "X won" << endl;
    else if (s == Ow) cout << "O won" << endl;
    else if (s == Draw) cout << "Draw" << endl;
    else cout << "Game has not completed" << endl;
  }
  return 0;
}
