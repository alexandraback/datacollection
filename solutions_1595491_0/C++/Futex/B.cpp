#include <iostream>
#include <vector>
using namespace std;

int abs(int a) {
  if (a < 0) {
    return -a;
  } else {
    return a;
  }
}

int main() {
  int cases = 0;
  cin >> cases;
  for (int c = 0; c < cases; ++c) {
    int num;
    int surp;
    int atleast;
    cin >> num >> surp >> atleast;
    vector<int> points(num);
    for (int idx = 0; idx < num; ++idx) {
      cin >> points[idx];
    }
    cout << "Case #" << (c + 1) << ": ";

    int surpseen = 0;
    int meet = 0;
    for (int idx = 0; idx < points.size(); ++idx) {
      bool nonsurp = false;
      bool issurp = false;

      for (int s1 = 0; s1 <= 10; ++s1) {
        for (int s2 = 0; s2 <= 10; ++s2) {
          for (int s3 = 0; s3 <= 10; ++s3) {
            if (s1 + s2 + s3 != points[idx]) {
              continue;
            }
            if (abs(s1 - s2) >= 3 ||
                abs(s1 - s3) >= 3 ||
                abs(s2 - s3) >= 3) {
              continue;
            }
            if (s1 < atleast &&
                s2 < atleast &&
                s3 < atleast) {
              continue;
            }
            issurp = true;
            if (abs(s1 - s2) <= 1 &&
                abs(s1 - s3) <= 1 &&
                abs(s2 - s3) <= 1) {
              nonsurp = true;
            }
          }
        }
      }

      if (nonsurp) {
        ++meet;
      } else if (issurp && surpseen < surp) {
        ++surpseen;
        ++meet;
      }
    }

    cout << meet << endl;
  }

  return 0;
}
