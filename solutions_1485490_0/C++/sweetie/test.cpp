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

unsigned long long int getInt(std::istream &is) {
  unsigned long long int result;
  is >> result;
  return result;
}

std::string getLine(std::istream &is) {
  char line[4096];
  is.getline(line, _countof(line));
  return line;
}

struct assembly {
  unsigned long long int count;
  unsigned int type;
};

std::vector<assembly> assembles[2];

unsigned long long int GetMax(const unsigned int firstIndex, const unsigned int secondIndex) {
  if (firstIndex == assembles[0].size() || secondIndex == assembles[1].size()) {
    return 0;
  }
  const unsigned int firstType = assembles[0][firstIndex].type;
  const unsigned int secondType = assembles[1][secondIndex].type;
  if (firstType == secondType) {
    const unsigned long long int firstCount = assembles[0][firstIndex].count;
    const unsigned long long int secondCount = assembles[1][secondIndex].count;
    const unsigned long long int count = std::min(firstCount, secondCount);
    assembles[0][firstIndex].count -= count;
    assembles[1][secondIndex].count -= count;
    unsigned long long int result = count;
    if (firstCount == secondCount) {
      result += GetMax(firstIndex + 1, secondIndex + 1);
    } else if (firstCount > secondCount) {
      result += GetMax(firstIndex, secondIndex + 1);
    } else {
      result += GetMax(firstIndex + 1, secondIndex);
    }
    assembles[0][firstIndex].count += count;
    assembles[1][secondIndex].count += count;
    return result;
  }
  unsigned long long int result = 0;
  for (unsigned int i = secondIndex; i < assembles[1].size(); i++) {
    if (firstType == assembles[1][i].type) {
      result = std::max(result, GetMax(firstIndex, i));
      break;
    }
  }
  for (unsigned int i = firstIndex; i < assembles[0].size(); i++) {
    if (secondType == assembles[0][i].type) {
      result = std::max(result, GetMax(i, secondIndex));
      break;
    }
  }
  return std::max(result, GetMax(firstIndex + 1, secondIndex + 1));
}

int main(const unsigned int argc, const char * const * const argv) {
  if (argc != 2) {
    return 1;
  }
  const boost::filesystem::path path(argv[1]);
  boost::filesystem::ifstream ifs(path, std::ios::binary);
  const unsigned int count = getIntLine(ifs);
  for (unsigned int i = 0; i < count; i++) {
    assembles[0].resize(getInt(ifs));
    assembles[1].resize(getInt(ifs));
    BOOST_FOREACH(std::vector<assembly> &assemblyItem, assembles) {
      BOOST_FOREACH(assembly &item, assemblyItem) {
        item.count = getInt(ifs);
        item.type = getInt(ifs);
      }
    }
    std::cout << boost::format("Case #%d: %d\n") % (i + 1) % GetMax(0, 0);
  }
  return 0;
}
