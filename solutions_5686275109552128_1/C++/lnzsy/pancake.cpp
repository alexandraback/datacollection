#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

#define REP(i, p, n) for (int i=p; i<n; ++i)
#define FOR(i, c) for (__typeof ((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define ULL unsigned long long


int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	//FILE *fout = fopen (argv[2], "w");
	if (fin==NULL) exit(1);

  int N;
  fscanf(fin, "%d", &N);
  vector<int> X(N, 10000);

  for (int i=0; i<N; ++i) {
    int D;
    fscanf(fin, "%d", &D);
    vector<int> p;

    for (int j=0; j<D; ++j) {
      int k;
      fscanf(fin, "%d", &k);
      p.push_back(k);
    }

    //
    sort(p.begin(), p.end());
    int best=10000;
    int last=10000;
    for (int j=1; j<=p[p.size()-1]; ++j) {
      int tmp=j;
      for (int k=p.size()-1; k>=0; --k) {
        if (p[k] == 1) break;
        tmp += (p[k]-1)/j;
      }
      /*
      if (tmp > last) {
        break;
      }
      */
      X[i] = min(X[i], tmp);
      last = tmp;
    }
  }

  for (int i=0; i<N; ++i) {
    cout << "Case #" << i+1 << ": " << X[i] << endl;
  }

	fclose(fin);
	//fclose(fout);
	return 0;
}






