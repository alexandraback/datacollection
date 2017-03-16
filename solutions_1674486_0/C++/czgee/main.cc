#include <iostream>
#include <fstream>

#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;


int main() {
  //ifstream input("A-small.in", ifstream::in);
  ifstream input("A-small-attempt1.in", ifstream::in);
  //ifstream input("A-large.in", ifstream::in);
  ofstream output("problem-a.out", ofstream::out);

  int caseCount;
  input >> caseCount;
  
  for (int caseId = 1; caseId <= caseCount; ++caseId) {
    int classes;
    input >> classes;

    vector<pair<int, vector<int>>> graph;

    for (int classId = 0; classId < classes; classId++) {
      int inheritsFrom;
      input >> inheritsFrom;

      graph.push_back(make_pair(-1, vector<int>()));

      for (int i = 0; i < inheritsFrom; i++ ) {
        int tmp;
        input >> tmp;
        graph[classId].second.push_back(tmp - 1);
      }
    }

    bool diamondFound = false;

    function<void (int, int)> colorUp = [&](int start, int origin) {
      if (diamondFound) return;

      if (graph[start].first == origin) {
        diamondFound = true;
        return;
      } else {
        graph[start].first = origin;

        for (int parent: graph[start].second) {
          colorUp(parent, origin);
        }
      }
    };

    
    for (int classId = 0; classId < classes; classId++) {
      colorUp(classId, classId);
    }

    output << "Case #" << caseId << ": " << (diamondFound ? "Yes" : "No") << endl;
  }

  return 0;
}