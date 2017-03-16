#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int l(int i, int len) {
  if(i == 0) return len -1;
  return i-1;
}

int r(int i, int len) {
  if(i == len - 1) return 0;
  return i + 1;
}

bool works(int placed[], int bffs[], int length) {
  if(length == 1)
    return true;
  // cout << length << ":" ;
  // int arr2[] = {6,8,2,9,3,0};
  // if(length == 6 && equal(placed, placed + 6, arr2 )) {
  //   cout << "woah";
  // }
  for(int i = 0; i < length; i++) {
    if(bffs[placed[i]] != placed[r(i, length)] && bffs[placed[i]] != placed[l(i, length)])
      return false;
  }
  return true;
}

bool permWorks(int placed[], bool used[], int bffs[], int at, int stop, int n) {
  for(int i = 0; i < at; i++) {
    // cout << placed[i] << " ";
  }
  // cout << endl;


  if(at == stop) {
    if(works(placed, bffs, stop))
      return true;
    return false;
  }

  if(at >= 2) {
    if(bffs[placed[at - 1]] != placed[at - 2] && bffs[placed[at - 1]] != placed[at])
      return false;
  }

  int start = 0, end = n;
  if(at > 0 && bffs[placed[at - 1]] != placed[at - 2]) {
    start = bffs[placed[at-1]];
    end = start + 1;
  }
  for(int i = start; i < end; i++) {
    if(!used[i]) {
      placed[at] = i;
      used[i] = true;
      if(permWorks(placed, used, bffs, at+1, stop, n))
        return true;
      used[i] = false;
    }
  }
  return false;
}

int main() {
  int lines;
  cin >> lines;
  for(int line = 1; line <= lines; line++) {
    cout << "Case #" << line << ": ";

    int n;
    cin >> n;
    int* bffs = new int[n];
    // cout << n;
    for(int i = 0; i < n; i++) {
      cin >> bffs[i];
      bffs[i]--;
    }

    //TRY NO BFFS
    int doot[1000];
    bool used[1000] = {false};
    bool current[1000] = {false};

    int bestCycle = 1;
    int cycled = 0;
    for(int i = 0; i < n; i++) {
      if(!used[i]) {

        bool current[1000] = {false};
        int j = bffs[i];

        while(j != i && !current[j]) {
          current[j] = true;
          j = bffs[j];
          // cout << j << " ";
        }
        if(j == i) {
          int cycleSize = 1;
          used[i] = true;
          int j = bffs[i];
          while(j != i) {
            used[j] = true;
            j = bffs[j];
            ++cycleSize;
          }
          cycled += cycleSize;
          bestCycle = max(bestCycle, cycleSize);
          // cout << "CYCLE!" << endl;
        }
      }
    }
    for(int i = n - cycled; i > bestCycle; i--) {
      // cout << i << endl;
      if(permWorks(doot, used, bffs, 0, i, n)) {
        // cout << "ANS:" << i;
        // cout << endl << i << endl;
        break;
      }
    }
    cout << bestCycle;

    delete bffs;
    cout << endl;
  }
}

