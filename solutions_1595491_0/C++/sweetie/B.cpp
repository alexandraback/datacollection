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

struct CountAbove {
  const unsigned int border;
  CountAbove(const unsigned int border) : border(border) { }
  bool operator()(const unsigned int value) const {
    return value >= border;
  }
};

int main(const unsigned int argc, const char * const * const argv) {
  if (argc != 2) {
    return 1;
  }
  const boost::filesystem::path path(argv[1]);
  boost::filesystem::ifstream ifs(path, std::ios::binary);
  const unsigned int count = getIntLine(ifs);
  for (unsigned int i = 0; i < count; i++) {
    const unsigned int n = getInt(ifs);
    const unsigned int s = getInt(ifs);
    const unsigned int p = getInt(ifs);
    std::vector<unsigned int> points(n);
    BOOST_FOREACH(unsigned int &point, points) {
      point = getInt(ifs);
    }
    //std::sort(points.begin(), points.end());
    const unsigned int aboveCount = std::count_if(points.begin(), points.end(), CountAbove(p + (std::max)(0, (int)(p) - 1) * 2));
    const unsigned int surprisingCount = std::count_if(points.begin(), points.end(), CountAbove(p + (std::max)(0, (int)(p) - 2) * 2)) - aboveCount;
    const unsigned int result = aboveCount + (std::min)(s, surprisingCount);
    std::cout << boost::format("Case #%d: %d\n") % (i + 1) % result;
  }
  return 0;
}
