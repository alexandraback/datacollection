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

std::string getLine(std::istream &is) {
    char line[4096];
    is.getline(line, _countof(line));
    return line;
}


int main(const unsigned int argc, const char * const * const argv) {
  if (argc != 2) {
    return 1;
  }

  const char hintIn[] =
    "ejp mysljylc kd kxveddknmc re jsicpdrysi"
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
    "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  const char hintOut[] =
    "our language is impossible to understand"
    "there are twenty six factorial possibilities"
    "so it is okay if you want to just give up";
  std::vector<char> map(256);
  for (unsigned int i = 0; i < _countof(hintIn); i++) {
    if (map[hintIn[i]] != '\0' && map[hintIn[i]] != hintOut[i]) {
      std::cout << boost::format("Error:%s => (%c:%c)\n") % hintIn[i] % map[hintIn[i]] % hintOut[i];
      return 1;
    }
    map[hintIn[i]] = hintOut[i];
  }
  map['q'] = 'z';
  map['z'] = 'q';

  const boost::filesystem::path path(argv[1]);
  boost::filesystem::ifstream ifs(path, std::ios::binary);
  const unsigned int count = getIntLine(ifs);
  for (unsigned int i = 0; i < count; i++) {
    std::string line = getLine(ifs);
    BOOST_FOREACH(char &c, line) {
      c = map[c];
    }
    std::cout << boost::format("Case #%d: %s\n") % (i + 1) % line;
  }
  return 0;
}
