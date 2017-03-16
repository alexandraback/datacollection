#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

int p = 1000000007;

int solve(int N, int M, int K, vector<int> & arra) {
  // N = 3 - number of numbers
  // each number in [2, M=5]
  //
  double probr = 0.;
  int ar = -1, br = -1, cr = -1;
  for (int a = 2; a <= M; ++a) {
    for (int b = a; b <= M; ++b) {
      for (int c = b; c <=M; ++c) {
        int arr[] = {a,b,c};
        int prod_ok[7] = {0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < 1<<3; ++i) {
          vector<int> sset;
          for (int j = 0; j <3; ++j) {
            if ((i>>j) %2 == 1) {
              sset.push_back(arr[j]);
            }
          }
          int prod = 1;
          for (int z = 0; z < sset.size(); ++z) {
            prod *= sset[z];
          }
          for (int z = 0; z < 7; ++z) {
            if (prod == arra[z])
              prod_ok[z] ++;
          }


        }
        double prob = 1.;
        for (int z = 0; z < 7; ++z) {
          prob *= double(prod_ok[z]) / 8;
        }
        if (prob > probr) {
          ar = a;
          br = b;
          cr = c;
        }
      }
    }
  }
  printf("%d %d %d\n", ar, br, cr);
  return 0;
}

int main() {
    int T;
    cin >> T;

    for(unsigned int _ = 0; _ < T; _++) {
        cout <<"Case #" << (_+1) << ":\n";
        int R, N, M, K;
        cin >> R >> N >> M >> K;
        for (int i = 0; i < R; ++i) {
          vector<int> a(K);
          for (int j = 0; j < K; ++j) {
            cin >> a[j];
          }
          solve(N, M, K, a);
        }
    }
    return 0;
}