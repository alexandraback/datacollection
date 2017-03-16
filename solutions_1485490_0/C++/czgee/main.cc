#include <iostream>
#include <fstream>

#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <map>
#include <cstdint>

using namespace std;


int main() {
  //ifstream input("C-small.in", ifstream::in);
  ifstream input("C-small-attempt5.in", ifstream::in);
  //ifstream input("C-large.in", ifstream::in);
  ofstream output("problem-c.out", ofstream::out);

  int caseCount;
  input >> caseCount;
  
  for (int caseId = 1; caseId <= caseCount; ++caseId) {
    uint64_t n, m;
    input >> n >> m;

    deque<pair<uint64_t, int>> a, b;
    
    for (uint64_t i = 0; i < n; i++) {
      uint64_t tmpa;
      int tmpb;
      input >> tmpa >> tmpb;
      a.push_back(make_pair(tmpa, tmpb));
    }

    for (uint64_t i = 0; i < m; i++) {
      uint64_t tmpa;
      int tmpb;
      input >> tmpa >> tmpb;
      b.push_back(make_pair(tmpa, tmpb));
    }

    /*vector<tuple<int, int, int>> mix; //a, b, val

    while (a.empty() && b.empty()) {
      int val = min(a.front().first, b.front().first);
      mix.push_back(make_tuple(a.front().second, b.front().second, val));

      if (val == a.front().first) {
        a.pop_front();
      } else {
        a.front().first -= val;
      }

      if (val == b.front().first) {
        b.pop_front();
      } else {
        b.front().first -= val;
      }
    }*/

    //swap(a, b);

    vector<tuple<uint64_t, int, uint64_t>> nejdelsiDo;
    for (int i = 0; i < (int)a.size(); i++) {
      nejdelsiDo.push_back(make_tuple(0, -1, 0));
    }

    for (int j = 0; j < (int)b.size(); j++) {
      // find max from this
      int typ = b[j].second;
      uint64_t zbyva = b[j].first;
      uint64_t prevValue = 0;
      for (int i = 0; i < (int)a.size(); i++) {
        uint64_t thisValue = max(prevValue, get<0>(nejdelsiDo[i]));

        if (prevValue > get<0>(nejdelsiDo[i])) {
          if (i > 0) {
            get<1>(nejdelsiDo[i]) = get<1>(nejdelsiDo[i - 1]);
            get<2>(nejdelsiDo[i]) = get<2>(nejdelsiDo[i - 1]);
          }
        } else {
          zbyva = b[j].first;
        }

        if ((typ == a[i].second) && (get<1>(nejdelsiDo[i]) <= i)) {
          uint64_t matchable = min(zbyva, a[i].first);
          uint64_t matchedbefore = 0;
          if (get<1>(nejdelsiDo[i]) == i) {
            matchable = min(matchable, a[i].first - get<2>(nejdelsiDo[i]));
            matchedbefore = get<2>(nejdelsiDo[i]);
          }
          thisValue += matchable;
          zbyva -= matchable;
          get<1>(nejdelsiDo[i]) = i;
          get<2>(nejdelsiDo[i]) = matchedbefore + matchable;
        }
        get<0>(nejdelsiDo[i]) = thisValue;
        prevValue = thisValue;
      }
    }

    uint64_t val = get<0>(nejdelsiDo.back());

    output << "Case #" << caseId << ": " << val << endl;
  }

  return 0;
}