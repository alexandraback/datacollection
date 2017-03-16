#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <bitset>
#include <functional>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

vector<int> a;

void print_mask(int mask, int N) {
  for (int i = 0; i < N; ++i) {
    if (mask & (1 << i)) {
      cout << a[i] << " ";
    }
  }
  cout << endl;
}

void solve(int ind) {
    int N;
    cin >> N;
    a = vector<int>(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
    }
    //just try all possible subsets as masks
    map<int, vector<int> > subsets;
    for (int i = 1; i < (1 << N) - 1; ++i) {
        int sum = 0;
        for (int k = 0; k < N; ++k) {
          if (i & (1 << k)) {
            sum += a[k];
          }
        }
        subsets[sum].push_back(i);
    }
    //figure out answer
    int mask1, mask2;
    bool found = false;
    map<int, vector<int> >::iterator it;
    for (it = subsets.begin(); (it != subsets.end()) && (!found); ++it) {
      if (it->second.size() > 1) {
        for (int i = 0; i < it->second.size() && !found; ++i) {
          for (int j = i+1; j < it->second.size() && !found; ++j) {
            if (it->second[i] & it->second[j] == 0) {
              continue;
            }
            found = true;
            mask1 = it->second[i];
            mask2 = it->second[j];
          }
        }
      }
    }
    //output
    cout << "Case #" << ind << ":" << endl;
    if (!found) {
      cout << "Impossible" << endl;
    } else {
      //restore bits in each mask
      print_mask(mask1, N);
      print_mask(mask2, N);
    }
}

int main() {
    int i,T;
    cin >> T;
    string st;
    getline(cin, st);
    for (i=1; i<=T; i++) {
        solve(i);
    }
}
