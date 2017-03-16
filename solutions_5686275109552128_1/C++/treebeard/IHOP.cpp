/*
 * =============================================================================
 *
 *       Filename:  IHOP.cpp
 *
 *    Description:  Infinite House of Pancakes
 *
 *        Created:  04/10/2015 11:59:24 PM
 *       Compiler:  gcc/g++
 *
 *         Author:  Lawrence Wu (llwu), llwu@mit.edu
 *   Organization:  Massachusetts Institute of Technology
 *
 * =============================================================================
 */

#include <iostream>

using namespace std;

int s_opt[1001][1001]; // splits required to bring height i stack to height j

int main()
{
  for(int i = 1; i <= 1000; i++)
    for(int j = i; j <= 1000; j++)
      s_opt[i][j] = 0;
  for(int i = 2; i <= 1000; i++)
    for(int j = 1; j < i; j++) {
      s_opt[i][j] = i-j;
      for(int k = 1; k <= i-k; k++)
        if(1+s_opt[k][j]+s_opt[i-k][j] < s_opt[i][j])
          s_opt[i][j] = 1+s_opt[k][j]+s_opt[i-k][j];
    }
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    int m_opt[1001] = { 0 }; // splits required to bring pancakes to height k
    int D;
    cin >> D;
    for(int j = 0; j < D; j++) {
      int P;
      cin >> P;
      for(int k = 1; k <= 1000; k++)
        m_opt[k] += s_opt[P][k];
    }
    int minutes = (1 << 28);
    for(int k = 1; k <= 1000; k++)
      if(m_opt[k] + k < minutes)
        minutes = m_opt[k] + k;
    cout << "Case #" << i << ": " << minutes << '\n';
  }
  return 0;
}
