/*
 * =============================================================================
 *
 *       Filename:  Dijkstra.cpp
 *
 *    Description:  Dijkstra
 *
 *        Created:  04/11/2015 01:36:03 AM
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

#define I (2)
#define J (3)
#define K (4)

const int mult_table[4][4] = {{1,I,J,K}, // 1 -> 1, 2 -> i, 3 -> j, 4 -> k
                        {I,-1,K,-J},
                        {J,-K,-1,I},
                        {K,J,-I,-1}};

int sgn(int x) { if(x > 0) return 1; else return -1; }

int mult(int a, int b)
{
  return mult_table[abs(a)-1][abs(b)-1]*sgn(a)*sgn(b);
}

int parse(char c)
{
  switch(c) {
    case '1': return 1; break;
    case 'i': return I; break;
    case 'j': return J; break;
    case 'k': return K; break;
    default: return 1;
  }
}

int main()
{
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    int L, X;
    cin >> L >> X;
    cin.ignore();
    int seq[10000];
    for(int j = 0; j < L; j++) {
      char c;
      cin >> c;
      seq[j] = parse(c);
    }
    int prod_once = 1, prod_total = 1;
    for(int j = 0; j < L; j++) prod_once = mult(prod_once, seq[j]);
    for(int j = 0; j < (X % 4); j++) prod_total = mult(prod_total, prod_once);
    string ans = "NO";
    if(prod_total == -1) {
      bool first_split = false;
      int running_prod = 1;
      for(int j = 0; j < min(8,X); j++)
        for(int k = 0; k < L; k++) {
          running_prod = mult(running_prod, seq[k]);
          if(running_prod == I) first_split = true;
          if(first_split && running_prod == K) ans = "YES";
        }
    }
    cout << "Case #" << i << ": " << ans << '\n';
  }
  return 0;
}
