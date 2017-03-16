
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator> 
#include <cmath>
#include <set> 

using namespace std;

int main() {
  int T; 
  cin >> T;
  for (int i=0; i<T; i++) {
    int N; 
    cin >> N;
    vector<int> onestar;
    vector<int> twostar;
    for (int j=0; j<N; j++) {
      int a, b;
      cin >> a >> b;
      onestar.push_back(a);
      twostar.push_back(b);
    }
    int stars = 0;
    bool isDone = false;
    bool madeProgress = true;
    int turns = 0;
    while(true) {

      for (int k=0; k<N; k++) {
        //cout << onestar[k] << "," << twostar[k] << endl;
      } 

      madeProgress = false;
      int maxone = -1;
      for (int k=0; k<N; k++) {
        if (twostar[k] <= stars 
          && twostar[k] != -1 
          && (maxone == -1 || onestar[maxone] < onestar[k])) {
          maxone = k;
        }
      }

      if(maxone != -1) {
        turns++;
        madeProgress = true;
        twostar[maxone] = -1;

        if(onestar[maxone] == -1) {
          stars += 1;
        } else {
          onestar[maxone] = -1;
          stars += 2;
        }
        continue;
      }
      
      int maxtwo = -1;
      for (int k=0; k<N; k++) {
        if (onestar[k] <= stars && onestar[k] != -1
          && (maxtwo == -1 || twostar[maxtwo] < twostar[k] || twostar[k] == -1)) {
          maxtwo = k;
          if (twostar[k] == -1) break;
        }
      }
      if (maxtwo != -1) {
        turns++;
        madeProgress = true;
        onestar[maxtwo] = -1;
        stars += 1;
        continue;
      }

      int score = 0;
      for (int k=0; k<N; k++) {
        score += onestar[k] + twostar[k];
      } 
      isDone = (score == -2 * N);
      break;
    }
    if (isDone)
      cout << "Case #" << i+1 << ": " << turns << endl;
    else
      cout << "Case #" << i+1 << ": Too Bad" << endl;
  }
  return 0;
}

