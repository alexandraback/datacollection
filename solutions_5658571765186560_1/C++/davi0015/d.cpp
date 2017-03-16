#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main() {
  int T;
  cin >> T;
  forn(i, T) {
    int X, R, C;
    cin >> X >> R >> C;

    bool win = false;
    if(X >= 7) {
      win = true;
    }
    else if((R * C) % X > 0) {
      win = true;
    }
    else if(X > R && X > C) {
      win = true;
    }
    else if((X + 1) / 2 > R || (X + 1) / 2 > C) {
      win = true;
    }
    else if(X >= 4 && (C <= 2 || R <= 2)) {
      win = true;
    }
    else if(X >= 5 &&  ((C == 3 && 2 * X > R) || (R == 3 && 2 * X > C))) {
      win = true;
    }

    cout << "Case #" << i+1 << ": ";
    if(win) {
      cout << "RICHARD" << endl;
    }
    else {
      cout << "GABRIEL" << endl;
    }
  }

  return 0;
}
