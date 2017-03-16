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
		unsigned int A, B, K;
		fscanf (fin, "%u%u%u", &A, &B, &K);

//		if (A<B) swap(A,B);
		unsigned long long ans=0;
		for (unsigned int j=0; j<A; ++j)
			for (unsigned int k=0; k<B; ++k) {
				unsigned int kk = j&k;
//				cout << kk << endl;
				if (kk<K) {
//					cout << j << " " << k << endl;
					++ans;
				}
			}
		fprintf (fout, "Case #%d: %llu\n", i+1, ans);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}






