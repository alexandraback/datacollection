#include <fstream>
#include <queue>
#include <functional>

using std::istream; using std::ostream;
using std::ifstream; using std::ofstream;
using std::priority_queue;

void Test(int caseNum, istream &is, ostream &os) {
  int diners;
  is >> diners;
  priority_queue<int> pancakes, tmp;
  for (int i = 0; i < diners; i++) {
    int p;
    is >> p;
    pancakes.push(p);
  }
  tmp = pancakes;
  int min_time = tmp.top();
  for (int i = 0; ; i++) {
    min_time = std::min(min_time, i + tmp.top());
    if (tmp.top() > 3) {
      int p = tmp.top();
      int n = (p + 2) / 3;
      n /= 2;
      tmp.pop();
      int p0 = 3 * n, p1 = p - p0;
      tmp.push(p0);
      tmp.push(p1);
    } else {
      break;
    }
  }
  tmp = pancakes;
  for (int i = 0;; i++) {
    min_time = std::min(min_time, i + tmp.top());
    if (tmp.top() > 3) {
      int p = tmp.top();
      tmp.pop();
      int p0 = p / 2, p1 = p - p0;
      tmp.push(p0);
      tmp.push(p1);
    } else {
      break;
    }
  }
  os << "Case #" << caseNum << ": " << min_time << '\n';
}

int main() {
  ifstream is("B-large.in");
  ofstream os("output.txt");
  int T;
  is >> T;
  for (int i = 1; i <= T; i++)
    Test(i, is, os);
  is.close();
  os.close();
  return 0;
}