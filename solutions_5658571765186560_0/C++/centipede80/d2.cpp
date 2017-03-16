#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool doit(int X, int R, int C) {
  if(R>C) swap(R,C);
  if(R*C%X!=0) return 1;
  if(X==1) return 0;
  if(X==2) return 0;
  if(X==3) {
    if(R==1&&C==3) return 1;
    if(R==3&&C==1) return 1;
    if(R==2&&C==3) return 0;
    if(R==3&&C==2) return 0;
    if(R==3&&C==3) return 0;
    if(R==3&&C==4) return 0;
    if(R==4&&C==3) return 0;
    return 1;
  }
  if(X==4) {
    if(R==1&&C==4) return 1;
    if(R==4&&C==1) return 1;
    if(R==2&&C==2) return 1;
    if(R==2&&C==4) return 1;
    if(R==4&&C==2) return 1;
    if(R==3&&C==4) return 0;
    if(R==4&&C==3) return 0;
    if(R==4&&C==4) return 0;
    return 1;
  }
  return 1;
}    

int main() {
  int tests;
  cin >> tests;
  for(int i = 0; i < tests; i++) {
    int X, R, C;
    cin >> X >> R >> C;
    string ret = "";
    if(doit(X,R,C)) ret = "RICHARD";
    else ret = "GABRIEL";
    cout << "Case #" << (i+1) << ": " << ret << endl;
  }
  return 0;
}
