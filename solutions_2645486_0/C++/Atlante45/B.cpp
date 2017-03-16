#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <gmpxx.h>

using namespace std;

void alg() {
  int E, R, N;
  cin >> E >> R >> N;
  
  int *V = new int[N];
  int *M = new int[N];

  for (int i(0); i < N; i++) {
    cin >> V[i];
  }
  
  M[N - 1] = V[N - 1];
  for (int i(0); i < N; i++) {
    M[N - 1 - i] = V[N - 1 - i] < M[N - i] ? M[N - i] : V[N - 1 - i];
  }
  

  int e = E;
  int gain = 0;

  for (int i(0); i < N; i++) {
    if (V[i] == M[i]) {
      gain += V[i]*e;
      e = 0;
    }
    else {
      int surplus = e + R - E;
      if (0 < surplus) {
	gain += V[i]*surplus;
	e -= surplus ;
      }
    }
    
    e = e + R < E ? e + R : E;
  }
  
  cout << gain << endl;
}

int main() {
    int n_cases;
    cin >> n_cases;
    
    for (int test_case = 1; test_case <= n_cases; test_case++) {
      cout << "Case #" << test_case << ": ";
      alg();
    }

    return EXIT_SUCCESS;
}
