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
//using namespace __gnu_cxx;

int main (int argc, char* argv[]) {

  ifstream in (argv[1]);
  ofstream out ("problem.out");
  string line;
  int nbTests;
  out.precision(12);

  in >> nbTests;
  getline(in, line);

  for (int test=0; test<nbTests; test++) {
    int n, s, p, x, tot;
    int bestscore_sur;
    int bestscore_notsur;
    int bestscore;
    in >> n >> s >> p;
    vector<int> v(n, -1);
    int sol = 0;
    
    for(int i = 0; i < n; i++)
      in >> v[i];

    for(int i = 0; i < n; i++) {
      tot = v[i];
      x = tot / 3;
      
      bestscore_sur = (tot%3 == 2) ? (x + 2) : (x + 1);
      bestscore_notsur = (tot%3 == 0) ? x : (x + 1);
      assert(tot%3 != 1 || x != 10);
      assert(tot%3 != 2 || x != 10);
     
      bestscore = bestscore_notsur;
      /* If this triplet CAN be surprising */
      if((tot >= 2) && (tot <= 28)) {
	/* If it would be a gain to count it as surprising */
	if(bestscore_notsur < p && bestscore_sur >= p) {
	  /* If there is enough surprising triplet remaining */
	  if(s > 0) {
	    s--;
	    bestscore = bestscore_sur;
	  }
	}
      }

      if(bestscore >= p)
	sol++;
    }    
    out << "Case #" << test+1 << ": " << sol << endl;
  }
}

