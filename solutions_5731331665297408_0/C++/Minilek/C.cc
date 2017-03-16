#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
#include <stdlib.h>
using namespace std;
int nextv;
vector<int> v;
int perm[8];
char adj[51][51];
int zips[51], n, m;
string zipstr[51], ret;
void dfs(int x) {
  ret += zipstr[x];
  while (1) {
    if (nextv==n || !adj[x][perm[v[nextv]]])
      return;
    else {
      nextv++;
      dfs(perm[v[nextv-1]]);
    }
  }
}

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  for (int rr = 1; rr <= nocases; ++rr) {
    memset(adj, 0, sizeof(adj));
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> zipstr[i];
      zips[i] = atoi(zipstr[i].c_str());
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      adj[x][y] = adj[y][x] = 1;
    }
    if (n==1) {
      printf("Case #%d: %s\n", rr, zipstr[0].c_str());
      continue;
    }
    vector< pair<int, int> > vv;
    for (int i = 0; i < n; ++i)
      vv.push_back(make_pair(zips[i], i));
    sort(vv.begin(), vv.end());
    for (int i = 0; i < n; ++i)
      perm[i] = vv[i].second;
    v = vector<int>(n, 0);
    for (int i = 0; i < n; ++i)
      v[i] = i;
    do {
      if (v[0] != 0) continue;
      ret = "";
      nextv = 1;
      dfs(perm[0]);
      if (nextv == n) {	
	printf("Case #%d: %s\n", rr, ret.c_str());
	break;
      }
    } while (next_permutation(v.begin(), v.end()));
  }
  return 0;
}
