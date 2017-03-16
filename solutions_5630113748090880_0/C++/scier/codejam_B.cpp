#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;


vector<int> nums;

vector<int> foo(int n) {
  vector<int> res;
  for (int i = 0; i < 2501; ++i) {
    if (nums[i] % 2 == 1)
      res.push_back(i);
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  int t;
  int n;

  FILE *fin = NULL, *fout = NULL;
  fin = fopen("inputB.txt", "r");
  fout = fopen("outputB.txt", "w");

  fscanf(fin, "%d", &t);
  for (int i = 1; i <= t; ++i) {
    fscanf(fin, "%d", &n);
    nums.assign(2501, 0);
    for (int j = 0; j < 2 * n - 1; ++j) {
      int tmp;
      for (int k = 0; k < n; ++k) {
        fscanf(fin, "%d", &tmp);
        nums[tmp]++;
      }
    }
    
    vector<int> res = foo(n);
    fprintf(fout, "Case #%d:", i);
    for (int j = 0; j < n; ++j)
      fprintf(fout, " %d", res[j]);
    fprintf(fout, "\n");
  } 

  fclose(fin);
  fclose(fout);
	return 0;
}