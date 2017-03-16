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
		double C, F, X;
		fscanf (fin, "%lf%lf%lf", &C, &F, &X);
//		cout << "fawfewafew   " << C << " " << F << " " << X << endl;
		double curr=0.0;
		vector<double> total_time;
		while (1) {
			double t = (curr == 0.0) ? 0.0 : C/(2.0+(curr-1.0)*F);
			double total;
			if (curr == 0.0) {
				total = X/2.0;
			} else {
				total = total_time.back() - X/(2.0+F*(curr-1.0)) + t + X/(2.0+F*curr);
			}
	//		cout << t<< " " <<  total << endl;

			if (total_time.size() == 0 || total<total_time.back()) {
				total_time.push_back (total);
			} else {
//				cout << curr << " " << total << " " << total_time.back() << endl;
				break;
			}
			curr+=1.0;
		}
		fprintf (fout, "Case #%d: %lf\n", i+1, total_time.back());
	}

	return 0;
}






