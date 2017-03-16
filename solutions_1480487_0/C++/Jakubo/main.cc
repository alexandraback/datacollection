#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ":";
    int N;
    cin >> N;
    vector <int> a;
    for (int j = 0; j < N; ++j) {
      int buffer;
      cin >> buffer;
      a.push_back(buffer);
    }
    double sum = 0;
    for (int j = 0; j < N; ++j) {
      sum += a[j];
    }
    double sum2 = 2 * sum;
    int M = N;
    vector <double> result;
    for (int j = 0; j < N; ++j) {
      result.push_back(1);
    }
    for (int j = 0; j < N; ++j) {
      if (a[j] > (double)(sum * 2) / N) {
        result[j] = 0;
        --M;
        sum2 -= a[j];
      }
    }
    for (int j = 0; j < N; ++j) {
      cout << " ";
      if (!result[j]) {
        printf("%.6f", 0);
        continue;
      }
      else {
        double r = (sum2 / M - a[j]) / sum * 100;
        printf("%.6f", r);
      }
    }
    cout << endl;
  }
}
