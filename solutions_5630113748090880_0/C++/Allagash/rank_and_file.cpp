// last word 2016

#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

void run() {
  string input;
  getline(cin, input);
  long count = atoi(input.c_str());
  for (long i = 0; i < count; ++i) {
    int n;
    cin >> n;
    unordered_map<int, int> hash;
    for (long j = 0; j < (2*n - 1); ++j) {
      for (long k = 0; k < n; ++k) {
	int height;
	cin >> height;
	int val = hash[height];
	hash[height] = (val + 1);
      }
    }
    vector<int> output;
    for (auto x : hash) {
      if (x.second % 2 == 1) { // old
	output.push_back(x.first);
      }
    }
    sort(output.begin(), output.end());
    cout << "Case #" << (i+1) << ":";
    for (auto y : output) {
      cout << " " << y;
    }
    cout << "\n";
  }
}

int main(int argc, const char* argv[]) {
  run();
}

  
