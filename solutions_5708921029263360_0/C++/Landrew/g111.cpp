#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <string>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin ("INP111.txt");


int main() {

  int TT;
  fin >> TT;

  for (int tt=0;tt<TT; tt++)
  {
    int j, p, s, k;
	fin >> j >> p >> s >> k;

    fout << "Case #" << tt+1 << ": " << j*p*min(s,k) <<  endl;
  }

   return 0;
}
