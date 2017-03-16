#include <cstdlib>
#include <cstdio>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

char line[1020];

char ans[2100];

char * foo() {
  int n = strlen(line);
  int s = 1050, f = 1050;

  if (n == 0) {
    ans[f] = 0;
    return ans + s;
  }
  ans[s] = line[0];
  --s; ++f;

  for (int i = 1; i < n; ++i) {
    if (line[i] >= ans[s+1]) {
      ans[s] = line[i];
      --s;
    }
    else {
      ans[f] = line[i];
      ++f;
    }
  }
  ans[f] = 0;

  return ans+s+1;
}

int main() {
  int t;
  long long n, res;
  FILE *fin = NULL, *fout = NULL;
  fin = fopen("inputA.txt", "r");
  fout = fopen("outputA.txt", "w");

  fscanf(fin, "%d", &t);
  for (int i = 1; i <= t; ++i) {
    fscanf(fin, "%s", line);
    fprintf(fout, "Case #%d: %s\n", i, foo());
  } 

  fclose(fin);
  fclose(fout);
	return 0;
}