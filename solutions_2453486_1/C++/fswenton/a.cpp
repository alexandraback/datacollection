#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cmath>
// #include "Rational.h"

/*
// !!! Don't forget to canonicalize() Rational's after input!
#include <gmpxx.h>
#include <gmp.h>
#define Integer mpz_class
#define Rational mpq_class
#define Float mpf_class
*/

using namespace std;

bool debug = false;

int main(void) {
  int iTest, nTests; cin >> nTests;

  for (iTest = 1; iTest <= nTests; ++iTest) {
    cerr << iTest << "/" << nTests << "\n";

    int i, j;
    vector<string> board(4);
    for (i = 0; i < 4; ++i) {
      cin >> board[i];
      if (debug) cerr << board[i] << "\n";
    }

    bool xWon = false, oWon = false, draw=true;
      int Xs, Os, Ts;
      
      Xs = Os = Ts = 0;
      for (i = 0; i < 4; ++i)
	if (board[i][i]=='X')
	  ++Xs;
	else if (board[i][i]=='O')
	  ++Os;
	else if (board[i][i]=='T')
	  ++Ts;
      if (Xs==4 || (Xs==3 && Ts==1)) xWon = true;
      if (Os==4 || (Os==3 && Ts==1)) oWon = true;
      if (Xs+Os+Ts!=4) draw = false;

      Xs = Os = Ts = 0;
      for (i = 0; i < 4; ++i)
	if (board[i][3-i]=='X')
	  ++Xs;
	else if (board[i][3-i]=='O')
	  ++Os;
	else if (board[i][3-i]=='T')
	  ++Ts;
      if (Xs==4 || (Xs==3 && Ts==1)) xWon = true;
      if (Os==4 || (Os==3 && Ts==1)) oWon = true;
      if (Xs+Os+Ts!=4) draw = false;

      for (i = 0; i < 4; ++i) {
	Xs = Os = Ts = 0;
	for (j = 0; j < 4; ++j)
	  if (board[i][j]=='X')
	    ++Xs;
	  else if (board[i][j]=='O')
	    ++Os;
	  else if (board[i][j]=='T')
	    ++Ts;
	if (Xs==4 || (Xs==3 && Ts==1)) xWon = true;
	if (Os==4 || (Os==3 && Ts==1)) oWon = true;
      if (Xs+Os+Ts!=4) draw = false;

	Xs = Os = Ts = 0;
	for (j = 0; j < 4; ++j)
	  if (board[j][i]=='X')
	    ++Xs;
	  else if (board[j][i]=='O')
	    ++Os;
	  else if (board[j][i]=='T')
	    ++Ts;
	if (Xs==4 || (Xs==3 && Ts==1)) xWon = true;
	if (Os==4 || (Os==3 && Ts==1)) oWon = true;
      if (Xs+Os+Ts!=4) draw = false;

      }

    cout << "Case #" << iTest << ": ";

    if (xWon && !oWon)
      cout << "X won";
    else if (oWon && !xWon)
      cout << "O won";
    else if (draw)
      cout << "Draw";
else
      cout << "Game has not completed";

    cout << "\n";
  }

  return 0;
}
