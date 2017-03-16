#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    int A, N;
    cin >> A >> N;
    int p[N];
    for (int i = 0; i < N; i++)
      cin >> p[i];
    sort(p, p+N);
    int res = 0;
    for (int i = 0; i < N; i++) {
      if (p[i] < A) {
        A += p[i];
      } else {
        int op2 = N - i, op1 = 0, t;
        if (A > 1)
          for (t = A; t <= p[i]; t += t-1, op1++);
        else
          op1 = 1<<20;
        if (op1 < op2) {
          res += op1;
          A = t + p[i];
        } else {
          res += op2;
          break;
        }
        // option 1:
        // A = 2**n (A - 1) + 1, n steps needed
        // option 2:
        // remove last n elements
      }
    }
    cout << "Case #" << CASE << ": " << res << endl;
  }
}