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
vector<int64_t> splitInt64(const string& s, const string& delim =" ");
vector<double> splitDouble(const string& s, const string& delim =" ");

int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();

bool is_pa(int64_t x) {
  vector<int> dig;
  while (1) {
    int r = x % 10;
    dig.push_back(r);
    if (x < 10) {
      break;
    }
    x = x / 10;
  }
  int len = dig.size() / 2;
  int total_len = dig.size();
  for (size_t m = 0; m <= len; ++m) {
    if (dig[m] != dig[total_len - m - 1]) {
      return false;
    }
  }
  return true;
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

  int64_t min_L = 1;
  int64_t min_L_sqrt = 1;
  int64_t max_R = 100000000000000LL;
  int64_t max_R_sqrt = 10000000LL;
  vector<int64_t> pa;
  for (int64_t i = min_L_sqrt; i <= max_R_sqrt; ++i) {
    if (!is_pa(i)) {
      continue;
    }
    int64_t square = i * i;
    if (is_pa(square)) {
      pa.push_back(square);
    }
  }
  printf("pa size: %lu\n", pa.size());
  for (size_t i = 0; i < pa.size(); ++i) {
    printf("%llu\t",pa[i]);
  }
  printf("\n");
  for (int case_i = 0; case_i < case_num; ++case_i) {
    getline(fin, buffer_line);
    vector<int64_t> fields = splitInt64(buffer_line, " ");
    int64_t S = fields[0];
    int64_t E = fields[1];
    int res = 0;
    for (size_t i = 0; i < pa.size(); ++i) {
      if (pa[i] >= S && pa[i] <= E) {
        ++res;
      }
    }
    fprintf(fp, "Case #%d: %d\n", case_i, res);
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

vector<int64_t> splitInt64(const string& s, const string& delim) {
  vector<string> tok = split(s, delim);
  vector<int64_t> res;
  for (int i = 0 ; i != tok.size(); i++) {
    stringstream ss(tok[i]);
    int64_t temp;
    ss >> temp;
    res.push_back(temp);
  }
  return res;
}

vector<double> splitDouble(const string& s, const string& delim) {
  vector<string> tok = split(s, delim);
  vector<double> res;
  for (int i = 0 ; i != tok.size(); i++)
    res.push_back(atof(tok[i].c_str()));
  return res;
}
