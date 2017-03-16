/*
ID: Plagapong
LANG: C++
TASK: recycled
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999

using namespace std;
int a, b;
int mutant[10];

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  
}

void process() {
  // Code here!
  cin >> a >> b;
  // First, find the number of digits
  int n = 0, ten2n = 1;
  long long cnt = 0;
  while (ten2n <= a) {
    ten2n *= 10;
    n++;
  }
  // Then, brute force
  while (a <= b) {
    mutant[0] = a;
    for (int i = 1; i < n; i++) {
      int tod = mutant[i-1] * 10 / ten2n;
      mutant[i] = mutant[i-1] * 10 - tod * ten2n + tod;
      if (mutant[i] > a && mutant[i] <= b) {
        int j;
        for (j = 0; j < i; j++) {
          if (mutant[j] == mutant[i]) {
            break;
          }
        }
        if (j == i) {
          // Not repeated
          cnt++;
        }
      }
    }
    a++;
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
