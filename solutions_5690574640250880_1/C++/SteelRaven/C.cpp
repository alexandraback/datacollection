#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solvePrepared(int r, int c, int f, vector < string > & res) {
  if(r == 1){
    res.resize(r, string(c, ' '));
    res[0][0] = 'c';
    for(int i = 1; i < f; ++i)
      res[0][i] = '.';
    for(int i = f; i < c; ++i)
      res[0][i] = '*';
    return;
  }
  if(f == 1){
    res.resize(r, string(c, ' '));
    for(int i = 0; i < r; ++i){
      for(int j = 0; j < c; ++j){
        if(i == 0 && j == 0) res[i][j] = 'c';
        else res[i][j] = '*';
      }
    }
    return;
  }
  if(f == 2 || f == 3 || f == 5 || f == 7){
    return;
  }
  if(f == 4){
    res.resize(r, string(c, ' '));
    for(int i = 0; i < r; ++i){
      for(int j = 0; j < c; ++j){
        if(i == 0 && j == 0) res[i][j] = 'c';
        else if(i < 2 && j < 2) res[i][j] = '.';
        else res[i][j] = '*';
      }
    }
    return;
  }
  if(f == 6){
    if(r * c < 6) return;
    res.resize(r, string(c, ' '));
    for(int i = 0; i < r; ++i){
      for(int j = 0; j < c; ++j){
        if(i == 0 && j == 0) res[i][j] = 'c';
        else if(i < 2 && j < 3) res[i][j] = '.';
        else res[i][j] = '*';
      }
    }
    return;
  }
  if(r == 2){
    if(f % 2) return;
    res.resize(r, string(c, ' '));
    for(int i = 0; i < r; ++i){
      for(int j = 0; j < c; ++j){
        if(i == 0 && j == 0) res[i][j] = 'c';
        else if(j < f / 2) res[i][j] = '.';
        else res[i][j] = '*';
      }
    }
    return;
  }
  res.resize(r, string(c, ' '));
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
      if(i == 0 && j == 0) res[i][j] = 'c';
      else if(i == 2 && j == 2) res[i][j] = ' ';
      else res[i][j] = '.';
    }
  }
  f -= 8;
  for(int i = 3; i < c; ++i){
    if(f < 2) break;
    res[0][i] = res[1][i] = '.';
    f -= 2;
  }
  for(int i = 3; i < r; ++i){
    if(f < 2) break;
    res[i][0] = res[i][1] = '.';
    f -= 2;
  }
  for(int i = 2; i < r && f; ++i){
    for(int j = 2; j < c && f; ++j){
      --f;
      res[i][j] = '.';
    }
  }
  for(int i = 0; i < r; ++i){
    for(int j = 0; j < c; ++j){
      if(res[i][j] == ' ') res[i][j] = '*';
    }
  }
}

void solve() {
  int r, c, m;
  cin >> r >> c >> m;
  int f = r * c - m;
  bool transposed = false;
  if(c < r){
    swap(c, r);
    transposed = true;
  }
  vector < string > res;
  solvePrepared(r, c, f, res);
  if(res.empty()){
    cout << "Impossible\n";
    return;
  }
  if(transposed){
    vector < string > tmp(c, string(r, ' '));
    for(int i = 0; i < r; ++i){
      for(int j = 0; j < c; ++j){
        tmp[j][i] = res[i][j];
      }
    }
    res.swap(tmp);
  }
  for(const string& s : res){
    cout << s << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(9);
  int t;
  cin >> t;
  for(int i = 1; i <= t; ++i){
    cout << "Case #" << i << ": \n";
    solve();
  }
}
