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

int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();

int solve(vector<int> &ns, map<uint64_t, int> &dp, int max_e_val, int e, int r, int n, int cur) {
  if (e > max_e_val) {
    e = max_e_val;
  }
  if (e == 0) {
    return 0;
  }
  if (cur == n) {
    return 0;
  }
  uint64_t key = (uint64_t)cur << 32 | e;
  if (dp.find(key) != dp.end()) {
    return dp[key];
  }
  
  int max_e = MIN_INT;
  for (int i = 0; i <= e; ++i) {
    int res = solve(ns, dp, max_e_val, e+r-i, r, n, cur+1) + ns[cur] * i;
    if (res > max_e) {
      max_e = res;
    }
  }
  dp[key] = max_e;
  return max_e;
}

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
    map<uint64_t, int> dp;
    getline(fin, buffer_line);
    vector<int> ern = splitInt(buffer_line, " ");
    int e = ern[0];
    int r = ern[1];
    int n = ern[2];
    getline(fin, buffer_line);
    vector<int> ns = splitInt(buffer_line, " ");
    int res = solve(ns, dp, e, e, r, n, 0);
    fprintf(fp, "Case #%d: %d\n", case_i+1, res);
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
