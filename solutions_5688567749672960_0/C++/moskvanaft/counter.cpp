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

void test() {
  assert(101 == reverse_num(101));
  assert(101 == reverse_num(1010));
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
  vector<size_t> nums = f.get_vec<size_t>(T);

  size_t max = *max_element(nums.begin(), nums.end());
  //cout << "max = " << max << endl;
  vector<size_t> v(max+1, inf);
  v[0] = 0;
  for (size_t i = 0; i < max; ++i) {
    size_t rev = reverse_num(i);
    if (rev > i && rev <= max) {
      v[rev] = min(v[rev], v[i]+1);
    }
    v[i+1] = min(v[i+1], v[i]+1);
      /*
      v[i] = min(v[i-1]+1, v[rev]);
    } else {
      v[i] = v[i-1]+1;
    }
      */
    //cout << i << ' ' << v[i] << endl;
  }
  //cout << max << ' ' << v[max] << endl;

  for (size_t i = 1; i <= nums.size(); ++i) {
    f.out << "Case #" << i << ": " << v[nums[i-1]] << endl;
  }
}
