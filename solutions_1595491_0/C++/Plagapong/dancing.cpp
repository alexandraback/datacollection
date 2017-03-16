/*
ID: Plagapong
LANG: C++
TASK: dancing
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999

using namespace std;
int n, s, p;

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  
}

void process() {
  // Code here!
  cin >> n >> s >> p;
  int t, cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t <= 1) {
      if ((t == 0 && p == 0) || (t == 1 && p <= 1)) {
        cnt++;
      }
    } else if (t >= 29) {
      cnt++;
    } else {
      if (t >= 3 * p - 2) {
        cnt++;
      } else if (t >= 3 * p - 4 && s > 0) {
        s--;
        cnt++;
      }
    }
  }
  cout << cnt;
}

int main(int argc, const char* argv[]) {
  preprocess();
  int times;
  cin >> times;
  for (int i = 1; i <= times; i++) {
	cout << "Case #" << i << ": ";
	clearVars();
	process();
	cout << endl;
  }
  return 0;
}
