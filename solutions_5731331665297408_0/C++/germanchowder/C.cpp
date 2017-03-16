#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

string mymin(string s1, string s2) {
  if (s1.size() < s2.size()) {
    return s2;
  }
  if (s2.size() < s1.size()) {
    return s1;
  }
  for (int ii = 0; ii < s1.size(); ii++) {
    if (ii >= s2.size()) {
      return s1;
    }
    if (s1[ii] < s2[ii]) {
      return s1;
    }
    if (s2[ii] < s1[ii]) {
      return s2;
    }
  }
  return s2;
}

string solve(long long N, string *zip, int edges[8][8], vector<int> used, vector<int> stack) {
  string ret = "";
  if (used.size() == N) {
    return "";
  }
  if (stack.size() > 1) {
    int k = stack[stack.size()-1];
    stack.pop_back();
    ret = mymin(solve(N, zip, edges, used, stack), ret);
    stack.push_back(k);
  }
  for (int ii = 0; ii < N; ii++) {
    string poss = "";
    if (used.size() > 0 && find(used.begin(), used.end(), ii) != used.end()) {
      continue;
    }
    if (stack.size()) {
      if (edges[stack[stack.size()-1]][ii]) {
        poss = zip[ii];
        stack.push_back(ii);
        used.push_back(ii);
        poss += solve(N, zip, edges, used, stack);
        stack.pop_back();
        used.pop_back();
      }
    }
    else {
      poss = zip[ii];
      stack.push_back(ii);
      used.push_back(ii);
      poss += solve(N, zip, edges, used, stack);
      stack.pop_back();
      used.pop_back();
    }
    ret = mymin(ret, poss);
  }
  
  /*
  if (stack.size()) {
    cout << stack[stack.size()-1] << " ";
  }
  cout << ret << endl;*/
  return ret;
}

int main() {
  long long T;
  long long N, M;
  cin >> T;

  for (long long ii = 1; ii <= T; ii++) {
    cout << "Case #" << ii << ": ";
    cin >> N >> M;
    string zip[8];
    int edges[8][8] {};
    for (int ii = 0; ii < N; ii++) {
      cin >> zip[ii];
    }
    for (int ii = 0; ii < M; ii++) {
      int i, j;
      cin >> i >> j;
      edges[i-1][j-1] = edges[j-1][i-1] = 1;
    }
    /*for (int ii = 0; ii < N; ii++) {
      for (int jj = 0; jj < N; jj++) {
      cout << edges[ii][jj] << " ";
      }
      cout << endl;
    }*/

    vector <int> used, stack;
    cout << solve(N, zip, edges, used, stack) << endl; 
  }
}
