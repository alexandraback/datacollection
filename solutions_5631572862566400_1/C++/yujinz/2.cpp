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

struct entry {
  int len = 0;
  int endid = 0;
  bool done = false;
};

int main () {
  ifstream fis("small.txt");
  int round = 0;

  fis >> round;
  for(int r=1; r<=round; r++) {
	int N = 0;
	fis >> N;
	vector<vector<int> > pointing(N+1);
	vector<entry> chainlen(N+1);
	for (int i=1; i<N+1; i++) {
	  int bff;
	  fis >> bff;
	  pointing[bff].push_back(i);
	  chainlen[bff].len = 1;
	}

	int done_points = 0;

	while (done_points < N) {
	  for (int i=1; i<N+1; i++) {
		if (!chainlen[i].done) {
		  int maxlen = chainlen[i].len;
		  int _endid = 0;
		  int endsum = 0;
		  for (int j=0; j<pointing[i].size(); j++) {
			int ilen = chainlen[i].len + chainlen[pointing[i][j]].len;
			endsum += chainlen[pointing[i][j]].len;
			if (ilen > maxlen) {
			  maxlen = ilen;
			  _endid = j;
			}
		  }

		  if (chainlen[i].endid == i) {
			chainlen[i].done = true;
			chainlen[i].len = maxlen - 1;
			done_points ++;
		  }
		  else {
			chainlen[i].len = maxlen;
			if (endsum==0) {
			  chainlen[i].done = true;
			  done_points ++;
			}
		  }
		  chainlen[i].endid = _endid;
		}
	  }
	}

	cout << "Case #" << r << ": ";

	cout << "\n";
  }
}
