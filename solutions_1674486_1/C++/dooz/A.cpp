#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>

using namespace std;


void diamond(int argc, char* argv[])
{
  int num_tests;
  cin >> num_tests;

  for (int i = 0; i < num_tests; ++i) {

    map<int, vector<int>> graph;

    int num_classes;
    cin >> num_classes;
    for (int j = 0; j < num_classes; ++j) {
      int num_inherit;
      cin >> num_inherit;
      for (int k = 0; k < num_inherit; ++k) {
        int parent;
        cin >> parent;
        graph[parent].push_back(j+1);
      }
    }

    bool found_cycle = false;
    for (int j = 0; j < num_classes; ++j) {
      stack<int> unvisited;
      set<int> visited;
      unvisited.push(j+1);
      while (!unvisited.empty()) {
        int parent = unvisited.top();
        unvisited.pop();
        auto it = visited.find(parent);
        if (it != visited.end()) {
          // cycle
          found_cycle = true;
          goto done;
        }
        visited.insert(parent);
        auto jj = graph.find(parent);
        if (jj != graph.end()) {
          const vector<int> &children = jj->second;
          for (int k = 0; k < (int)children.size(); ++k) {
            unvisited.push(children[k]);
          }
        }
      }
    }

done:;
    printf("Case #%d: %s\n", i + 1, found_cycle ? "Yes" : "No");

  }


}


int main(int argc, char* argv[])
{
  diamond(argc, argv);
  return 0;
}
