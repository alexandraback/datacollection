/*
 * =====================================================================================
 *
 *       Filename:  problemA.cpp
 *
 *    Description:  Google Code Jam 2013 - Round 1B - Problem A
 *
 *        Version:  1.0
 *        Created:  27.04.2013 01:45:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jonas Maaskola (jonas.maaskola@gmail.com)
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<size_t> find_conseq_cons(size_t w, const string &str) {
  set<size_t> s;
  size_t n = str.size();
  for(size_t i = 0; i < n-w+1; i++) {
    size_t pos = str.find_first_of("aeiou",i);
    if(pos == string::npos or pos - i >= w)
      s.insert(i);
  }
  cerr << "Positions:" << endl;
  for(auto &x: s)
    cerr << " " << x << " " << str.substr(x) << endl;
  return(s);
}

size_t solve(const string &w, size_t l) {
  std::cerr << "w = '" << w << "' l = " << l << endl;
  set<size_t> occ = find_conseq_cons(l, w);
  size_t n = w.size();
  size_t count = 0;
  for(size_t i = 0; i < n; i++) {
    auto next_hit = occ.lower_bound(i);
    if(next_hit == end(occ))
      break;
    size_t first_full_end = *next_hit + l;
    size_t n_suffix = n - first_full_end + 1;
    cerr << "i = " << i << " first_full_end = " << first_full_end << " n_suffix = " << n_suffix << endl;
    count += n_suffix;
  }
  return(count);
}

int main(int argc, const char **argv)
{
  if(argc > 2) {
    cout << "Please provide the path or stream to standard input." << endl;
    exit(-1);
  }

  string path = "/dev/stdin";
  if(argc == 2)
    path = argv[1];
  ifstream ifs(path.c_str());

  string line;
  getline(ifs,line);
  size_t t = atoi(line.c_str());

  cerr << "t = " << t << endl;

  for(size_t i = 0; i < t; i++) {
    cerr << "i = " << i << endl;

    getline(ifs, line);
    size_t pos = line.find(" ");
    size_t l = atoi(line.substr(pos).c_str());
    string w = line.substr(0,pos);

    auto result = solve(w, l);

    cout << "Case #" << (i+1) << ": " << result << endl;
  }

  return EXIT_SUCCESS;
}

