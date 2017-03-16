#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> decompose(int n, int B)
{
  int l = log2(n);
  vector<int> v(B);
  
  for(int i = B-2; i >=0; --i) {
    v[i] = n%2;
    n >>= 1;
  }

  return v;
}

void print_mat(vector<vector<int>> &mat)
{
  for(int i = 0; i < mat.size(); ++i) {
    for(int j = 0; j < mat[0].size(); ++j) {
      cout << mat[i][j];
    }
    cout << endl;
  }
}

int main()
{
  int T;
  cin >> T;

  for(int i = 1; i <= T; ++i) {
    int B, M;
    cin >> B >> M;


    
    cout << "Case #" << i << ": ";
    if(B < log2(M) + 2) {
      cout << "IMPOSSIBLE" << endl;
    } else if(B == log2(M) + 2) {
      cout << "POSSIBLE" << endl;
      vector<vector<int>> mat = vector<vector<int>>(B, vector<int>(B, 0));
      
      for(int j = 0; j < B; ++j) {
	for(int k = j+1; k < B; ++k) {
	  mat[j][k] = 1;
	}
      }

      print_mat(mat);
    }else {
      cout << "POSSIBLE" << endl;
      auto v = decompose(M, B);
	  
      vector<vector<int>> mat = vector<vector<int>>(B, vector<int>(B, 0));
      
      mat[0] = v;

      for(int j = 1; j < B; ++j) {
	for(int k = j+1; k < B; ++k) {
	  mat[j][k] = 1;
	}
      }

      print_mat(mat);
    }
    
   
  }
}
