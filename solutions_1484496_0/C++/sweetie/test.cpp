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

int main(const unsigned int argc, const char * const * const argv) {
  if (argc != 2) {
    return 1;
  }
  const boost::filesystem::path path(argv[1]);
  boost::filesystem::ifstream ifs(path, std::ios::binary);
  const unsigned int count = getIntLine(ifs);
  for (unsigned int i = 0; i < count; i++) {
    const unsigned int N = getInt(ifs);
    std::vector<unsigned long long int> S(N);
    BOOST_FOREACH(unsigned long long int &s, S) {
      s = getInt(ifs);
    }
    std::sort(S.begin(), S.end());
    std::map<unsigned long long int, std::vector<unsigned long long int> > v;
    typedef std::pair<unsigned long long int, std::vector<unsigned long long int> > VPair;
    std::vector<unsigned long long int> result[2];
    BOOST_FOREACH(const unsigned long long int &s, S) {
      const std::map<unsigned long long int, std::vector<unsigned long long int> >::const_iterator it = v.find(s);
      if (it != v.end()) {
        result[0] = it->second;
        result[1].push_back(s);
        break;
      }
      std::map<unsigned long long int, std::vector<unsigned long long int> > temp;
      temp.insert(std::make_pair(s, std::vector<unsigned long long int>(1, s)));
      BOOST_FOREACH(VPair pair, v) {
        pair.first += s;
        pair.second.push_back(s);
        const std::map<unsigned long long int, std::vector<unsigned long long int> >::const_iterator it = v.find(pair.first);
        if (it != v.end()) {
          result[0] = it->second;
          result[1] = pair.second;
          break;
        }
        temp.insert(pair);
      }
      if (!result[0].empty()) {
        break;
      }
      BOOST_FOREACH(const VPair pair, temp) {
        v.insert(pair);
      }
    }

    std::cout << boost::format("Case #%d:\n") % (i + 1);
    if (result[0].empty()) {
      std::cout << "Impossible\n";
    } else {
      BOOST_FOREACH(const std::vector<unsigned long long int> &values, result) {
        for (unsigned int i = 0; i < values.size(); i++) {
          if (i != 0) {
            std::cout << " ";
          }
          std::cout << boost::format("%d") % values[i];
        }
        std::cout << "\n";
      }
    }
  }
  return 0;
}
