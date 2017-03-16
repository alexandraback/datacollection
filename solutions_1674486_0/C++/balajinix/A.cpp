#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct _node {
  vector<int> roads;
  set<int> sources;
} Node;

bool found=false;

int DFS(vector<Node>& nodes, int current, int source) {
  if (nodes[current].sources.find(source) != nodes[current].sources.end()) {
    found = true;
    cout << ": Yes" << endl;
    return 1;
  }
  nodes[current].sources.insert(source);
  for (int i=0;i<nodes[current].roads.size();i++) {
    DFS(nodes, nodes[current].roads[i], source);
    if (found)
      break;
  }
  return 0;
}

int main() {
  string line;
  stringstream ss;
  int T = 0;
  getline(cin, line);
  ss << line;
  ss >> T;
  ss.clear();

  for (int t=1;t<=T;t++) {
    found = false;
    getline(cin, line);
    ss << line;
    int N=0;
    ss >> N;
    ss.clear();
    vector<Node> nodes;
    Node node;
    nodes.push_back(node);
    for (int n=1;n<=N;n++) {
      getline(cin, line);
      ss << line;
      int M=0;
      ss >> M;
      int road=0;
      Node node;
      for (int m=0;m<M;m++) {
        ss >> road;
        node.roads.push_back(road);
      }
      ss.clear();
      nodes.push_back(node);
    }
    cout << "Case #" << t;
    for (int n=1;n<=N;n++) {
      for (int i=0;i<nodes[n].roads.size();i++) {
        DFS(nodes, nodes[n].roads[i], n);
        if (found)
          break;
      } 
      if (found)
        break;
    }
    if (!found)
      cout << ": No" << endl;
  }

  return 0;
}

