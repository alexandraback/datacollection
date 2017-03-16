#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// to use:
// g++ -o template template.cpp
// ./template < in.txt

const int N_MAX = 1005;
int N;

int diag[N_MAX][N_MAX];
int ans[N_MAX][N_MAX]; // powers of diag. diag^k
int paths[N_MAX][N_MAX]; // sum of anything in ans.


void print_mat(int a[N_MAX][N_MAX]) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool all_zeros(int a[N_MAX][N_MAX]) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (a[i][j] != 0) return false;
    }
  }
  return true;
}

bool greater_than_one(int a[N_MAX][N_MAX]) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (a[i][j] > 1) return true;
    }
  }
  return false;
}

// a = a * b
void mult(int a[N_MAX][N_MAX], int b[N_MAX][N_MAX]) {

  int c[N_MAX][N_MAX];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      c[i][j] = 0;
      for (int k = 1; k <= N; k++) {
	c[i][j] += a[i][k] * b[k][j];
      }
    }
  }


  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      a[i][j] = c[i][j];
    }
  }

}

void solve(int case_num) {

  cin >> N;
  // initialize everything to zero
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      diag[i][j] = 0; // path from i to j
      paths[i][j] = 0;
      if (i == j) ans[i][j] = 1; // starts with identity
      else ans[i][j] = 0;
    }
  }

  for (int i = 1; i <= N;i++) {
    int M;
    int num;
    cin >> M;
    for (int j = 0; j < M; j++) {
      cin >> num;
      diag[i][num] = 1; // ??
    }
  }

  while (! all_zeros(ans)) {
    mult(ans,diag);

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
	paths[i][j] += ans[i][j];
      }
    }

    //  cout << "MAT ans" << endl;
    //print_mat(ans);
    //cout << "MAT paths" << endl;
    //print_mat(paths);

    if (greater_than_one(paths))  {
      cout << "Case #" << case_num << ": Yes" << endl;
      return;
    }



  }

  
  cout << "Case #" << case_num << ": No" << endl;
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve(i+1);
  }
  return 0;
}
