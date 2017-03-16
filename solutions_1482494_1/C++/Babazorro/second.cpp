using namespace std;

#include <assert.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <climits>
typedef vector<int> Vint;
typedef vector<string> Vstring;
typedef vector<int>::iterator VintIt;
typedef vector<string>::iterator VstringIt;

int Na[1000];
int Nb[1000];

long long doit(int N, vector<pair<int, int> > stars) {
  int pow = 0;
  int levels = 0;
  start:
  //look second star
  for (vector<pair<int, int> >::iterator it = stars.begin(); it < stars.end(); ++it) {
    if ((*it).second <= pow) {
      pow++;
      if ((*it).first != INT_MAX)
        pow++;
      levels++;
      stars.erase(it);
      goto start;
    }
  }

  //look first star
  int m = -1;
  vector<pair<int, int> >::iterator tt;
  for (vector<pair<int, int> >::iterator it = stars.begin(); it < stars.end(); ++it) {
    if ((*it).first <= pow && (*it).second > m) {
      tt  = it;
      m = (*it).second;
    }
  }
  if (m != -1) {
    pow++;
    levels++;
    (*tt).first = INT_MAX;
    goto start;
  }

  if (stars.size() == 0)
    return levels;
  return -1;
}

int main(int argc, char **argv) {
  int T;
  cin >> T >> ws;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N >> ws;
    vector<pair<int, int> > stars;
    for (int i = 0; i < N; ++i) {
      int a, b;
      cin >> a >> b >> ws;
      stars.push_back(make_pair(a, b));
    }
    long long res = doit(N, stars);
    if (res == -1)
      cout << "Case #" << t << ": " << "Too Bad" << endl;
    else
      cout << "Case #" << t << ": " << res << endl;
  }
}
