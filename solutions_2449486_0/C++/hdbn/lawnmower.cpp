#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

string solve(const vector<vector<int> > & grid){
  int i, j, h, k, N, M;
  N = grid.size(); M = grid[0].size();
  vector<vector<pair<int,int> > > byHeight(101);
  for(i = 0; i < grid.size(); i++){
    assert(grid[i].size() == M);
    for(j = 0; j < grid[i].size(); j++){
      byHeight[grid[i][j]].push_back(make_pair(i,j));
    }
  }
  for(h = 100; h >= 0; h--){
    for(k = 0; k < byHeight[h].size(); k++){
      int y = byHeight[h][k].first; 
      int x = byHeight[h][k].second;
      bool can = false;
      for(i = 0; i < N; i++){
	if(grid[i][x] > h) break;
      }
      if(i == N) can = true;
      for(i = 0; i < M; i++){
	if(grid[y][i] > h) break;
      }
      if(i == M) can = true;
      if(can == false) return "NO";
    }
  }
  return "YES";
}

int main(int argc, char * argv[]){
  int T, n, N, M, i, j;
  cin >> T;
  for(n = 0; n < T; n++){
    vector<vector<int> > grid;
    cin >> N >> M;
    for(j = 0; j < N; j++){
      vector<int> row;
      for(i = 0; i < M; i++){
	int x;
	cin >> x;
	row.push_back(x);
      }
      grid.push_back(row);
    }
    string result;
    result = solve(grid);
    cout << "Case #" << (n+1) << ": " << result << endl;
  }
}
