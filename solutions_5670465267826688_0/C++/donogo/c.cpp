#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

#define E 0
#define I 1
#define J 2
#define K 3

#define ME 4
#define MI 5
#define MJ 6
#define MK 7

int mtbl[8][8] = {
         /* E, I, J, K,ME,MI,MJ,MK*/
  /* E*/ {  E, I, J, K,ME,MI,MJ,MK },
  /* I*/ {  I,ME, K,MJ,MI, E,MK, J },
  /* J*/ {  J,MK,ME, I,MJ, K, E,MI },
  /* K*/ {  K, J,MI,ME,MK,MJ,MI, E },
  /*ME*/ { ME,MI,MJ,MK,E, I, J, K, },
  /*MI*/ { MI, E,MK, J,I,ME, K,MJ, },
  /*MJ*/ { MJ, K, E,MI,J,MK,ME, I, },
  /*MK*/ { MK,MJ, I, E,K, J,MI,ME, },
};
  
int itbl[8] = {
/* E, I, J, K,ME,MI,MJ,MK*/
  E, MI,MJ,MK,ME, I, J, K
};

string sym(int a) {
  switch(a) {
  case E: return "1";
  case I: return "i";
  case J: return "j";
  case K: return "k";
  case ME: return "-1";
  case MI: return "-i";
  case MJ: return "-j";
  case MK: return "-k";
  }

  return "?";

}

int find_decomposition(string WW) {
  map <int, int> eval;
  int vl, vm, vr;
  int i, j;

  eval['i'] = I;
  eval['j'] = J;
  eval['k'] = K;

  vm = E;

  for (i = 0; i < WW.length(); i++) {
    vm = mtbl[ vm ][ eval[WW[i]] ];
  }

  // evaluate WW

  if (vm != ME) { // the product is not ijk
    return 0;
  }

  vl = E;
  vr = E;

  for (i = 0; i < WW.length(); i++) {
    vl = mtbl[ vl ][ eval[ WW[i] ]];
    vm = mtbl[ itbl[ eval[ WW[i] ] ] ][ vm ];
    if (vl != I) {
      continue;
    }
    for (j = WW.length() - 1; j > i; j--) {
      vr = mtbl[ eval[ WW[j] ]  ][ vr ];
      vm = mtbl[ vm ][ itbl[ eval[ WW[j] ] ] ];
      //      cout << "<" << i << "," << j << ">";
      //      cout << "(" << sym(vl) << ",";
      //      cout << sym(vm) << "," ;
      //      cout << sym(vr) << ")" << endl;

      if (vm == J && vr == K) {
	return 1;
      }
    }
  }
  return 0;
}


int isijk(string W, int X) {
  int L = W.length();

  if (X % 4 == 0) {
    // in this case the value is E
    // on the other hand IJK = KK = ME.
    // value mismatch
    return 0;
  }

  if (X > 12) {
    X = 12 + X % 12; // reduction;
  }
  string WW;
  for (int i = 0; i < X; i++) {
    WW += W;
  }
  return find_decomposition(WW);

}

int main(void) {
  int T, t;
  int L, X;
  int res;
  cin >> T;

  for (t = 1; t <= T; t++) {
    string W;
    cin >> L; // length
    cin >> X; // power
    cin >> W; // word



    res = isijk(W, X);

    cout << "Case #" << t << ": " << ((res == 1) ? "YES" : "NO") << endl;
	 

  }
  return 0;
}
