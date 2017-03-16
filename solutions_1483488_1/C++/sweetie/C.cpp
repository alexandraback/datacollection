#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#include <math.h>
#include <limits.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <numeric>
#include <functional>
#include <algorithm>
#include <utility>

// boost http://www.boost.org/
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>

#ifndef _countof
#define _countof(a) (sizeof(a) / sizeof(*a))
#endif

using namespace std;

unsigned int getIntLine(std::istream &is) {
  char line[4096];
  is.getline(line, _countof(line));
  return std::atoi(line);
}

unsigned int getInt(std::istream &is) {
  unsigned int result;
  is >> result;
  return result;
}

std::string getLine(std::istream &is) {
  char line[4096];
  is.getline(line, _countof(line));
  return line;
}

std::vector<std::pair<unsigned int, unsigned int> > ans;

template<int A, int B>
inline unsigned int ImplImplImpl(const unsigned int a, const unsigned int b) {
  const unsigned int value = a / A + (a % A) * B;
  if (a < value && value <= b) {
    ans.push_back(std::make_pair(a, value));
    return 1;
  }
  return 0;
}

template<int T>
inline unsigned int ImplImpl2(const unsigned int a, const unsigned int b) {
  return ImplImplImpl<10, T>(a, b);
}

template<int T>
inline unsigned int ImplImpl3(const unsigned int a, const unsigned int b) {
  return ImplImplImpl<100, T>(a, b);
}

template<int T>
inline unsigned int ImplImpl4(const unsigned int a, const unsigned int b) {
  return ImplImplImpl<1000, T>(a, b);
}

template<int T>
inline unsigned int ImplImpl5(const unsigned int a, const unsigned int b) {
  return ImplImplImpl<10000, T>(a, b);
}

template<int T>
inline unsigned int ImplImpl6(const unsigned int a, const unsigned int b) {
  return ImplImplImpl<100000, T>(a, b);
}

template<int T>
inline unsigned int ImplImpl7(const unsigned int a, const unsigned int b) {
  return ImplImplImpl<1000000, T>(a, b);
}

inline unsigned int Impl2(const unsigned int a, const unsigned int b) {
  return ImplImpl2<10>(a, b);
}

inline unsigned int Impl3(const unsigned int a, const unsigned int b) {
  return ImplImpl2<100>(a, b) + ImplImpl3<10>(a, b);
}

inline unsigned int Impl4(const unsigned int a, const unsigned int b) {
  return ImplImpl2<1000>(a, b) + ImplImpl3<100>(a, b) + ImplImpl4<10>(a, b);
}

inline unsigned int Impl5(const unsigned int a, const unsigned int b) {
  return ImplImpl2<10000>(a, b) + ImplImpl3<1000>(a, b) + ImplImpl4<100>(a, b) + ImplImpl5<10>(a, b);
}

inline unsigned int Impl6(const unsigned int a, const unsigned int b) {
  return ImplImpl2<100000>(a, b) + ImplImpl3<10000>(a, b) + ImplImpl4<1000>(a, b) + ImplImpl5<100>(a, b) + ImplImpl6<10>(a, b);
}

inline unsigned int Impl7(const unsigned int a, const unsigned int b) {
  return ImplImpl2<1000000>(a, b) + ImplImpl3<100000>(a, b) + ImplImpl4<10000>(a, b) + ImplImpl5<1000>(a, b) + ImplImpl6<100>(a, b) + ImplImpl7<10>(a, b);
}

int main(const unsigned int argc, const char * const * const argv) {
  if (argc != 2) {
    return 1;
  }
  const boost::filesystem::path path(argv[1]);
  boost::filesystem::ifstream ifs(path, std::ios::binary);
  const unsigned int count = getIntLine(ifs);
  for (unsigned int i = 0; i < count; i++) {
    const unsigned int a = getInt(ifs);
    const unsigned int b = getInt(ifs);
    unsigned int result = 0;
    ans.clear();
    if (a < 10) {
      result = 0;
    } else if(a < 100) {
      for(unsigned int l = a; l < b; l++) {
        result += Impl2(l, b);
      }
    } else if(a < 1000) {
      for(unsigned int l = a; l < b; l++) {
        result += Impl3(l, b);
      }
    } else if(a < 10000) {
      for(unsigned int l = a; l < b; l++) {
        result += Impl4(l, b);
      }
    } else if(a < 100000) {
      for(unsigned int l = a; l < b; l++) {
        result += Impl5(l, b);
      }
    } else if(a < 1000000) {
      for(unsigned int l = a; l < b; l++) {
        result += Impl6(l, b);
      }
    } else {
      for(unsigned int l = a; l < b; l++) {
        result += Impl7(l, b);
      }
    }
    std::sort(ans.begin(), ans.end());
    std::vector<std::pair<unsigned int, unsigned int> >::iterator it = std::unique(ans.begin(), ans.end());
    ans.erase(it, ans.end());
    result = ans.size();
    std::cout << boost::format("Case #%d: %d\n") % (i + 1) % result;
  }
  return 0;
}
