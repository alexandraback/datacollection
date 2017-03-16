#include "Solve.h"
#include <iostream>
#include <cfloat>

using namespace std;

Solve::Solve(istream& is_, ostream& os_):
  is(is_), os(os_)
{
 
}

bool won(char b[4][4], char p)
{
  // rows
  int r,c;
  for (r = 0; r < 4; r++) {
    for (c = 0; c < 4; c++) {
      if (b[r][c] != p and b[r][c] != 'T')
	break;
    }
    if (c == 4) return true;
  }
  // rows
  for (c = 0; c < 4; c++) {
    for (r = 0; r < 4; r++) {
      if (b[r][c] != p and b[r][c] != 'T')
	break;
    }
    if (r == 4) return true;
  }
  // diag
  int i;
  for (i = 0; i < 4; ++i) {
    if (b[i][i] != p and b[i][i] != 'T')
      break;
  }
  if (i == 4) return true;
  // diag 2
  for (i = 0; i < 4; ++i) {
    if (b[i][3-i] != p and b[i][3-i] != 'T')
      break;
  }
  if (i == 4) return true;

  return false;
}

bool draw(char b[4][4])
{
  // rows                                                                                                                                                                                     
  int r, c;
  for (r = 0; r < 4; r++) {
    for (c = 0; c < 4; c++) {
      if (b[r][c] == '.')
        return false;
    }
  }
  return true;
}



void Solve::solveOne(void)
{
  os << " ";

  // read data
  char b[4][4];

  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      char a;
      is >> a;
      b[r][c] = a;
    }
    is.ignore(100, '\n');
  }
  is.ignore(100, '\n');

  if (won(b,'X')) os << "X won";
  else if (won(b, 'O')) os << "O won";
  else if (draw(b)) os << "Draw";
  else os << "Game has not completed";

  os << endl;

}

