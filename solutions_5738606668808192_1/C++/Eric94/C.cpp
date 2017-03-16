#include <iostream>
#include <vector>
using namespace std;

int N, J, seen;
vector <int> number;

int abs(int n) {
  if (n < 0) return -n;
  return n;
}

void back (int pos, int odds, int evens) {
  if (seen == J) return;
  if (pos == 1 && odds == evens) {
    ++seen;
    for (int i = N - 1; i >= 0; --i) {
      cout << number[i];
    }

    for (int i = 2; i <= 10; ++i) {
      cout << ' ' << i + 1;
    }
    cout << endl;
    return;
  }

  if (pos == 1) return;

  if (abs(odds - evens) > (pos + 1)/2) return;

  number[pos] = 0;
  back (pos - 1, odds, evens);
  number[pos] = 1;
  if (pos % 2 == 0) {
    back (pos - 1, odds, evens + 1);
  }
  else {
    back (pos - 1, odds + 1, evens);
  }
}

int main() {

  int n;
  cin >> n;
  seen = 0;
  cin >> N;
  cin >> J;

  cout << "Case  #1:" << endl;

  number = vector <int> (N);
  number[N - 1] = number[0] = 1;

  back (N - 2, 0, 0);
}
