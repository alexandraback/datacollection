#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define N 20

// map from subset sum to index
int cnt[20];

void printset(int i) {
  for (int j=0;j<N;j++) {
    if (i & (1<<j)) {
      cout << cnt[j] << " ";
    }
  }
  cout << endl;
}

void runcase() {
  map<int, int> aa;
  int Njunk;
  cin >> Njunk;
  for(int i = 0;i<N;i++) cin >> cnt[i];

  for (int i = 1; i < (1<<N);i++) {
    int sum = 0;
    for (int j=0;j<N;j++) {
      if ( (i & (1<<j)) != 0) sum += cnt[j];
    }
    std::pair<map<int, int>::iterator,bool> w = aa.insert(make_pair(sum, i));
    if (w.second == false) {
      printset(w.first->second);
      printset(i);
      return;
    }
  }
  cout << "Impossible" << endl;
  return;
}

int main(int argv, char* argc[]) {
  int case_count;
  cin >> case_count;
  for (int i = 0; i < case_count; i++) {
    cout << "Case #" << (i+1) << ":" << endl;
    runcase();
  }
}

