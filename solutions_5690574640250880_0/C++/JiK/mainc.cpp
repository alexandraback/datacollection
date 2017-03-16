/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some c++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including -lgmp and -lgmpxx in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#include <gmpxx.h>

#define MAXR 50
#define MAXC 50
#define MAXM 2500


void transpose(char board[MAXR][MAXC]) {
  for(int i=0; i<MAXR; i++)
    for(int j=i; j<MAXC; j++) {
      char tmp = board[i][j];
      board[i][j] = board[j][i];
      board[j][i] = tmp;
    }
}

bool fill(int R, int C, int M, char board[MAXR][MAXC]) {
  if(R>C) {
    bool res = fill(C, R, M, board);
    transpose(board);
    return res;
  } else {
    //Assume C>R.

    int minesleft = M;
    for(int j=C-1; j>1; j--) {
      int thismines;
      if(minesleft>=R) {
	thismines = R;
	if((j==2) && ((minesleft-thismines)%2==1)) { //Exception...
	  thismines-=3;
	}
      } else if(minesleft==R-1) {
	thismines = R-2;
	if(j==2) { //Exception...
	  thismines--;
	}
      } else {
	thismines = minesleft;
      }

      
    
      for(int i=0; i<R-thismines; i++)
	board[i][j] = '.';
      for(int i=R-thismines; i<R; i++)
	board[i][j] = '*';
      minesleft -= thismines;

      if((j==2) && minesleft/2 > thismines)
	return false;
    }

    //First two columns remaining.
    if(minesleft%2==1) {
      return false;
    } else {
      for(int i=0; i<R-minesleft/2; i++) {
	board[i][0] = '.';
	board[i][1] = '.';
      }
      for(int i=R-minesleft/2; i<R; i++) {
	board[i][0] = '*';
	board[i][1] = '*';
      }
    }
  board[0][0] = 'c';
  }

  return true;
}


void solve() {
  int R, C, M;
  std::cin >> R;
  std::cin >> C;
  std::cin >> M;


  //Trivial cases?

  //Only one empty cell
  if(R*C-M==1) {
    for(int i=0;i<R;i++) {
      for(int j=0;j<C;j++) {
	std::cout << ((i+j) ? "*" : "c");
      }
      std::cout << "\n";
    }
    return;
  }

  //Either dimension 1.
  if(R==1) {
    std::cout << "c";
    for(int i=0;i<(C-M-1); i++)
      std::cout << ".";
    for(int i=0;i<M; i++)
      std::cout << "*";
    std::cout << "\n";
    return;
  }
  if(C==1) {
    std::cout << "c\n";
    for(int i=0;i<(R-M-1); i++)
      std::cout << ".\n";
    for(int i=0;i<M; i++)
      std::cout << "*\n";
    return;
  }

  //Now assume that R,C >1
  if(R*C-M==2) {
    std::cout << "Impossible\n";
    return;
  }

  //If either dimension is 2.
  if(M%2==1) {
    if((R==2) || (C==2)) {
      std::cout << "Impossible\n";
      return;
    }
  }

  //Trivial cases?
  if(R==2) {
    std::cout << "c";
    for(int i=0;i<(C-M/2-1); i++)
      std::cout << ".";
    for(int i=0;i<M/2; i++)
      std::cout << "*";
    std::cout << "\n";
    for(int i=0;i<(C-M/2); i++)
      std::cout << ".";
    for(int i=0;i<M/2; i++)
      std::cout << "*";
    std::cout << "\n";
    return;
  }
  if(C==2) {
    std::cout << "c.\n";
    for(int i=0;i<(R-M/2-1); i++)
      std::cout << "..\n";
    for(int i=0;i<M/2; i++)
      std::cout << "**\n";
    return;
  }

  //Now assume that R,C > 2.


  if((R*C-M==3) || (R*C-M==5)) {
    std::cout << "Impossible\n";
    return;
  }


  char board[MAXR][MAXC];
  for(int i=0;i<R;i++)
    for(int j=0;i<C;i++)
      board[i][j] = 0;
  if(fill(R, C, M, board)) {
    for(int i=0; i<R; i++) {
      for(int j=0; j<C; j++) 
	std::cout << board[i][j];
      std::cout << "\n";
    }
  } else {
    std::cout << "Impossible\n";
  }

}

void pre_compute() {
  
}

int main() {
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    std::cout << "Case #" << i << ":\n";
    solve();
  }

  return 0;
}
