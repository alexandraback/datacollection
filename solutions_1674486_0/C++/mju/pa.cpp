#include <iostream>
#include <list>
#include <vector>
#include <fstream>

#define MAX_NUM_NODES 1000

using namespace std;

bool
dfs(int node, vector<list<int> >& graph, vector<int>& num_visits) {
  list<int>::iterator ibegin = graph[node].begin();
  const list<int>::iterator iend = graph[node].end();
  for (; ibegin != iend; ibegin++) {
    num_visits[*ibegin]++;
    if (num_visits[*ibegin] > 1) {
      return true;
    }
    if (dfs(*ibegin, graph, num_visits)) {
      return true;
    }
  }
  return false;
}

int
main(int argc, char** argv) {
  fstream fin, fout;
  fin.open("pa.in", ios::in);
  fout.open("pa.out", ios::out);

  int num_cases, c;
  int num_nodes;
  int num_children;
  int child;
  bool found;
  vector<list<int> > graph(MAX_NUM_NODES + 1);
  vector<int> num_parents(MAX_NUM_NODES + 1);
  vector<int> num_visits(MAX_NUM_NODES + 1);

  fin >> num_cases;

  int i, j;
  for (c = 1; c <= num_cases; c++) {
    found = false;
    fin >> num_nodes; 
    for (i = 1; i <= num_nodes; i++) {
      graph[i].clear();
      num_parents[i] = 0;
    }
    for (i = 1; i <= num_nodes; i++) {
      fin >> num_children;
      for (j = 0; j < num_children; j++) {
        fin >> child;
        num_parents[child]++;
        graph[i].push_back(child);
      }
    }
    for (i = 1; i <= num_nodes; i++) {
      if (num_parents[i] == 0) {
        // dfs
        for (j = 1; j <= num_nodes; j++) {
          num_visits[j] = 0;
        }
        if (dfs(i, graph, num_visits)) {
          found = true;
          break;
        }
      }
    }
    if (!found) {
      fout << "Case #" << c << ": No" << endl;
    } else {
      fout << "Case #" << c << ": Yes" << endl;
    }
  }

  fout.close();
  fin.close();

  return 0;
}
