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
  if(at == stop) {
    if(works(placed, bffs, stop))
      return true;
    return false;
  }

  for(int i = 0; i < n; i++) {
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
    int doot[10];
    bool used[10] = {false};
    for(int i = 10; i >= 1; i--) {
      if(permWorks(doot, used, bffs, 0, i, n)) {
        cout << i;
        // cout << endl << i << endl;
        break;
      }
    }

    delete bffs;
    cout << endl;
  }
}

