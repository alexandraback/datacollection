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
    string s;
    f.in >> s;
    assert(n+1 == s.size());
    size_t count = 0;
    size_t friends = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      size_t k = s[i]-'0';
      if (count < i && k > 0) {
	friends += i-count;
	count += i-count;
      }
      count += k;
    }
    f.out << "Case #" << t << ": " << friends << endl;
  }
}
