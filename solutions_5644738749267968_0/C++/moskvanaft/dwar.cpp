#include <vector>
#include <initializer_list>
#include <utility>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <iostream>

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

std::pair<int, int> solve(std::vector<double>& naomi, std::vector<double>& ken) {
  std::sort(naomi.begin(), naomi.end());
  std::sort(ken.begin(), ken.end());
  auto ken_max = ken.rbegin();
  auto ken_min = ken.begin();
  int war = 0;
  for (auto it = naomi.rbegin(); it != naomi.rend(); ++it) {
    if (*it > *ken_max) {
      ++ken_min;
      ++war;
    } else {
      assert(*it < *ken_max);
      ++ken_max;
    }
  }

  int dwar = 0;
  auto in = naomi.begin();
  auto ik = ken.begin();
  while (in != naomi.end()) {
    if (*ik < *in) {
      ++dwar;
      ++ik;
    }
    ++in;
  }

  return std::make_pair(dwar, war);
}

std::pair<int, int> solve_test(const std::initializer_list<double>& naomi, const std::initializer_list<double>& ken) {
  std::vector<double> n(naomi.begin(), naomi.end());
  std::vector<double> k(ken.begin(), ken.end());
  return solve(n, k);
}

void test() {
  assert(std::make_pair(0, 0) == solve_test({0.5}, {0.6}));
  assert(std::make_pair(1, 0) == solve_test({0.2, 0.7}, {0.3, 0.8}));
  assert(std::make_pair(2, 1) == solve_test({0.1, 0.5, 0.9}, {0.3, 0.4, 0.6}));
  assert(std::make_pair(8, 4) == solve_test({0.186, 0.389, 0.907, 0.832, 0.959, 0.557, 0.300, 0.992, 0.899},
				       {0.916, 0.728, 0.271, 0.520, 0.700, 0.521, 0.215, 0.341, 0.458}));
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Use ./a.out <file>" << std::endl;
    //test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t n;
    f.in >> n;
    auto naomi = f.get_vec<double>(n);
    auto ken = f.get_vec<double>(n);
    auto res = solve(naomi, ken);
    f.out << "Case #" << t << ": " << res.first << ' ' << res.second << std::endl;
  }
  return 0;
}


