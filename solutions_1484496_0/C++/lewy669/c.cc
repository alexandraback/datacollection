/*
 * =====================================================================================
 *
 *       Filename:  c.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05.05.2012 19:35:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>


#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;




const int MAX_N = 3000000;
vector<int> byl[MAX_N];

int in[25];

int main() {

  int t;
  cin >> t;
  for(int p = 0; p < t; ++p) {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> in[i];
    }
    cout<< "Case #" << (p + 1) << ":" << endl;

    bool ret = false;
    for(int i = 1; i < (1 << (n)); ++i) {
      int s = 0;
      int ic = i;
      vector<int> r;
      for(int j = 0; j < n; ++j) {
        if(ic % 2 == 1){
          s += in[j];
          r.push_back(in[j]);
        }
        ic /= 2;
      }

      if(byl[s].size() > 0) {
        for(int i = 0; i < byl[s].size(); ++i) {
          cout << byl[s][i] << ' ';
        }
        cout << endl;
        for(int i = 0; i < r.size(); ++i) {
          cout << r[i] << ' ';
        }
        cout << endl;
        ret = true;
        break;
      } else {
        byl[s] = r;
      }
    }
    if(!ret) {
      cout << "Impossible" << endl;
    }
      for(int i = 0; i < MAX_N; ++i) {
        byl[i].clear();
      }
  }
}
