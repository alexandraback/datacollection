#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <limits>
#include <algorithm>
#include <map>

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

constexpr size_t inf = std::numeric_limits<size_t>::max();

inline size_t reverse_num(size_t n) {
  size_t res = 0;
  while (n%10 == 0 && n > 0) {
    n /= 10;
  }
  while (n > 0) {
    res = 10*res+n%10;
    n /= 10;
  }
  return res;
}

inline size_t order_num(size_t n) {
  size_t res = 1;
  while (n > 10) {
    res = 10*res;
    n /= 10;
  }
  res *= n;
  return res;
}

size_t solve(size_t r, size_t c, size_t w) {
  return (r-1)*c/w + c/w+(c%w ? 1 : 0) + (w-1);
}

void test() {
  cout << "Test OK" << endl;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    //cout << inf << endl;
    std::cerr << "Use ./a.out <file>" << std::endl;
    test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;

  for (size_t t = 1; t <= T; ++t) {
    size_t r, c, w;
    f.in >> r >> c >> w;
    auto min = solve(r, c, w);
    f.out << "Case #" << t << ": " << min << endl;
  }
}
