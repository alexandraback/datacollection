#include <iostream>
#include <vector>
using namespace std;

int N, X;
vector<int> J;

double busca(double miny, double maxy, int ind) {
  double m = (miny + maxy)/2.0;
  if (maxy - miny < 1e-8) return m;
  double sum = 0;
  for (int i = 0; i < N; ++i) {
    double y = m - double(J[i] - J[ind])/X;
    sum += min(max(y, 0.0), 1.0);
  }
  if (sum > 1) return busca(miny, m, ind);
  if (sum < 1) return busca(m, maxy, ind);
  else return m;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(6);
  int T, cas;
  cin >> T;
  cas = 1;
  while (cas <= T) {
    cin >> N;
    J = vector<int>(N);
    X = 0;
    for (int i = 0; i < N; ++i) {
      cin >> J[i];
      X += J[i];
    }
    cout << "Case #" << cas << ":";
    for (int i = 0; i < N; ++i) {
      cout << ' ' << min(max(busca(0, 1, i), 0.0), 1.0)*100;
      //cout << ' ' << max((2.0/N - double(J[i])/X)*100, 0.0);
    }
    cout << endl;
    ++cas;
  }
}