#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <assert.h>
#include <bitset>
#include <functional>
#include <utility>
#include <iomanip>
#include <cctype>

using namespace std;

typedef unsigned long long int ll;

int main (int argc, char* argv[]) {

  ifstream in (argv[1]);
  ofstream out ("problem.out");
  string line;
  int nbTests;
  out.precision(12);

  in >> nbTests;
  getline(in, line);

  for (int test=0; test<nbTests; test++) {

    long int a, b;
    in >> a >> b;
    long int acp = a;
    int nb = 0;
    long int t = 1;
    while(acp != 0) {
      acp /= 10;
      t *= 10;
      nb++;
    }
    t /= 10;

    vector<long int> v(nb - 1, -1);
    long int ten1, ten2;
    long int cpt = 0;

    for(long int m = b; m >= a; m--) {
      ten1 = 10;
      ten2 = t;
      for(int i = 1; i < nb; i++) {
	v[i - 1] = (m % ten1)*ten2 + (m / ten1);
	ten1 *= 10;
	ten2 /= 10;
      }
      sort(v.begin(), v.end());
      for(int i = 0; i < nb - 1; i++) {
	if((v[i] >= a) && (v[i] < m) && ((i == nb - 2) || v[i] != v[i + 1])) {
	  cpt++;
	}
      }
    }
    out << "Case #" << test+1 << ": " << cpt << endl;
    
  }
}

