// N*N meter lawn
// lawnmower: h= 1-100 millimeter -> cut all grass higher than h
// start from any part of the edge of the lawn
// one cut is with 1m wide

// the line was cut with leargest height in the line

// algorithm: 
// measure the largest height of each row and col
// sort them in the descending order
// cut the lawn in that order
// compare the resulting lawn and the given lawn


// height should gradually decreased?
// initial 100mm high
// output possibility of the pattern

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool solve(int N, int M, int lawn[][100]){
  // score each row and col
  multimap<int, int> cutLen;
  for(int i = 0; i < N+M; i++){
    int tmpMax = 0;
    if(i < N){ // i-th row
      for(int j = 0; j < M; j++){
	tmpMax = max(tmpMax, lawn[i][j]);
      }
    }else{ // i-N-th col
      for(int j = 0; j < N; j++){
	tmpMax = max(tmpMax, lawn[j][i-N]);
      }
    }
    cutLen.insert(make_pair(tmpMax, i));
  }
  
  int result[100][100];
  for(multimap<int, int>::reverse_iterator it = cutLen.rbegin(); it != cutLen.rend(); ++it){
    // cut line it->second with height it->first
    if(it->second < N){ // i-th row
      for(int col = 0; col < M; col++){
	result[it->second][col] = it->first;
      }
    }else{ // i-N-th col
      for(int row = 0; row < N; row++){
	result[row][it->second-N] = it->first;
      }
    }
  }
  // compare result and lawn
  // YES if result == lawn, NO otherwise
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(lawn[i][j] != result[i][j]) return false;
    }
  }
  return true;
}



int main(){
  int T;
  cin >> T;
  int N, M;
  int lawn[100][100];
  for(int t = 0; t < T; t++){
    cin >> N >> M;
    for(int n = 0; n < N; n++){
      for(int m = 0; m < M; m++){
	cin >> lawn[n][m];
      }
    }
    bool result = solve(N,M,lawn);
    cout << "Case #" << t+1 << ": " << (result?"YES":"NO") << endl;
  }
  

  return 0;
}
