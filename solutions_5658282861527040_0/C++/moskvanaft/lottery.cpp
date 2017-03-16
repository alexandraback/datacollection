#include <string>
#include <cstddef>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <cassert>

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

uint64_t solve(uint64_t a, uint64_t b, uint64_t k) {
  size_t count = 0;
  for (auto i = k; i < a; ++i) {
    for (auto j = k; j < b; ++j) {
      if ((i & j) < k) {
	++count;
      }
    }
  }
  return std::min(k, b)*a + std::min(a, k)*b - std::min(k, a)*std::min(k, b) + count;
}

void test() {
  assert(10 == solve(3, 4, 2));
  assert(16 == solve(4, 5, 2));
  assert(52 == solve(7, 8, 5));
  assert(2411 == solve(45, 56, 35));
  /*
  size_t res = solve(103, 143, 88);
  std::cout << res << std::endl;
  assert(14337 == res);
  */
  assert(14377 == solve(103, 143, 88));
  assert(384*271 == solve(384, 271, 975));
}

int main(int argc, char** argv) {
  if (argc < 2) {
    //std::cerr << "Use ./a.out <file>" << std::endl;
    test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;
  for (size_t t = 1; t <= T; ++t) {
    int a, b, k;
    f.in >> a >> b >> k;
    auto res = solve(a, b, k);
    f.out << "Case #" << t << ": " << res << std::endl;
  }
}
