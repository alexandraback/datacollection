#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <limits>

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

inline double solve(double C, double F, double X) {
  double min = X/2;
  double buy_spent = 0;
  size_t buyed = 0;
  while (1) {
    buy_spent += C/(2+F*buyed);
    ++buyed;
    double new_cost = buy_spent + X/(2+F*buyed);
    if (new_cost < min) {
      min = new_cost;
    } else {
      return min;
    }
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Use ./a.out <file>" << std::cin;
    return 1;
  }
  Files f(argv[1]);
  size_t N;
  f.in >> N;
  for (size_t n = 1; n <= N; ++n) {
    double C, F, X;
    f.in >> C >> F >> X;
    auto res = solve(C, F, X);
    f.out << "Case #" << n << ": " << std::setprecision(std::numeric_limits<double>::digits10) << res << std::endl;
  }
  return 0;
}
