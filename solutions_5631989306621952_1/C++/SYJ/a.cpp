#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main() {
  FILE *fin = fopen("al.in", "r");
  FILE *fout = fopen("al.out", "w");
  int testn = 0;
  int n = 0;
  char ss[10005];
  fscanf(fin, "%d", &testn);
  for (int t = 1; t <= testn; ++t) {
    fprintf(fout, "Case #%d: ", t);
    fscanf(fin, "%s", ss);
    stringstream sss;
    string target;
    sss << ss[0];
    sss >> target;
    string answer = "" + target;
    char start = ss[0];
    for (int i = 1; i < strlen(ss); ++i) {
      stringstream ss1;
      string t1;
      ss1 << ss[i];
      ss1 >> t1;
      if (ss[i] >= start) {
        answer = t1 + answer;
        start = ss[i];
      } else {
        answer = answer + t1;
      }
    }
    fprintf(fout, "%s\n", answer.c_str());
  }
}