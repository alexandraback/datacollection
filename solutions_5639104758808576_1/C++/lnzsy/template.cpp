#include <cstdio>
#include <cstdlib>
#include <climits>
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


int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen (argv[2], "w");
	if (fin==NULL || fout==NULL) exit(1);

  int num_cases=0;
  fscanf(fin, "%d", &num_cases);
  char c;
  vector<int> res;

  for (int i=0; i<num_cases; ++i) {
    int d=0;
    fscanf(fin, "%d", &d);
    fscanf(fin, "%c", &c);
    vector<int> num;
    for (int j=0; j<d+1; ++j) {
      fscanf(fin, "%c", &c);
      num.push_back(c-'0');
    }

    if (d == 0) {
      res.push_back(0);
      continue;
    }

    int num_people = 0;
    int acc = 0;
    for (int i=0; i<d+1; ++i) {
      if (i <= acc) {
        acc += num[i];
      } else {
        if (num[i] == 0) continue;
        num_people += i - acc;
        acc += i - acc;
        acc += num[i];
      }
    }
    res.push_back(num_people);
  }

  for (int i=0; i<num_cases; ++i) {
    cout << "Case #" << i+1 << ": " << res[i] << endl;
  }


	fclose(fin);
	fclose(fout);
	return 0;
}






