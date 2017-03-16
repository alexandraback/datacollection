#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void generate(int index, const string& original, string candidate, vector<string>& candidates) {
  if (index >= original.size()) {
    candidates.push_back(candidate);
    return;
  }
  if (original[index] != '?') {
    string newCandidate = candidate + original[index];
    generate(index + 1, original, newCandidate, candidates);
  } else {
    for (int i = 0; i < 10; i++) {
      string newCandidate = candidate + (char)('0' + i);
      generate(index + 1, original, newCandidate, candidates);
    }
  }
}

int main() {
  int t; cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    string c,j;
    cin >> c >> j;

    vector<string> cCandidates(0);
    vector<string> jCandidates(0);

    generate(0, c, "", cCandidates);
    generate(0, j, "", jCandidates);

    sort(cCandidates.begin(), cCandidates.end());
    sort(jCandidates.begin(), jCandidates.end());

    int diff = 1000000;

    string ansC = "";
    string ansJ = "";
    for (int i = 0; i < cCandidates.size(); i++) {
      for (int j = 0; j < jCandidates.size(); j++) {
	stringstream ss;
	ss << cCandidates[i];
	int cc, cj;
	ss >> cc;
	ss.str("");
	ss.clear(stringstream::goodbit);

	ss <<  jCandidates[j];
	ss >> cj;
	int d = abs(cj-cc);
	if (d < diff) {
	  ansC = cCandidates[i];
	  ansJ = jCandidates[j];
	  diff = d;
	}
      }
    }
    cout << "Case #" << tc << ": " << ansC << " " << ansJ << endl;
  }
}
