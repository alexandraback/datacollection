/*
 * =============================================================================
 *
 *       Filename:  StandingOvation.cpp
 *
 *    Description:  Standing Ovation
 *
 *        Created:  04/10/2015 11:40:34 PM
 *       Compiler:  gcc/g++
 *
 *         Author:  Lawrence Wu (llwu), llwu@mit.edu
 *   Organization:  Massachusetts Institute of Technology
 *
 * =============================================================================
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    int smax;
    string shyness;
    cin >> smax >> shyness;
    int adjusted = 0, gaps = 0;
    for(int j = 0; j <= smax; j++) {
      adjusted += shyness[j] - '0';
      if(adjusted == 0) gaps++; else adjusted--;
    }
    cout << "Case #" << i << ": " << gaps << '\n';
  }
  return 0;
}
