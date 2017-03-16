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

int main (int argc, char* argv[]) {

  ifstream in (argv[1]);
  ofstream out ("problem.out");
  string line;
  int nbTests;
  out.precision(12);
  char tab[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 
		  'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
  int i, n;
  in >> nbTests;
  getline(in, line);
  
  for (int test=0; test<nbTests; test++) {
    getline(in, line);
    n = line.size();
    out << "Case #" << test+1 << ": ";
    for(i = 0; i < n; i++) {
      if(line[i] == ' ')
	out << ' ';
      else {
	if((int)line[i] < (int)'a' || (int)line[i] > 'z') {
	  fprintf(stderr, "error reading %c\n", line[i]);
	  exit(1);
	}
	out << tab[(int)line[i] - (int)'a'];
      }
    }
    out << endl;
  }
}

