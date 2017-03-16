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

bool check_row(vector<vector<int> > &data, int N, int M, int row, int max_h) {
  for (int i = 0; i < M; ++i) {
    if (data[row][i] > max_h) {
      return false;
    }
  }
  return true;
}

bool check_col(vector<vector<int> > &data, int N, int M, int col, int max_h) {
  for (int i = 0; i < N; ++i) {
    if (data[i][col] > max_h) {
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

  for (int case_i = 0; case_i < case_num; ++case_i) {
    getline(fin, buffer_line);
    vector<int> NM = splitInt(buffer_line, " ");
    int N = NM[0];
    int M = NM[1];
    vector<vector<int> > data;
    data.resize(N);
    for (int i = 0; i < N; ++i) {
      data[i].resize(M);
      getline(fin, buffer_line);
      vector<int> fields = splitInt(buffer_line, " ");
      for (int m = 0; m < M; ++m) {
        data[i][m] = fields[m];
      }
    }
    // check row
    bool valid = true;
    for (int c = 0; c < M; ++c) {
      for (int r = 0; r < N; ++r) {
        for (int r2 = r + 1; r2 < N; ++r2) {
          if (data[r][c] > data[r2][c]) {
            bool ret = check_row(data, N, M, r2, data[r2][c]);
            if (!ret) {
              valid = false;
              break;
            }
          } else if (data[r2][c] > data[r][c]){
            bool ret = check_row(data, N, M, r, data[r][c]);
            if (!ret) {
              valid = false;
              break;
            }
          }
        }
        if (valid == false) {
          break;
        }
      }
      if (valid == false) {
        break;
      }
    }
    if (valid == false) {
      fprintf(fp, "Case #%d: NO\n", case_i+1);
      continue;
    }
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < M; ++c) {
        for (int c2 = c + 1; c2 < M; ++c2) {
          if (data[r][c] > data[r][c2]) {
            bool ret = check_col(data, N, M, c2, data[r][c2]);
            if (!ret) {
              valid = false;
              break;
            }
          } else if (data[r][c2] > data[r][c]){
            bool ret = check_col(data, N, M, c, data[r][c]);
            if (!ret) {
              valid = false;
              break;
            }
          }
        }
        if (valid == false) {
          break;
        }
      }
      if (valid == false) {
        break;
      }
    }
    if (valid == false) {
      fprintf(fp, "Case #%d: NO\n", case_i+1);
      continue;
    }
    fprintf(fp, "Case #%d: YES\n", case_i+1);
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
