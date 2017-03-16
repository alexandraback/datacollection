#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include "graph.h"

using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::set;
using std::endl;
using std::cout;
using std::map;
#define MAX(x,y) (x)>(y)?(x):(y)


vector<bool> color;
vector<int> cnt;
vector<int> bff;
vector<bool> is_pair;
vector<int> father;
vector<int> stats;
vector<int> stamp;

void search(int i) {
  color[i] = true;
  
  if (is_pair[bff[i]]) {
    cnt[i]=1;
    father[i] = bff[i];
    color[i] = true;
    return;
  }
  if (!color[bff[i]])
    search(bff[i]);
  father[i] = father[bff[i]];
  cnt[i] = cnt[bff[i]] + 1;
  if (father[i]!=-1)
    cnt[father[i]] = MAX(cnt[father[i]], cnt[i]);
}

int loop(int i, int level = 0) {
  if (stamp[bff[i]]==-1) {
    stamp[i] = level;
    int res = loop(bff[i], level+1);
    stamp[i] = -1;
    return res;
  }
  else {
    return level-stamp[bff[i]]+1;
  }
}


int ans = 0;
int main() {
  ifstream fin("c_in.txt");
  ofstream fout("c_out.txt");
  int T = 0;
  fin >> T;
  for (int i = 0; i<T; i++) {
    int n;
    fin >> n;
    ans = 0;
    bff = vector<int>(n, 0);
    is_pair = vector<bool>(n, false);
    color = vector<bool>(n, false);
    cnt = vector<int>(n, 0);
    father = vector<int>(n, -1);
    stats = vector<int>(n, -1);
    stamp = vector<int>(n, 0);
    
    for (int j=0; j<n; j++) {
      fin >> bff[j];
    }
    for (int k=0; k<n; k++) {
      if (bff[bff[k]]==k) {
        is_pair[k] = true;
        is_pair[bff[k]] = true;
      }
    }
    for (int j=0; j<n; j++)
      if (!color[j]) search(j);
    for (int j=0; j<n; j++) {
      for (int k=j+1; k<n; k++) {
        if (is_pair[father[k]] && father[j]==bff[father[k]])
          if (cnt[j]+cnt[k]+2>stats[father[k]]) {
            stats[father[k]] = cnt[j]+cnt[k]+2;
            stats[father[j]] = cnt[j]+cnt[k]+2;
          }
      }
    }
    for (int j=0; j<n; j++) {
      if (stats[j]==-1) continue;
      ans += stats[j];
      stats[j] = -1;
      stats[bff[j]] = -1;
    }
    for (int j=0; j<n; j++) 
      ans = MAX(ans, loop(j));
    
    fout << "CASE #"<<i+1<<": "<<ans<<endl;
  }
  return 0;
}
