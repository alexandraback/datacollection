#include <cstdint>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

vector<uint64_t> calc(uint64_t k, uint64_t c, uint64_t s) {
  vector<uint64_t> res;
  uint64_t n = 0;
  uint64_t v = 0;
  for (size_t i = 0; i < k; ++i) {
    v = v*k+i;
    ++n;
    if (n == c) {
      res.push_back(v+1);
      if (res.size() > s) { //impossible
	res.clear();
	return res;
      }
      v = 0;
      n = 0;
    }
  }
  if (n > 0) {
    res.push_back(v+1);
    if (res.size() > s) { //impossible
      res.clear();
      return res;
    }
  }
  return res;
}

void test() {
  typedef vector<uint64_t> V;
  assert(V{2} == calc(2, 3, 2));
  assert(V{1} == calc(1, 1, 1));
  assert(V{} == calc(2, 1, 1));
  assert(V({1, 2}) == calc(2, 1, 2));
  assert(V({2, 3}) == calc(3, 2, 3));

  assert(V({2, 14, 5}) == calc(5, 2, 3));
  assert(V({}) == calc(5, 2, 2));
}

int main(int argc, char** argv) {
  if (argc == 2 && string(argv[1]) == "-test") {
    test();
    return 0;
  }
  size_t N;
  cin >> N;
  for (size_t i = 1; i <= N; ++i) {
    uint64_t k, c, s;
    cin >> k >> c >> s;
    vector<uint64_t> res = calc(k, c, s);
    cout << "Case #" << i << ":";
    if (!res.empty()) {
      for (uint64_t x : res) {
	cout << ' ' << x;
      }
    } else {
      cout << " IMPOSSIBLE";
    }
    cout << endl;
  }
}
