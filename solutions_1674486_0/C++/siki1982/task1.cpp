#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>


using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long
#define UI unsigned int



void findroots(int i, vector<vector<int> > &graph, vector<set<int> > &roots) {
  if (graph[i].size() == 0) {
    return;
  }
  if (roots[i].size() > 0) return;

  for (int j = 0; j < graph[i].size(); ++j) {
    int parent = graph[i][j] - 1;
    roots[i].insert(parent);
    if (roots[parent].size() > 0) {
      for (set<int>::iterator it = roots[parent].begin(); it != roots[parent].end(); ++it) {
        roots[i].insert(*it);
      }
    } else {
      findroots(parent, graph, roots);
      for (set<int>::iterator it = roots[parent].begin(); it != roots[parent].end(); ++it) {
        roots[i].insert(*it);
      }

    }
  }
}

bool check(int i , int j, vector<set<int> > &roots) {
  set<int>::iterator it1, it2;
  it1 = roots[i].begin();
  it2 = roots[j].begin();

  while (it1 != roots[i].end() || it2 != roots[j].end()) {
    if (it2 == roots[j].end() || (it1 != roots[i].end() && *it1 < *it2)) {
      ++it1;
      //cerr << "it1" << endl;
    } else if (it1 == roots[i].end() || (it2 != roots[j].end() && *it2 < *it1)) {
      ++it2;
      //cerr << "it2" << endl;
    } else {
      //cerr << "haha" << endl;
      return true;
    }
  }
  return false;
}

int main() {
  // Declare members
  int num_case;
  cin >> num_case;

  vector<vector<int> > graph;
  vector<set<int> > roots;
  int N, M;


  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    graph.clear();
    roots.clear();
    cin >> N;

    graph.resize(N);
    roots.resize(N);

    for (int i = 0; i < N; ++i) {
      cin >> M;
      graph[i].resize(M);
      for (int j = 0; j < M; ++j) {
        cin >> graph[i][j];
      }
    }

    for (int i = 0; i < N; ++i) {
      findroots(i, graph, roots);
    }
    for (int i = 0; i < N; ++i) {
      roots[i].insert(i);
    }

    for (int i = 0; i < N; ++i) {
      for (set<int>::iterator it = roots[i].begin(); it != roots[i].end(); ++it) {
        //cerr << " " << *it;
      }
      //cerr << endl;
    }


    bool t = false;
    for (int i = 0; i < N; ++i) {
      if (graph[i].size() == 0) continue;
      for (int j = 0; j < graph[i].size() - 1; ++j) {
        //cerr << "2: " << j << " " << graph[i].size() << endl;
        for (int k = j + 1; k < graph[i].size(); ++k) {
          //cerr << "check" << endl;
          t = check(graph[i][j] - 1, graph[i][k] - 1, roots);
          if (t) break;
        }
        if (t) break;
      }
      if (t) break;
    }




    // Print output for case j
    cout << "Case #" << nc << ": " << (t?"Yes":"No") << endl;
  }


  return 0;
}
