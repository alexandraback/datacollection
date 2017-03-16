#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;

int main() {
  int T;
  cin >> T;
  vector<int> dijkstra;

  int mult_table[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1}
  };

  for(int t = 0; t < T; t++) {
    unsigned long long L, X;
    cin >> L >> X;
    unsigned long long LX = L*X;
    unsigned long long mod8 = X % 8;
    
      
    dijkstra.resize(L);
  
    char ijk_char;
    int ijk_int;
    int neg_one = 1;
    for(unsigned long long l = 0; l < L; l++) {
      cin >> ijk_char;

      switch(ijk_char) {
        case 'i':
          ijk_int = 2; break;
        case 'j':
          ijk_int = 3; break;
        case 'k':
          ijk_int = 4; break;
      }

      dijkstra[l] = ijk_int;

      if(neg_one < 0)
        neg_one = -(mult_table[-(neg_one)][ijk_int]);
      else
        neg_one = mult_table[neg_one][ijk_int];
    }

    if(LX < 3) {
      cout << "Case #" << t+1 << ": NO" << endl;
      continue;
    }

    //** Initial multiplication
    int neg_mult = 1;
    for(unsigned long long n = 0; n < mod8; n++) {
      if(neg_one < 0) {
        if(neg_mult < 0)
          neg_mult = mult_table[-(neg_mult)][-(neg_one)];
        else
          neg_mult = -(mult_table[neg_mult][-(neg_one)]);
      }
      else {
        if(neg_mult < 0)
          neg_mult = -(mult_table[-(neg_mult)][neg_one]);
        else
          neg_mult = mult_table[neg_mult][neg_one];
      }
    }
    //**

    if(neg_mult == -1) {
      int i_char = 1; 
      int j_char = 1;
      int k_char = 1;

      unsigned long long str_p = 0;
      unsigned long long overall = 0;

      for(unsigned long long n = 0; n < mod8; n++) {
        unsigned long long lx = str_p;
        for(unsigned long long ind = 0; ind < L; ind++) {
          if(i_char == 2 || overall == LX)
            break;

          if(i_char < 0)
            i_char = -(mult_table[-(i_char)][dijkstra[(ind + str_p) % L]]);
          else
            i_char = mult_table[i_char][dijkstra[(ind + str_p) % L]];

          lx = (lx + 1) % L;
          overall++;
        }
        if(i_char == 2 || overall == LX) {
          str_p = lx;
          break;
        }
      }

      for(unsigned long long n = 0; n < mod8; n++) {
        unsigned long long lx = str_p;
        for(unsigned long long ind = 0; ind < L; ind++) {
          if(j_char == 3 || overall == LX)
            break;

          if(j_char < 0)
            j_char = -(mult_table[-(j_char)][dijkstra[(ind + str_p) % L]]);
          else
            j_char = mult_table[j_char][dijkstra[(ind + str_p) % L]];

          lx = (lx + 1) % L;
          overall++;
        }
        if(j_char == 3 || overall == LX) {
          str_p = lx;
          break;
        }
      }

      for(unsigned long long n = 0; n < mod8; n++) {
        unsigned long long lx = str_p;
        for(unsigned long long ind = 0; ind < L; ind++) {
          if(k_char == 4 || overall == LX)
            break;

          if(k_char < 0)
            k_char = -(mult_table[-(k_char)][dijkstra[(ind + str_p) % L]]);
          else
            k_char = mult_table[k_char][dijkstra[(ind + str_p) % L]];

          lx = (lx + 1) % L;
          overall++;
        }
        if(k_char == 4 || overall == LX) {
          str_p = lx;
          break;
        }
      }

      if(i_char == 2 && j_char == 3 && k_char == 4)
        cout << "Case #" << t+1 << ": YES" << endl; 
      else
        cout << "Case #" << t+1 << ": NO" << endl;

    } else { cout << "Case #" << t+1 << ": NO" << endl; }
    dijkstra.clear();
  }
}
