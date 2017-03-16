#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


int solve_case(int a, int b, int case_num) {
  string answer;


}

int * mat_mult (int * A, int * B, int N) {
  int * ans = new int[N*N];
  int sum;
  for(int i = 0; i<N; i++) {
    for(int j = 0; j<N; j++) {
      sum = 0;
      for(int k = 0; k<N; k++) {
	sum += A[i*N+k]*B[k*N+j];
      }
      ans[i*N+j] = sum;
    }
  }
  return ans;
}

int * mat_add (int * A, int * B, int N) {
  int * ans = new int[N*N];
  for(int i = 0; i<N; i++) {
    for(int j = 0; j<N; j++) {
      ans[i*N+j] = A[i*N+j]+B[i*N+j];
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    int * arr = new int[N*N];
    int * arr2 = new int[N*N];
    for (int j = 0; j<N; j++) {
      for(int k = 0; k<N; k++) {
	arr[j*N+k] = 0;
	arr2[j*N+k] = 0;
      }
    }
    for (int j = 0; j<N; j++) {
      int m;
      cin >> m;
      int t;
      for (int k = 0; k<m; k++) {
	cin >> t;
	arr[(t-1)*N+j] = 1;
      }
    }
    
    
    int * power = new int[N*N];
    memcpy(power,arr,N*N*sizeof(int));
    memcpy(arr2, arr, N*N*sizeof(int));
    for(int k = 0; k < N; k++) {
      arr2 = mat_add(mat_mult(power,arr,N),arr2,N);
      power = mat_mult(power, arr,N);
    }
    string answer = "No";
    for(int k = 0; k<N*N; k++) {
      if (arr2[k] > 1) {
	answer = "Yes";
	break;
      }
    }
     
    cout << "Case #" << i+1 << ": " << answer << "\n";
    
  }
}
