#include <iostream>
#include <iomanip>
using namespace std;

void solveCase() {
  double speed, C, F, X, money;
  speed = 2.0;
  cin >> C;
  cin >> F;
  cin >> X;
  money = 0;
  double elapsed = 0.0;
  if(X <= C) {
    cout << X/speed;
    return;
  }
  while(money < X) {
    elapsed += C/speed;
    money = C;
    double toWin = (X-C)/speed;
    double farmToWin = (X)/(speed+F);
    if(toWin <= farmToWin) {
      elapsed += toWin;
      money = X;
    }
    else {
      money = 0;
      speed += F;
    }
  }
  cout << fixed << setprecision(7) <<elapsed;
}

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solveCase();
    cout << endl;
  }
}