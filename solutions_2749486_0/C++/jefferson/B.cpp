#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

void solve(int X, int Y, string& sol) {
  for (int i = 0; i < X; i++)
    sol += "WE";
  for (int i = 0; i < Y; i++)
    sol += "SN";
}

void my_swap(string& s, char c, char t) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c)
      s[i] = t;
    else if (s[i] == t)
      s[i] = c;
  }
}
int main () {
  int T; cin >> T;

  for (int t = 1; t <= T; t++) {
    int X, Y; cin >> X >> Y;
    bool cH = false, cV = false;

    if (X < 0) {
      X = -X;
      cH = true;
    }
    if (Y < 0) {
      Y = -Y;
      cV = true;
    }

    string sol = "";
    solve(X,Y,sol);

    if (cH)
      my_swap(sol,'E','W');
    if (cV)
      my_swap(sol,'N','S');

    cout << "Case #" << t << ": " << sol << endl;
  }

  return 0;
}
