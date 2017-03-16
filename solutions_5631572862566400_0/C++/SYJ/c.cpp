#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main() {
  FILE *fin = fopen("c.in", "r");
  FILE *fout = fopen("cc1.out", "w");
  int testn = 0;
  fscanf(fin, "%d", &testn);
  for (int t = 1; t <= testn; ++t) {
    int bff[1002];
    fprintf(fout, "Case #%d: ", t);
    int n = 0;
    int max = 0;
    fscanf(fin, "%d", &n);
    for (int i = 1; i <= n; ++i) {
      fscanf(fin, "%d", &bff[i]);
    }
    int maxloop = 0;
    for (int i = 1; i <= n; ++i) {
      bool used[1002] = {false};
      int node = i;
      int loopsize = 0;
      int lnode = 0;
      while (!used[node]) {
        used[node] = true;
        lnode = node;
        node = bff[node];
        ++loopsize;
      }
      if (node != i && bff[node] != lnode) {
        continue;
      }
      if (bff[node] == lnode) {
        for (int i = 1; i <= n; ++i) {
          if (bff[i] == lnode && !used[i]) {
            ++loopsize;
            break;
          }
        }
      }
      if (loopsize > maxloop) {
        maxloop = loopsize;
      }
    }
    fprintf(fout, "%d\n", maxloop);
  }
}