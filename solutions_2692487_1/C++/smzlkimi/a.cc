#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

vector<string> split(const string& s, const string& delim =" ");
vector<int> splitInt(const string& s, const string& delim =" ");
vector<double> splitDouble(const string& s, const string& delim =" ");


int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./program input output\n");
    return -1;
  }
  ifstream fin(argv[1]);
  if (!fin) {
    printf("open %s failed\n", argv[1]);
    return -1;
  }
  FILE *fp = fopen(argv[2], "w");

  string buffer_line;
  getline(fin, buffer_line);
  int case_num = atoi(buffer_line.c_str());

  for (int case_i = 0; case_i < case_num; ++case_i) {
    getline(fin, buffer_line);
    vector<int> fields = splitInt(buffer_line, " ");
    int A = fields[0];
    int N = fields[1];
    if (A == 1) {
      fprintf(fp, "Case #%d: %d\n", case_i+1, N);
      getline(fin, buffer_line);
      continue;
    }
    int cur_res = 0;
    getline(fin, buffer_line);
    fields = splitInt(buffer_line, " ");
    sort(fields.begin(), fields.end(), less<int>());

    int cur = A;
    for (int i = 0; i < N - 1; ++i) {
      int need = fields[i];
      while (cur <= need) {
        cur += cur - 1;
        ++cur_res;
      }
      cur += need;
    }

    if (cur <= fields[fields.size()-1]) {
      ++cur_res;
    }

    fprintf(fp, "Case #%d: %d\n", case_i+1, cur_res);
  }

  fclose(fp);
}









vector<string> split(const string& s, const string& delim) {
  vector<string> res;
  string t;
  for (int i = 0 ; i != s.size() ; i++) {
    if (delim.find( s[i] ) != string::npos) {
      if (!t.empty()) {
        res.push_back(t);
        t = "";
      }
    } else {
      t += s[i];
    }
  }
  if (!t.empty()) {
    res.push_back(t);
  }
  return res;
}

vector<int> splitInt(const string& s, const string& delim) {
  vector<string> tok = split(s, delim);
  vector<int> res;
  for (int i = 0 ; i != tok.size(); i++)
    res.push_back(atoi(tok[i].c_str()));
  return res;
}

vector<double> splitDouble(const string& s, const string& delim) {
  vector<string> tok = split(s, delim);
  vector<double> res;
  for (int i = 0 ; i != tok.size(); i++)
    res.push_back(atof(tok[i].c_str()));
  return res;
}
