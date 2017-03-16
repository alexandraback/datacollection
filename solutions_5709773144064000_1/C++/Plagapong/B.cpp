/*
ID: Plagapong
LANG: C++
TASK: B
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999

using namespace std;
double c, f, x;

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  
}

void process() {
  // Code here!
  cin >> c >> f >> x;
  double answer = 0, rate = 2;
  while (true) {
    if (x/rate <= c/rate + x/(rate+f)) {
      // Enough
      cout << fixed << setprecision (7) << (answer + x/rate);
      return;
    } else {
      answer += c/rate;
      rate += f;
    }
  }
}

int main() {
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
