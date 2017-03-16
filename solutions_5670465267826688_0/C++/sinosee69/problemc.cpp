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
    int L, X;
    cin >> L >> X;
    dijkstra.resize(L*X);
  
    for(int l = 0; l < L; l++) {
      char ijk;
      cin >> ijk;
      switch(ijk) {
        case 'i':
          dijkstra[l] = 2; break;
        case 'j':
          dijkstra[l] = 3; break;
        case 'k':
          dijkstra[l] = 4; break;
      }
    }

    int l = 0;
    for(int lx = L; lx < L*X; lx++) {
      dijkstra[lx] = dijkstra[l];
      l++;
    }

    //** Initial multiplication
    int mult = 100;
    if(dijkstra.size() >= 3) {
      mult = mult_table[dijkstra[0]][dijkstra[1]];
      for(int lx = 2; lx < L*X; lx++) {
        if(mult < 0)
          mult = -(mult_table[-(mult)][dijkstra[lx]]);
        else
          mult = mult_table[mult][dijkstra[lx]];
      }
    }
    //**

    if(mult == -1) {
      int i_char = 100;
      int j_char = 200;
      int k_char = 300;
      int lx = 0;

      //** i_char
      i_char = dijkstra[lx];
      lx++;
      for(; lx < L*X; lx++) {
        if(i_char == 2)
          break;

        if(i_char < 0)
          i_char = -(mult_table[-(i_char)][dijkstra[lx]]);
        else
          i_char = mult_table[i_char][dijkstra[lx]];
      }
  
      //** j_char
      if(lx < L*X) {
        j_char = dijkstra[lx];
        lx++;
        for(; lx < L*X; lx++) {
          if(j_char == 3)
            break;

          if(j_char < 0)
            j_char = -(mult_table[-(j_char)][dijkstra[lx]]);
          else
            j_char = mult_table[j_char][dijkstra[lx]];
        }
      }

      if(lx < L*X) {
        k_char = dijkstra[lx];
        lx++;
        for(; lx < L*X; lx++) {
          if(k_char == 4)
            break;

          if(k_char < 0)
            k_char = -(mult_table[-(k_char)][dijkstra[lx]]);
          else
            k_char = mult_table[k_char][dijkstra[lx]];
        }
      }

      if(i_char == 2 && j_char == 3 && k_char == 4)
        cout << "Case #" << t+1 << ": YES" << endl; 
      else
        cout << "Case #" << t+1 << ": NO" << endl;

    } else { cout << "Case #" << t+1 << ": NO" << endl; }
  }
}
