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
vector<uint64_t> splitInt64(const string& s, const string& delim =" ");
vector<double> splitDouble(const string& s, const string& delim =" ");

int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();

bool equal_double(double x, double y) {
  if (y > (x - 1e-2) && y < (x + 1e-2)) {
    return true;
  }
  return false;
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

  uint64_t max_n = 2000000000000000000ULL;
  for (int case_i = 0; case_i < case_num; ++case_i) {
    getline(fin, buffer_line);
    vector<uint64_t> rt = splitInt64(buffer_line, " ");
    uint64_t r = rt[0];
    uint64_t t = rt[1];
    uint64_t temp = 2 * r + 1;

    uint64_t start = 0;
    uint64_t end = max_n;
    bool is_done = false;
    while (start <= end) {
      uint64_t mid = (start + end) / 2;
      double mid_val = (temp + 2 * (double)mid) * ((double)mid + 1);
      if (equal_double(mid_val, (double)t)) {
        fprintf(fp, "Case #%d: %lld\n", case_i+1, mid+1);
        is_done = true;
        break;
      }
      if (mid_val < (double)t) {
        start = mid+1;
      } else {
        end = mid-1;
      }
    }
    if (is_done) {
      continue;
    }
    uint64_t x;
    if (end < 3) {
      end = 0;
    } else {
      end -= 3;
    }
    for (x = end; x < start+3; ++x) {
      double y = (temp + 2 * x) * (x + 1);
      if (y > (double)t) {
        break;
      }
    }
    fprintf(fp, "Case #%d: %lld\n", case_i+1, x);
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

vector<uint64_t> splitInt64(const string& s, const string& delim) {
  vector<string> tok = split(s, delim);
  vector<uint64_t> res;
  for (int i = 0 ; i != tok.size(); i++)
    res.push_back(strtoull(tok[i].c_str(), NULL, 10));
  return res;
}
