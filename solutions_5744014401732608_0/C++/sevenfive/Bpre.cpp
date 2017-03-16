// my first program in C++
#include <iostream>
#include <math.h>

using namespace std;

int arr[100*100];

int count(int from, int N) {
  if (from == N-1) {
    return 1;
  }
  int c = 0;
  for (int to = 0; to < N; to++) {
    if (arr[from+N*to] > 0) {
      if (to <= from) {
        cout << "LOOP" ;
        exit(123);
      }
      c += count(to, N);
    }
  }
  return c;
}



int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    int M;
    cin >> M;
    int success = 0;
    for (int i = 0 ; !success && i < pow(2,N*(N-1)/2); i++) {
      for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
          arr[x + N*y] = 0;
        }
      }
      int k = 0;
      for (int x = 0; x < N; x++) {
        for (int y = x+1; y < N; y++) {
          arr[x + N*y] = (i & (1 << k)) > 0 ? 1 : 0;
          k++;
        }
      }
      int ways = count(0, N);
      // for (int x = 0; x < N; x++) {
      //   for (int y = 0; y < N; y++) {
      //     cout << arr[x + N*y] << " ";
      //   }
      //   cout << endl;
      // }
      // cout << ways << endl;
      if (ways == M) {
        cout << "POSSIBLE" << endl;
        for (int x = 0; x < N; x++) {
          for (int y = 0; y < N; y++) {
            cout << arr[x + N*y];
          }
          cout << endl;
          success = 1;
        }
      }
    }
    if (!success) {
      cout << "IMPOSSIBLE" << endl;
    }
  }

}
