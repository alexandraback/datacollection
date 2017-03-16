#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

struct noncopyable {
  noncopyable(const noncopyable&) = delete;
  noncopyable& operator=(const noncopyable&) = delete;
  noncopyable() {}
};

struct Files : noncopyable {
  std::fstream in;
  std::fstream out;

  static std::string name_to_out(const std::string& s) {
    if (s.substr(s.size()-3) == ".in") {
      return s.substr(0, s.size()-3)+".out";
    } else {
      return s+".out";
    }
  }

  Files(const std::string& name) : in(name.c_str(), std::ios_base::in),
    out(name_to_out(name).c_str(), std::ios_base::out) {
  }

  size_t get_numline() {
    size_t N;
    in >> N;
    std::string es;
    std::getline(in, es);
    if (!es.empty()) {
      assert(false);
    }
    return N;
  }

  template<class T> std::vector<T> get_vec(size_t n) {
    std::vector<T> v;
    v.reserve(n);
    while (n-- > 0) {
      T tmp;
      in >> tmp;
      v.push_back(std::move(tmp));
    }
    return v;
  }

  template<class T> T get() {
    T tmp;
    in >> tmp;
    return tmp;
  }
};

typedef unsigned int uint;

bool solve(uint x, uint r, uint c) {
  auto smin = min(r, c);
  auto smax = max(r, c);
  bool can; //can fill always
  if (x == 4 && smin == 2 && smax == 4) {
    return false;
  }
  if (x <= r*c && (r*c)%x == 0) {
    can = true;
    for (uint i = 1; i <= (x+1)/2; ++i) {
      assert(i <= x+1-i);
      if (i > smin || x+1-i > smax) {
	can = false;
	break;
      }
    }
  } else {
    can = false;
  }
  return can;
}

void test() {
  assert(true == solve(2, 2, 2));
  assert(false == solve(2, 1, 3));
  assert(false == solve(4, 4, 1));
  assert(true == solve(3, 2, 3));
  assert(false == solve(3, 1, 2));
  assert(true == solve(2, 3, 4));
  assert(false == solve(4, 1, 2));
  assert(true == solve(1, 2, 4));
  assert(false == solve(3, 2, 2));
  assert(true == solve(1, 1, 3));
  assert(true == solve(2, 2, 1));
  assert(false == solve(4, 2, 4));
  assert(true == solve(1, 1, 4));
  assert(false == solve(3, 2, 4));
  assert(true == solve(2, 4, 1));
  assert(true == solve(1, 3, 2));
  assert(true == solve(1, 1, 1));
  assert(true == solve(3, 4, 3));
  assert(false == solve(4, 1, 4));
  assert(false == solve(3, 3, 1));
  assert(true == solve(3, 3, 2));
  assert(false == solve(3, 1, 1));
  assert(false == solve(3, 4, 2));
  assert(false == solve(3, 1, 3));
  assert(true == solve(1, 4, 2));
  assert(true == solve(1, 4, 4));
  assert(true == solve(3, 3, 3));
  assert(true == solve(2, 3, 2));
  assert(true == solve(1, 3, 4));
  assert(true == solve(1, 1, 2));
  assert(false == solve(4, 3, 2));
  assert(true == solve(1, 2, 1));
  assert(false == solve(4, 1, 3));
  assert(false == solve(4, 2, 2));
  assert(true == solve(1, 3, 1));
  assert(true == solve(2, 4, 3));
  assert(false == solve(2, 1, 1));
  assert(false == solve(4, 1, 1));
  assert(true == solve(1, 2, 3));
  assert(false == solve(3, 1, 4));
  assert(true == solve(3, 3, 4));
  assert(false == solve(4, 3, 1));
  assert(false == solve(4, 4, 2));
  assert(false == solve(3, 4, 1));
  assert(true == solve(2, 1, 2));
  assert(false == solve(4, 3, 3));
  assert(true == solve(4, 4, 3));
  assert(true == solve(2, 2, 3));
  assert(false == solve(3, 2, 1));
  assert(true == solve(2, 4, 2));
  assert(false == solve(4, 2, 3));
  assert(true == solve(2, 1, 4));
  assert(true == solve(2, 2, 4));
  assert(true == solve(1, 2, 2));
  assert(false == solve(2, 3, 1));
  assert(false == solve(2, 3, 3));
  assert(true == solve(1, 4, 1));
  assert(true == solve(1, 4, 3));
  assert(false == solve(3, 4, 4));
  assert(true == solve(4, 4, 4));
  assert(true == solve(4, 3, 4));
  assert(true == solve(1, 3, 3));
  assert(true == solve(2, 4, 4));
  assert(false == solve(4, 2, 1));

  assert(false == solve(4, 2, 2));
  assert(false == solve(4, 2, 3));

  cout << "Test OK" << endl;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Use ./a.out <file>" << std::endl;
    test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;
  for (size_t t = 1; t <= T; ++t) {
    uint x, r, c;
    f.in >> x >> r >> c;
    bool can = solve(x, r, c);
    f.out << "Case #" << t << ": " << (can ? "GABRIEL" : "RICHARD") << endl;
  }
}
