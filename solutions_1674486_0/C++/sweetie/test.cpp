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

std::vector<std::vector<unsigned int> > classList;
std::vector<unsigned int> memo[1000];


bool Check(const unsigned int i, std::vector<unsigned int> &result = std::vector<unsigned int>()) {
  if (!memo[i].empty()) {
    result = memo[i];
    return false;
  }
  memo[i].push_back(i);
  BOOST_FOREACH(unsigned int classIndex, classList[i]) {
    std::vector<unsigned int> temp;
    if (Check(classIndex, temp)) {
      return true;
    }
    {
      std::sort(temp.begin(), temp.end());
      const std::vector<unsigned int>::iterator it = std::unique(temp.begin(), temp.end());
      temp.erase(it, temp.end());
    }

    {
      result.insert(result.begin(), temp.begin(), temp.end());
      std::sort(result.begin(), result.end());
      const std::vector<unsigned int>::iterator it = std::unique(result.begin(), result.end());
      if (it != result.end()) {
        return true;
      }
    }
  }
  result.push_back(i);
  memo[i] = result;
  return false;
}

int main(const unsigned int argc, const char * const * const argv) {
  if (argc != 2) {
    return 1;
  }
  const boost::filesystem::path path(argv[1]);
  boost::filesystem::ifstream ifs(path, std::ios::binary);
  const unsigned int count = getIntLine(ifs);
  for (unsigned int i = 0; i < count; i++) {
    BOOST_FOREACH(std::vector<unsigned int> &memoItem, memo) {
      memoItem.clear();
    }
    const unsigned int classCount = getInt(ifs);
    classList.resize(classCount);
    BOOST_FOREACH(std::vector<unsigned int> &classItem, classList) {
      classItem.clear();
      const unsigned int extendCount = getInt(ifs);
      for(unsigned int j = 0; j < extendCount; j++) {
        classItem.push_back(getInt(ifs) - 1);
      }
    }
    bool result = false;
    for (unsigned int j = 0; j < classList.size(); j++) {
      if (classList[j].size() < 2) {
        continue;
      }
      if (Check(j)) {
        result = true;
        break;
      }
    }
    std::cout << boost::format("Case #%d: %s\n") % (i + 1) % (result ? "Yes" : "No");
  }
  return 0;
}
