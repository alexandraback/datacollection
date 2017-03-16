// last word 2016

#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;

void run() {
  string input;
  getline(cin, input);
  long count = atoi(input.c_str());
  for (long i = 0; i < count; ++i) {
    getline(cin, input);
    int len = input.size();
    std::deque<char> output;
    if (len > 0) {
      output.push_back(input[0]);
    }
    for (int i = 1; i < len; ++i) {
      char c = input[i];
      if (c >= output[0]) {
	output.push_front(c);
      } else {
	output.push_back(c);
      }
    }
    string done(output.begin(), output.end());
    cout << "Case #" << (i + 1) <<": " << done << "\n";
    }
}

int main(int argc, const char* argv[]) {
  run();
}

  
