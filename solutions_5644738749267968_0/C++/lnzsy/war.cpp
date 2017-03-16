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


int main (int argc, char **argv)
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout = fopen (argv[2], "w");
	if (fin==NULL || fout==NULL) exit(1);

	int num_cases;
	fscanf (fin, "%d", &num_cases);

	REP (i, 0, num_cases) {
		int N;
		fscanf (fin, "%d", &N);
		vector<double> naomi(N, 0.0);
		vector<double> ken(N, 0.0);
		REP (j, 0, N) { double tmp; fscanf (fin, "%lf", &tmp); naomi[j]=tmp; }
		REP (j, 0, N) { double tmp; fscanf (fin, "%lf", &tmp); ken[j]=tmp; }

		sort (naomi.begin(), naomi.end());
		sort (ken.begin(), ken.end());
		vector<int> n_flag(N, 0);
		vector<int> k_flag(N, 0);
		int count=0;
		REP (j, 0, N) {		// ken
			REP (k, 0, N) {		// naomi
				if (n_flag[k]==0 && naomi[k]>ken[j]) {
					n_flag[k] = 1;
					++count;
					break;
				}
			}
		}
		vector<int> n_flag2(N, 0);
		vector<int> k_flag2(N, 0);

		int count2=0;
		REP (j, 0, N) {
			REP (k, 0, N) {
				if (k_flag2[k]==0 && ken[k]>naomi[j]) {
					k_flag2[k]=1;
					++count2;
					break;
				}
			}
		}

		fprintf (fout, "Case #%d: %d %d\n"	, i+1, count, N-count2);
	}


	return 0;
}






