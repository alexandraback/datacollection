/*
 * =============================================================================
 *
 *       Filename:  OminousOmino.cpp
 *
 *    Description:  Ominous Omino
 *
 *        Created:  04/11/2015 02:24:54 AM
 *       Compiler:  gcc/g++
 *
 *         Author:  Lawrence Wu (llwu), llwu@mit.edu
 *   Organization:  Massachusetts Institute of Technology
 *
 * =============================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    int X,R,C;
    cin >> X >> R >> C;
    string answer = "RICHARD";
    if(X < 7 && // otherwise Richard can put a hole in the n-omino
        (X-1)/2+1 <= min(R,C) &&
        X <= max(R,C)) { // otherwise Richard can make one that doesn't fit
      if((X-1)/2+1 < min(R,C)) { if((R*C)%X == 0) answer = "GABRIEL"; }// contiguous
      else {
        if(X == 6 || X == 4) answer = "RICHARD"; // parity breaking
        else if (X == 5 && max(R,C) < 6) answer = "RICHARD"; 
        else if ((R*C) % X == 0) answer = "GABRIEL"; // contiguous
        else answer = "RICHARD"; // wrong num squares
      }
    }
    cout << "Case #" << i << ": " << answer << '\n';
  }
  return 0;
}
