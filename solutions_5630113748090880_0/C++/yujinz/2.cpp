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
  int round = 0;

  fis >> round;
  for(int r=1; r<=round; r++) {
	int N = 0;
	fis >> N;
	vector<int> vec(2501, 0);
	for (int i=0; i<N*(2*N-1); i++) {
	  int height = 0;
	  fis >> height;
	  vec[height] += 1;
	}
	vector<int> row;

	for (int i=1; i<2501; i++) {
	  if (vec[i] % 2 != 0)
		row.push_back(i);
	}
	sort(row.begin(), row.end());

	cout << "Case #" << r << ": ";

	for (int i=0; i<row.size(); i++) {
	  cout << row[i] << " ";
	}
	cout << "\n";
  }
}
