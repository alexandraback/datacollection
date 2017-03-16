#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<int> bff;
vector<bool> visited;
vector<int> longestPath;


int foo(int start) {
  int count = 1;
  int cur = bff[start];

  while (true) {
    if (cur == start) {
      break;
    }

    if (visited[cur]) {
      count = 0;

      int path = 1;
      int sec_cur = bff[start];
      while (sec_cur != cur) {
        ++path;
        sec_cur = bff[sec_cur];
      }

      if (longestPath[cur] < path)
        longestPath[cur] = path;

      break;
    }

    ++count;
    visited[cur] = true;
    cur = bff[cur];
  }
  return count;
}

int bar(int n) {
  int max = 0;
  std::vector<pair<int, int> > v;

  for (int i = 1; i <= n; ++i) {
    visited.assign(n + 1, false);
    int res = foo(i);
    if (res == 2)
      v.push_back( make_pair(i, bff[i]) );

    if (res > max)
      max = res;
  }

  for (int i = 0; i < v.size(); ++i) {
    int res = 2 + longestPath[v[i].first] + longestPath[v[i].second];
    if (res > max)
      max = res;
  }

  return max;
}

int main() {
  int t;
  int n;

  FILE *fin = NULL, *fout = NULL;
  fin = fopen("inputC.txt", "r");
  fout = fopen("outputC.txt", "w");

  fscanf(fin, "%d", &t);
  for (int i = 1; i <= t; ++i) {
    fscanf(fin, "%d", &n);
    bff.assign(n + 1, 0);
    visited.assign(n + 1, false);
    longestPath.assign(n + 1, 0);

    int tmp = 0;

    for (int j = 1; j <= n; ++j) {
      fscanf(fin, "%d", &tmp);
      bff[j] = tmp;
    }

    fprintf(fout, "Case #%d: %d\n", i, bar(n));
  } 

  fclose(fin);
  fclose(fout);
	return 0;
}