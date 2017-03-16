#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;

int main() {
  FILE *fin = fopen("b.in", "r");
  FILE *fout = fopen("b.out", "w");
  int testn = 0;
  int n = 0;
  fscanf(fin, "%d", &testn);
  for (int t = 1; t <= testn; ++t) {
    fprintf(fout, "Case #%d: ", t);
    int n;
    fscanf(fin, "%d", &n);
    int maxn = 0;
    bool used[2505] = {false};
    for (int i = 0; i < n * 2 - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        int num;
        fscanf(fin, "%d", &num);
        used[num] = !used[num];
        if (num > maxn) {
          maxn = num;
        }
      }
    }
    for (int i = 1; i <= maxn; ++i) {
      if (used[i]) {
        fprintf(fout, "%d ", i);
      }
    }
    fprintf(fout, "\n");
  }
}