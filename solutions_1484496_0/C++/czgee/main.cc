#include <iostream>
#include <fstream>

#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

void generateSubsets(int presum, vector<int>& setin, int begin, vector<int> prev, vector<pair<int, vector<int>>>& subsets) {
  for(int start = begin; start < setin.size(); ++start) {
    int newpresum = presum + setin[start];
    vector<int> newprev = prev;
    newprev.push_back(setin[start]);

    subsets.push_back(make_pair(newpresum, newprev));
    if (subsets.size() % 100000 == 0) cout << subsets.size() << endl;
    if (start + 1 < setin.size()) generateSubsets(newpresum, setin, start + 1, newprev, subsets);
  }
}

int main() {
  //ifstream input("C-small.in", ifstream::in);
  ifstream input("C-small-attempt0.in", ifstream::in);
  ofstream output("problem-c.out", ofstream::out);

  int caseCount;
  input >> caseCount;
  
  for (int caseId = 1; caseId <= caseCount; ++caseId) {
    int n;
    input >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      int tmp;
      input >> tmp;
      nums.push_back(tmp);
    }

    vector<pair<int, vector<int>>> subsets;
    vector<int> prev;

    generateSubsets(0, nums, 0, prev, subsets);

    output << "Case #" << caseId << ":" << endl;

    bool found = false;

    for (auto ita = begin(subsets); !found && ita != end(subsets); ++ita) {
      for (auto itb = begin(subsets); !found && itb != end(subsets); ++itb) {
        if (ita == itb) continue;
        if ((*ita).first == (*itb).first) {
          for (auto suba = begin((*ita).second); suba != end((*ita).second); ++suba) {
            output << " " << *suba;
          }
          output << endl;
          for (auto subb = begin((*itb).second); subb != end((*itb).second); ++subb) {
            output << " " << *subb;
          }
          output << endl;
          found = true;
        }
      }
    }

    if (!found) {
      output << "Impossible" << endl;
    }
    
  }

  return 0;
}