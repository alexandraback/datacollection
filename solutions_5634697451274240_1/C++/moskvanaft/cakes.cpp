#include <string>
#include <iostream>
#include <cassert>

using namespace std;

size_t calc(string& s) {
  size_t n = 0;
  s.push_back('+');
  for (size_t i = 1; i < s.size(); ++i) {
    if (s[i] != s[i-1]) {
      ++n;
    }
  }
  return n;
}

size_t calc(const char* ptr) {
  string s(ptr);
  return calc(s);
}

void test() {
  assert(0 == calc("+"));
  assert(1 == calc("-"));
  assert(1 == calc("--"));
  assert(0 == calc("++"));
  assert(1 == calc("-+"));
  assert(2 == calc("+-"));

  assert(0 == calc("+++"));
  assert(3 == calc("--+-"));
}

int main(int argc, char** argv) {
  if (argc == 2 && string(argv[1]) == "-test") {
    test();
    return 0;
  }
  size_t N;
  cin >> N;
  for (size_t i = 1; i <= N; ++i) {
    string s;
    cin >> s;
    size_t res = calc(s);
    cout << "Case #" << i << ": " << res << endl;
  }
}
