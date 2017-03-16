#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <bitset>
#include <functional>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void solve(int ind) {
    int N, M;
    cin >> N;
    vector<vector<int> > edges(N);
    for (int i = 0; i < N; ++i) {
      cin >> M;
      edges[i] = vector<int>(M);
      for (int j = 0; j < M; ++j) {
        cin >> edges[i][j];
        edges[i][j]--;
      }
    }
    //calc
    bool diamond = false;
    for (int i = 0; i < N && !diamond; ++i) {
      if (edges[i].size() > 1) {
        // check if there is a diamond ending in this vertex
        vector<bool> visited(N, false);
        visited[i] = true;
        queue<int> to_visit;
        to_visit.push(i);
        while (to_visit.size() > 0 && !diamond) {
          int cur = to_visit.front();
          to_visit.pop();
          for (int j = 0; j < edges[cur].size(); ++j) {
            if (visited[edges[cur][j]]) {
              diamond = true;
              break;
            }
            visited[edges[cur][j]] = true;
            to_visit.push(edges[cur][j]);
          }
        }
      }
    }
    //output
    cout << "Case #" << ind << ": " << (diamond ? "Yes" : "No") << endl;
}

int main() {
    int i, T;
    cin >> T;
    string st;
    getline(cin, st);
    for (i=1; i<=T; i++) {
        solve(i);
    }
}
