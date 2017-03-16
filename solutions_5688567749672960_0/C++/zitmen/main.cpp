#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef unsigned long long ull;

ull reverse(ull val) {
  ull retval = 0ULL;
  while (val > 0ULL) {
    retval = retval * 10ULL + val % 10ULL;
    val /= 10ULL;
  }
  return retval;
}

struct Node {
  ull val, count;
  Node(ull v, ull c) { val = v; count = c; }
};

void visit(set<ull> &visited, queue<Node> &q, ull val, ull count) {
  if (visited.find(val) != visited.end()) return;
  visited.insert(val);
  q.push(Node(val, count));
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    ull N;
    cin >> N;
    set<ull> visited;
    queue<Node> q;
    visit(visited, q, 1, 1);
    while (q.front().val != N) {
      ull val = q.front().val;
      ull count = q.front().count;
      q.pop();
      visit(visited, q, reverse(val), count + 1);
      visit(visited, q, val + 1, count + 1);
    }
    cout << "Case #" << t << ": " << q.front().count << endl;
  }
  return 0;
}