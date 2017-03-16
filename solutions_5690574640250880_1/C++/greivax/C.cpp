#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

void fill_row(vvc &data, int x, int y, int k){
  for(int j = y; j < min(k, (int) data[x].size()); ++j)
    data[x][j] = '*';
}

void fill_column(vvc &data, int x, int y, int k){
  for(int i = x; i < min(k, (int) data.size()); ++i)
    data[i][y] = '*';
}

bool solve(vvc &data, int x, int y, int m){
  if(data.size() - x <= data[0].size() - y){
    if(m >= data.size() - x){
      fill_column(data, x, y, (int) data.size());
      m -= data.size() - x;
      return solve(data, x, y + 1, m);
    }
    if(m >= data[0].size() - y){
      fill_row(data, x, y, (int) data[0].size());
      m -= data[0].size() -y;
      return solve(data, x + 1, y, m);
    }
  } else {
    if(m >= data[0].size() - y){
      fill_row(data, x, y, (int) data[0].size());
      m -= data[0].size() -y;
      return solve(data, x + 1, y, m);
    }
    if(m >= data.size() - x){
      fill_column(data, x, y, (int) data.size());
      m -= data.size() - x;
      return solve(data, x, y + 1, m);
    }
  }
  // fill base case
  if(data.size() - x == 1 and data[0].size() - y == 1)
    return true;
  if(data.size() - x == 1 or data[0].size() - y == 1)
    return false;
  if(m == 0)
    return true;
  if(data.size() - x == 2 or data[0].size() - y == 2)
    return false;
  if(data.size() - x == 3 and data[0].size() - y == 3 and m == 2)
    return false;
  data[x][y] = '*';
  --m;
  if(data.size() - x > data[0].size() - y){
    int k = min(x + 1 + m, (int) data.size() - 2);
    fill_column(data, x + 1, y, k);
    m -= k;
    m += x + 1;
    if(m == 0)
      return true;
    fill_row(data, x, y + 1, y + 1 + m);
    return true;
  }
  int k = min(y + 1 + m, (int) data[0].size() - 2);
  fill_row(data, x, y + 1, k);
  m -= k;
  m += y + 1;
  if(m == 0)
    return true;
  fill_column(data, x + 1, y, x + 1 + m);
  return true;
}

int main(){
  int T;
  cin >> T;
  for(int c=1; c<=T; ++c){
    int R, C, M;
    cin >> R >> C >> M;
    vvc data(R, vc(C, '.'));
    data[data.size()-1][data[0].size()-1] = 'c';
    bool ret = false;
    if(R == 1){
      ret = true;
      fill_row(data, 0, 0, M);
    } else if(C == 1){
      ret = true;
      fill_column(data, 0, 0, M);
    } else {
      ret = solve(data, 0, 0, M);
    }
    cout << "Case #" << c << ':' << endl;
    if(not ret){
      cout << "Impossible" << endl;
    } else {
      for(int i = 0; i < (int) data.size(); ++i){
        for(int j = 0; j < (int) data[0].size(); ++j)
      	  cout << data[i][j];
      	cout << endl;
      }
    }
  }
}
