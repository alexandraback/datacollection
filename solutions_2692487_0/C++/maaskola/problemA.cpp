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
#include <algorithm>

using namespace std;

size_t solve(size_t a, vector<size_t> &motes) {
  cerr << "a = " << a << endl;
  sort(begin(motes), end(motes));
  cerr << "motes = ";
  for(auto &x: motes)
    cerr << " " << x;
  cerr << endl;

  // consume all that are less
  auto x = begin(motes);
  while(x != end(motes) and *x < a)
    a += *(x++);

  if(x == end(motes))
    return(0); // we could successfully consume all

  cerr << "remaining =";
  for(auto y = x; y != end(motes); y++)
    cerr << " " << *y;
  cerr << endl;

  size_t max_edits = distance(x, end(motes));
  if(a == 1) // we can't consume any and must discard all
    return(max_edits); 

  size_t n_steps = 0;
  vector<size_t> v(max_edits+1); // the costs incurred when accepting everything right up to BEFORE this position
  vector<size_t> w(max_edits+1); // the costs incurred when rejecting everything right FROM this position
  for(size_t i = 0; i < max_edits + 1; i++)
    w[i] = max_edits - i;
  v[0] = 0;
  for(size_t i = 0; i < max_edits; i++) {
    while(a <= *x) {
      a += (a-1);
      n_steps++;
    }
    a += *x;
    x++;
    cerr << "i = " << i << " a = " << a << " nsteps = " << n_steps << endl;
    v[i+1] = n_steps;
  }
  vector<size_t> u(max_edits+1);
  for(size_t i = 0; i <= max_edits; i++) {
    u[i] = v[i] + w[i];
  }

  cerr << "v =";
  for(auto &y: v)
    cerr << " " << y;
  cerr << endl;
 
  cerr << "w =";
  for(auto &y: w)
    cerr << " " << y;
  cerr << endl;

  cerr << "u =";
  for(auto &y: u)
    cerr << " " << y;
  cerr << endl;
 

  size_t res = *min_element(begin(u), end(u));

  return(res);
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

  size_t t;
  ifs >> t;

  cerr << "t = " << t << endl;

  for(size_t i = 0; i < t; i++) {
    cerr << "i = " << i << endl;

    size_t a, n;
    ifs >> a >> n;

    vector<size_t> motes(n);
    for(size_t j = 0; j < n; j++)
      ifs >> motes[j];

    auto result = solve(a, motes);

    cout << "Case #" << (i+1) << ": " << result << endl;
  }

  return EXIT_SUCCESS;
}

