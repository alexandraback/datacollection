#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string guess(string seq) {
  if (seq.size() <= 1)
	return seq;

  string curr = string(1, seq[0]);
  for (int i=1; i<seq.size(); i++) {
	char in = seq[i];
	if (in >= curr[0]) {
	  curr = in + curr;
	}
	else {
	  curr = curr + in;
	}
  }

  return curr;
}

int main () {
  ifstream fis("small.txt");
  string str = "";
  int round = 0;
  fis >> round;
  for(int i=1; i<=round; i++) {
	fis >> str;
	cout << "Case #" << i << ": " << guess(str) << "\n";
  }
}
