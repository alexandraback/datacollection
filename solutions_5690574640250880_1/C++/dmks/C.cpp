#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

vector<string> convert(const vector<string>& a) {
  vector<string> ret;
  int R = a.size(), C = a[0].size();
  for (int c = 0; c < C; c++) {
    string temp = "";
    for (int r = 0; r < R; r++) temp += a[r][c];
    ret.push_back(temp);
  }
  return ret;
}

void output(vector<string> ret, bool flag) {
  if (flag) {
    ret = convert(ret);
  }
  for (int i = 0; i < ret.size(); i++) cout << ret[i] << endl;
}

vector<string> full(int R, int C) {
  vector<string> ret;
  for (int r = 0; r < R; r++) {
    ret.push_back(string(C, '*'));
  }
  return ret;
}

void go(int R, int C, int M) {
  bool flag = false;
  if (R > C) {
    swap(R, C);
    flag = true;
  }
  vector<string> ret;
  if (R == 1) {
    string row(C, '*');
    for (int i = 0; i < C - M; i++) {
      if (i == 0) row[i] = 'c';
      else row[i] = '.';
    }
    ret.push_back(row);
    output(ret, flag);
    return;
  }
  int n = R * C - M;

  if (n == 1) {
    ret = full(R, C);
    ret[0][0] = 'c';
    output(ret, flag);
    return;
  }

  if (R == 2) {
    if (n % 2 == 1 || n == 2) {
      cout << "Impossible" << endl;
      return;
    }
    ret = full(R, C);
    for (int r = 0; r < R; r++) for (int c = 0; c < n / 2; c++) ret[r][c] = '.';
    ret[0][0] = 'c';
    output(ret, flag);
    return;
  }

  if (n <= 3 || n == 5 || n == 7) {
    cout << "Impossible" << endl;
    return;
  }

  int k = R;
  if (n < R * 3) {
    k = 3;
  }
  ret = full(R, C);
  int l = n / k;
  for (int r = 0; r < k; r++) for (int c = 0; c < l; c++) ret[r][c] = '.';
  for (int r = 0; r < n % k; r++) ret[r][l] = '.';
  if (n % k == 1) {
    ret[k-1][l-1] = '*';
    ret[1][l] = '.';
  }
  ret[0][0] = 'c';
  output(ret, flag);
  return;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int R, C, M;
    cin >> R >> C >> M;
    cout << "Case #" << i << ":" << endl;
    go(R, C, M);
  }
  return 0;
}
